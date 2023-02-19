#include <functional>

struct IThreadHandler {
    virtual bool WorkReady() = 0;
    virtual bool Stopping() = 0;
    virtual std::function<void()>* GetWork() = 0;
};