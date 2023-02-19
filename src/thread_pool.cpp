#include "thread_pool.h"

ThreadPool::ThreadPool(int numOfThreads) : mWorkerThreads(numOfThreads)
{
    for (auto& worker : mWorkerThreads)
    {
        mThreads.emplace_back([&worker](){worker();});
    }
}

void ThreadPool::QueueJob(std::function<void()> * job)
{
    for (auto& worker : mWorkerThreads)
    {
        if (worker.Ready())
        {
            worker.SetWork(job);
            return;
        }
    }
    mQueue.push(job);
}