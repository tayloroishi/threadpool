#include "worker_thread.h"

#include <thread>
#include <vector>
#include <queue>


class ThreadPool {
public:
    explicit ThreadPool(int numOfThreads);
    void QueueJob(std::function<void()> * job);


private:
    std::vector<WorkerThread> mWorkerThreads;
    std::vector<std::thread> mThreads;
    std::queue<std::function<void()>*> mQueue;
};


