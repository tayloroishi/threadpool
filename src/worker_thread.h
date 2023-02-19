#include <thread>

class WorkerThread {
public:
    void operator()();
    void SetWork(std::function<void()>*);
    bool Ready();

private:
    std::mutex mMutex;
    bool mReady = true;
    std::condition_variable mCV;
    std::function<void()>* mWork = nullptr;
};
