cmake_minimum_required(VERSION 3.28..4.1)

project(monorepo VERSION 1.0.0)

enable_testing()

set(subprojects
        project-a
        project-b
        project-c
        CACHE STRING "Subprojects to use directly from source"
)

foreach (subproject ${subprojects})
    message("adding sub project '${subproject}'")
    list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_BINARY_DIR}/${subproject}/generated")
    add_subdirectory(${subproject})
endforeach ()
