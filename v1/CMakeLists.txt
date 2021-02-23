cmake_minimum_required(VERSION 3.10)
project(learn_tars)

set(CMAKE_CXX_STANDARD 14)

include_directories(..)

add_executable(server1
        main.cpp
        tc_epoll_server.cpp
        tc_epoll_server.h
        tc_epoller.cpp
        tc_epoller.h)

add_executable(client1
        client.cpp)




