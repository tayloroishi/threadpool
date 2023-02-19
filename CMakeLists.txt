cmake_minimum_required(VERSION 3.23)
project(threadpool)

set(CMAKE_CXX_STANDARD 20)

add_executable(threadpool main.cpp src/thread_pool.cpp src/thread_pool.h src/worker_thread.cpp src/worker_thread.h src/interfaces.h)
