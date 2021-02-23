cmake_minimum_required(VERSION 3.10)
project(learn_tars)

set(CMAKE_CXX_STANDARD 14)

include_directories(..)

add_executable(server2
        main.cpp
        tc_epoll_server.cpp
        tc_epoller.cpp
        tc_socket.cpp
        )

add_executable(client2
        client.cpp)
