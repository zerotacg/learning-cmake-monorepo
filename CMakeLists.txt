cmake_minimum_required(VERSION 3.28)

project(monorepo VERSION 1.0.0)

enable_testing()

option(WITH_project-a "Enable project-a" ON)
option(WITH_project-b "Enable project-b" ON)

set(subprojects
        project-a
        project-b
)

foreach(subproject ${subprojects})
    if(WITH_${subproject})
        message("adding sub project '${subproject}'")
        list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_BINARY_DIR}/${subproject}/generated")
        add_subdirectory(${subproject})
    endif ()
endforeach()
