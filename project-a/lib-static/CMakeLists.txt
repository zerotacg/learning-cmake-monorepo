add_library(project-a-static STATIC)
target_sources(project-a-static
        PRIVATE
        project-a/special/special.cpp
)
target_sources(project-a-static
        PUBLIC
        FILE_SET HEADERS
)
add_project_library_alias(project-a-static static)
set_target_properties(project-a-static PROPERTIES OUTPUT_NAME "${PROJECT_NAME}-static")
