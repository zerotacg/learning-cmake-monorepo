add_executable(project-a-alpha)
target_sources(project-a-alpha
        PRIVATE
        project-a/alpha/main.cpp
)
target_link_libraries(project-a-alpha
        PUBLIC project-a::shared
        PRIVATE
        project-a::static
        fmt::fmt
)
set_target_properties(project-a-alpha PROPERTIES OUTPUT_NAME "${PROJECT_NAME}-alpha")

install(
        TARGETS project-a-alpha
        COMPONENT ${PROJECT_NAME}
)

add_test(NAME "${PROJECT_NAME}.can-start" COMMAND project-a-alpha)
