add_executable(project-c-gamma)
target_sources(project-c-gamma
        PRIVATE
        project-c/gamma/main.cpp
)
target_link_libraries(project-c-gamma
        PRIVATE
        project-a::shared
)
set_target_properties(project-c-gamma PROPERTIES OUTPUT_NAME "${PROJECT_NAME}-gamma")

install(
        TARGETS project-c-gamma
        COMPONENT ${PROJECT_NAME}
)

add_test(NAME "${PROJECT_NAME}.can-start" COMMAND project-c-gamma)
