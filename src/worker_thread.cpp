#include "worker_thread.h"

void WorkerThread::operator()()
{
    std::unique_lock lock(mMutex);
    try {
        if (mWork)
        {
            (*mWork)();
        }
    }
    catch (const std::exception&)
    {}

    mReady = true;
    mCV.wait(lock);
}

void WorkerThread::SetWork(std::function<void()> * const work) {
    mReady = false;
    mWork = work;
    mCV.notify_one();
}

bool WorkerThread::Ready() { return mReady; }
