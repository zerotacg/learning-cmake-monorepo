set(COMPONENT_NAME "special")

add_library(${COMPONENT_NAME})
target_sources(${COMPONENT_NAME}
        PRIVATE
        project-a/special/special.cpp
)
target_sources(${COMPONENT_NAME}
        PUBLIC
        FILE_SET HEADERS
)
add_library("${project_namespace}::${COMPONENT_NAME}" ALIAS ${COMPONENT_NAME})
set_target_properties(${COMPONENT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}-${COMPONENT_NAME}")

set(targets_export_name "${PROJECT_NAME}-${COMPONENT_NAME}-targets")
install(TARGETS "${COMPONENT_NAME}"
        COMPONENT "${PROJECT_NAME}"
        EXPORT "${targets_export_name}"
        FILE_SET HEADERS
)
