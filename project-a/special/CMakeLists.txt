set(COMPONENT_NAME "special")

file(GLOB SRC "${PROJECT_NAME}/${COMPONENT_NAME}/*.cpp")
file(GLOB HEADER "${PROJECT_NAME}/${COMPONENT_NAME}/*.hpp")

add_library(${COMPONENT_NAME} ${SRC})
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

install(FILES ${HEADER} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}/${COMPONENT_NAME})

install(EXPORT "${targets_export_name}"
        NAMESPACE "${project_namespace}::"
        DESTINATION "${config_install_dir}"
)

list(APPEND package_components "${COMPONENT_NAME}")
