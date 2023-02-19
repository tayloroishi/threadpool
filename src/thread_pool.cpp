#include "thread_pool.h"

using namespace std::chrono_literals;

bool ThreadPool::WorkReady()
{
    return !mQueue.empty();
}

bool ThreadPool::Stopping()
{
    return mIsStopping;
}

std::function<void()>* ThreadPool::GetWork()
{
    auto* job = mQueue.back();
    mQueue.pop();
    return job;
}

ThreadPool::ThreadPool(int numOfThreads)
{
    for (auto i = 0; i < numOfThreads; i++)
    {
        mWorkerThreads.emplace_back(this, &mMutex, &mCV);
    }

    for (auto& worker : mWorkerThreads)
    {
        mThreads.emplace_back([&worker](){worker.Run();});
    }
}

void ThreadPool::QueueJob(std::function<void()> * job)
{
    std::unique_lock lock(mMutex);
    mQueue.push(job);
    lock.unlock();
    mCV.notify_one();
}