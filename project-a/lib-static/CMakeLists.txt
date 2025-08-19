set(COMPONENT_NAME "static")

add_library(${COMPONENT_NAME} STATIC)
target_sources(${COMPONENT_NAME}
        PRIVATE
        project-a/special/special.cpp
)
target_sources(${COMPONENT_NAME}
        PUBLIC
        FILE_SET HEADERS
)
add_project_library_alias(${COMPONENT_NAME} ${COMPONENT_NAME})
set_target_properties(${COMPONENT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}-${COMPONENT_NAME}")
