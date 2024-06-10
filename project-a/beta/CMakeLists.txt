add_executable(beta
        beta/main.cpp
)
target_link_libraries(beta "${project_namespace}::shared")
