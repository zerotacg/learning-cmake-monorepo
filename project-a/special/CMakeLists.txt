set(COMPONENT_NAME "special")

add_library(${COMPONENT_NAME}
        project-a/special/special.cpp
)
add_library("${project_namespace}::${COMPONENT_NAME}" ALIAS ${COMPONENT_NAME})
set_target_properties(${COMPONENT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}-${COMPONENT_NAME}")

target_include_directories(${COMPONENT_NAME}
        PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)
