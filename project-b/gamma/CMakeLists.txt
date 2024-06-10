set(COMPONENT_NAME "gamma")

add_executable(${COMPONENT_NAME}
        project-b/gamma/main.cpp
)
target_link_libraries(${COMPONENT_NAME} project-a::special)
set_target_properties(${COMPONENT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}-${COMPONENT_NAME}")
