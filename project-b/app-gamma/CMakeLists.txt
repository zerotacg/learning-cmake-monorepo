add_executable(project-b-gamma)
target_sources(project-b-gamma
        PRIVATE
        project-b/gamma/main.cpp
)
target_link_libraries(project-b-gamma
        PRIVATE
        project-a::shared
)
set_target_properties(project-b-gamma PROPERTIES OUTPUT_NAME "${PROJECT_NAME}-gamma")

install(
        TARGETS project-b-gamma
        COMPONENT ${PROJECT_NAME}
)

add_test(NAME "${PROJECT_NAME}.can-start" COMMAND project-b-gamma)
