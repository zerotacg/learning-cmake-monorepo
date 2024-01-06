cmake_minimum_required(VERSION 3.16)

project(monorepo_alpha VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SRC alpha/*.cpp)

add_executable(alpha ${SRC})
target_link_libraries(alpha monorepo::shared)

include(CPack)
