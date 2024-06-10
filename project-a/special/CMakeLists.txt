set(COMPONENT_NAME "special")

add_library(${COMPONENT_NAME}
        project-a/special/special.cpp
)
add_library("${project_namespace}::${COMPONENT_NAME}" ALIAS ${COMPONENT_NAME})
set_target_properties(${COMPONENT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}-${COMPONENT_NAME}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(${COMPONENT_NAME}
        INTERFACE
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(targets_export_name "${PROJECT_NAME}-${COMPONENT_NAME}-targets")


install(TARGETS "${COMPONENT_NAME}"
        EXPORT "${targets_export_name}"
)

install(FILES
        project-a/special/special.cpp
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}/${COMPONENT_NAME}
)

install(EXPORT "${targets_export_name}"
        NAMESPACE "${project_namespace}::"
        DESTINATION "${config_install_dir}"
)

list(APPEND package_components "${COMPONENT_NAME}")
