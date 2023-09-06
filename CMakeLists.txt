cmake_minimum_required(VERSION 3.26)
project(c_sample C)

set(CMAKE_C_STANDARD 17)

add_executable(c_sample main.c
        Sample/Object-oriented/Staff.h
        Sample/Object-oriented/Staff.c
        Sample/Object-oriented/Object-oriented.c
        Sample/Object-oriented/Object-oriented.h
        Sample/Sample.c
        Sample/Sample.h
        Sample/Thread/Thread.c
        Sample/Thread/Thread.h)
