cmake_minimum_required(VERSION 3.16)

project(monorepo VERSION 1.0.0)

set(USE_LOCAL true)

add_subdirectory(project-a)
add_subdirectory(project-b)
