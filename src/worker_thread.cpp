#include "worker_thread.h"
WorkerThread::WorkerThread(IThreadHandler* handler, std::mutex * mutex, std::condition_variable * cv) : mHandler(handler), mMutex(mutex), mCV(cv) {}

void WorkerThread::Run()
{
    while (!mHandler->Stopping())
    {
        std::unique_lock lock(*mMutex);
        mCV->wait(lock, [handler=mHandler](){return handler->WorkReady();});
        std::function<void()>* work = mHandler->GetWork();
        lock.unlock();
        (*work)();
    }
}
