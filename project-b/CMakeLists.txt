cmake_minimum_required(VERSION 3.16)

project(project-b VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(project-a CONFIG REQUIRED COMPONENTS shared)

add_subdirectory(gamma)
