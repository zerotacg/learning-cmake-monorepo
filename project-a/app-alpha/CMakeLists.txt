set(COMPONENT_NAME "alpha")

add_executable(${COMPONENT_NAME}
        project-a/alpha/main.cpp
)
target_link_libraries(
        ${COMPONENT_NAME}
        PUBLIC "${project_namespace}::shared"
        PRIVATE "${project_namespace}::static"
)
set_target_properties(${COMPONENT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}-${COMPONENT_NAME}")

install(TARGETS "${COMPONENT_NAME}"
        COMPONENT "${PROJECT_NAME}"
)

add_test(NAME "${PROJECT_NAME}.can-start" COMMAND "${COMPONENT_NAME}")
