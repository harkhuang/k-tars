cmake_minimum_required(VERSION 3.17)
project(learn_tars)

set(CMAKE_CXX_STANDARD 14)

include_directories(..)

add_executable(server
        main.cpp
        tc_epoll_server.cpp
        tc_epoll_server.h
        tc_epoller.cpp
        tc_epoller.h)

add_executable(client
        client.cpp)
