set(COMPONENT_NAME "gamma")

add_executable(${COMPONENT_NAME}
        project-b/gamma/main.cpp
)
target_link_libraries(${COMPONENT_NAME} project-a::foo project-a::shared)
set_target_properties(${COMPONENT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}-${COMPONENT_NAME}")

install(
        TARGETS "${COMPONENT_NAME}"
        COMPONENT ${PROJECT_NAME}
)

add_test(NAME "${PROJECT_NAME}.can-start" COMMAND "${COMPONENT_NAME}")
