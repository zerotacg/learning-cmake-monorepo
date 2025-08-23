add_executable(project-b-beta)
target_sources(project-b-beta
        PRIVATE
        project-b/beta/main.cpp
)
target_link_libraries(project-b-beta
        PRIVATE
        project-a::shared
)
set_target_properties(project-b-beta PROPERTIES OUTPUT_NAME "${PROJECT_NAME}-beta")

install(
        TARGETS project-b-beta
        COMPONENT ${PROJECT_NAME}
)

add_test(NAME "${PROJECT_NAME}.can-start" COMMAND project-b-beta)
