cmake_minimum_required(VERSION 3.12)
project(ngninx_reverse_proxy_manager)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ngninx_reverse_proxy_manager
        Destination.cpp
        Destination.h
        nrpm.cpp
        Service.cpp
        Service.h ConfigurationWriter.cpp ConfigurationWriter.h Exceptions/FileOpenException.cpp Exceptions/FileOpenException.h)
