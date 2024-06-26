set(COMPONENT_NAME "shared")

add_library(${COMPONENT_NAME}
        project-a/shared/shared.cpp
)
add_library("${project_namespace}::${COMPONENT_NAME}" ALIAS ${COMPONENT_NAME})
set_target_properties(${COMPONENT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}-${COMPONENT_NAME}")

target_include_directories(${COMPONENT_NAME}
        PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(targets_export_name "${PROJECT_NAME}-${COMPONENT_NAME}-targets")

install(FILES
        project-a/shared/shared.hpp
        COMPONENT "${PROJECT_NAME}"
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}/${COMPONENT_NAME}
)

install(TARGETS "${COMPONENT_NAME}"
        COMPONENT "${PROJECT_NAME}"
        EXPORT "${targets_export_name}"
)

install(EXPORT "${targets_export_name}"
        COMPONENT "${PROJECT_NAME}"
        NAMESPACE "${project_namespace}::"
        DESTINATION "${config_install_dir}"
)

list(APPEND package_components "${COMPONENT_NAME}")
set(package_components ${package_components} PARENT_SCOPE)
