add_library(project-a-shared SHARED)
target_sources(project-a-shared
        PRIVATE
        project-a/shared/shared.cpp
)
target_sources(project-a-shared
        PUBLIC
        FILE_SET HEADERS
        FILES
        project-a/shared/shared.hpp
)
add_project_library_alias(project-a-shared shared)
set_target_properties(project-a-shared PROPERTIES OUTPUT_NAME "${PROJECT_NAME}-shared")
target_link_libraries(project-a-shared
        PUBLIC fmt::fmt
        PRIVATE project-a::static
)
set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(targets_export_name "${PROJECT_NAME}-shared-targets")

install(TARGETS project-a-shared
        COMPONENT "${PROJECT_NAME}"
        EXPORT "${targets_export_name}"
        FILE_SET HEADERS
)

install(EXPORT "${targets_export_name}"
        COMPONENT "${PROJECT_NAME}"
        NAMESPACE "${project_namespace}::"
        DESTINATION "${config_install_dir}"
)

list(APPEND package_components "shared")
set(package_components ${package_components} PARENT_SCOPE)
