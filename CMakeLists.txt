cmake_minimum_required(VERSION 3.28)

project(monorepo VERSION 1.0.0)

enable_testing()

set(subprojects project-a project-b)
macro(find_package)
    if (NOT "${ARGV0}" IN_LIST subprojects)
        _find_package(${ARGV})
    endif ()
endmacro()

add_subdirectory(project-a)
add_subdirectory(project-b)
