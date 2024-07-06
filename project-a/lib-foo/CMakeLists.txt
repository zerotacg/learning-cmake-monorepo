set(COMPONENT_NAME "foo")

add_library(${COMPONENT_NAME})
target_sources(${COMPONENT_NAME}
        PRIVATE
        project-a/foo/foo.cpp
)
target_sources(${COMPONENT_NAME}
        PUBLIC
        FILE_SET HEADERS
        FILES
        project-a/foo/foo.hpp
)
add_library("${project_namespace}::${COMPONENT_NAME}" ALIAS ${COMPONENT_NAME})
set_target_properties(${COMPONENT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}-${COMPONENT_NAME}")
target_link_libraries(${COMPONENT_NAME} PRIVATE "${project_namespace}::special")
set(targets_export_name "${PROJECT_NAME}-${COMPONENT_NAME}-targets")

install(TARGETS "${COMPONENT_NAME}"
        COMPONENT "${PROJECT_NAME}"
        EXPORT "${targets_export_name}"
        FILE_SET HEADERS
)

install(EXPORT "${targets_export_name}"
        COMPONENT "${PROJECT_NAME}"
        NAMESPACE "${project_namespace}::"
        DESTINATION "${config_install_dir}"
)

list(APPEND package_components "${COMPONENT_NAME}")
set(package_components ${package_components} PARENT_SCOPE)
