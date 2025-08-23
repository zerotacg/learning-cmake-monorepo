cmake_minimum_required(VERSION 3.28)

project(project-c VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

find_package(project-a 1.0.0 CONFIG REQUIRED COMPONENTS shared)

add_subdirectory(app-gamma)

include(CPack)
