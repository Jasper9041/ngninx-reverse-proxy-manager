cmake_minimum_required(VERSION 3.12)
project(ngninx_reverse_proxy_manager)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

configure_file(base-template.conf base-template.conf COPYONLY)
configure_file(http-template.conf http-template.conf COPYONLY)
configure_file(https-template.conf https-template.conf COPYONLY)
configure_file(http-to-https-redirect-template.conf http-to-https-redirect-template.conf COPYONLY)

add_executable(ngninx_reverse_proxy_manager
        Destination.cpp
        Destination.h
        nrpm.cpp
        Service.cpp
        Service.h ConfigurationWriter.cpp ConfigurationWriter.h Exceptions/FileOpenException.cpp Exceptions/FileOpenException.h)
