cmake_minimum_required(VERSION 3.16)

project(monorepo VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(libshared)
add_subdirectory(alpha)
add_subdirectory(beta)

include(CPack)
