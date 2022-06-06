cmake_minimum_required(VERSION 3.21.1)
project(Assignment_4_main)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment_4_main
        Classic.cpp
        Classic.h
        Comedy.cpp
        Comedy.h
        Customer.cpp
        Customer.h
        Drama.cpp
        Drama.h
        Genre.cpp
        Genre.h
        HashTable.cpp
        HashTable.h
        main.cpp
        Movies.cpp
        Movies.h
        RentalStore.cpp
        RentalStore.h)
