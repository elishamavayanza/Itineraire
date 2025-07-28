cmake_minimum_required(VERSION 3.31)
project(TpItineraire)

set(CMAKE_CXX_STANDARD 20)

add_executable(TpItineraire main.cpp
        Point.cpp
        Point.h
        Itineraire.cpp
        Itineraire.h
        RouteOptimizer.cpp
        RouteOptimizer.h)
if(MSVC)
    add_compile_options(/utf-8)
else()
    add_compile_options(-Wall -Wextra)
endif()