#include "worker_thread.h"

#include <thread>
#include <vector>
#include <queue>


class ThreadPool : public IThreadHandler {
public:
    explicit ThreadPool(int numOfThreads);
    void QueueJob(std::function<void()> * job);

    //IThreadHandler
    bool WorkReady() override;
    bool Stopping() override;
    std::function<void()>* GetWork() override;

private:
    std::vector<WorkerThread> mWorkerThreads;
    std::vector<std::thread> mThreads;
    std::queue<std::function<void()>*> mQueue;
    std::mutex mMutex;
    std::condition_variable mCV;
    bool mIsStopping = false;
};


