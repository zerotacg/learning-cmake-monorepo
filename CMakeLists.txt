cmake_minimum_required(VERSION 3.28)

project(monorepo VERSION 1.0.0)

enable_testing()

set(subprojects
        project-a
        project-b
        CACHE STRING "Subprojects to use directly from source"
)

foreach(subproject ${subprojects})
    list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_BINARY_DIR}/${subproject}/generated")
endforeach()

add_subdirectory(project-a)
add_subdirectory(project-b)
