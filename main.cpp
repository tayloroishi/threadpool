#include "src/thread_pool.h"
#include <iostream>

void testThread1()
{
    std::cout << "Hello, this is thread 1" << std::endl;
    for (int i =0; i <10; i++)
    {
        std::cout << i << std::endl;
    }
}

void testThread2()
{
    std::cout << "Hello, this is thread 2" << std::endl;
    for (int i =0; i <10; i++)
    {
        std::cout << i << std::endl;
    }
}

int main() {
    std::cout << "Starting test" << std::endl;
    auto tp = ThreadPool(3);
    std::function<void()> f1 = testThread1;
    std::function<void()> f2 = testThread2;
    tp.QueueJob(&f1);
    tp.QueueJob(&f2);

    while(true)
    {

    }
    return 0;
}
