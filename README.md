# learning-cmake-monorepo

pipeline for cmake project with multiple sub projects

project-b has a dependency on project-a

the pipeline only triggers if sources of the respective project are changed. In case of project-b it also triggers if
it's dependency got build.

Locally the project can be opened as a whole. In the pipeline project-b uses project-a from it's artifacts

credits for inspirations and insights
* https://youtu.be/IZXNsim9TWI?si=NgFUAIZIjChK54ri
* https://galowicz.de/2023/01/23/mixed-cpp-monorepo-project/
