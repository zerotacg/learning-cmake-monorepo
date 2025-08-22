# learning-cmake-monorepo

pipeline for cmake project with multiple sub projects

project-b has a dependency on project-a

the pipeline only triggers if sources of the respective project are changed. In case of project-b it also triggers if
it's dependency got build.

Locally the project can be opened as a whole. In the pipeline project-b uses project-a from it's artifacts

## Usage

complete monorepo
```bash
cmake --workflow --preset monorepo
```

project-a workflow
```bash
cmake --workflow --preset project-a
```
install project-a from package
```bash
build/project-a/project-a-*.sh --include-subdir --skip-license --prefix=build/install
```

project-b workflow
```bash
cmake --workflow --preset project-b
```

configure project-b using install of project-a
```bash
cmake --preset project-b -Dsubprojects:STRING="project-b"
```

## Credits

credits for inspirations and insights
* https://youtu.be/IZXNsim9TWI?si=NgFUAIZIjChK54ri
* https://galowicz.de/2023/01/23/mixed-cpp-monorepo-project/
* https://blog.vito.nyc/posts/cmake-pkg/

## TODO
 - [ ] add transitive dependency example as vcpkg fmt is static build and not really a dependency to project-b 
 - [ ] update to cmake 4 