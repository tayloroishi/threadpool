#include "interfaces.h"
#include <thread>

class WorkerThread {
public:
    WorkerThread(IThreadHandler*, std::mutex*, std::condition_variable*);
    void Run();

private:
    IThreadHandler* mHandler;
    std::mutex* mMutex;
    std::condition_variable* mCV;
};


