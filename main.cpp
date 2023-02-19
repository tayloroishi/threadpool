#include "src/thread_pool.h"
#include <iostream>

void testThread1()
{
    std::cout << "Hello, this is thread 1" << std::endl;
}

void testThread2()
{
    std::cout << "Hello, this is thread 2" << std::endl;
}

int main() {
    auto tp = ThreadPool(3);
    tp.QueueJob(reinterpret_cast<std::function<void(void)> *>(testThread1));
    tp.QueueJob(reinterpret_cast<std::function<void(void)> *>(testThread2));

    while (true)
    {

    }

    return 0;
}
