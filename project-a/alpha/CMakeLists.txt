set(COMPONENT_NAME "alpha")

file(GLOB SRC "${PROJECT_NAME}/${COMPONENT_NAME}/*.cpp")

add_executable(${COMPONENT_NAME} ${SRC})
target_link_libraries(${COMPONENT_NAME} "${project_namespace}::shared" "${project_namespace}::special")
set_target_properties(${COMPONENT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}-${COMPONENT_NAME}")
