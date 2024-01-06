project(monorepo_alpha LANGUAGES CXX)

file(GLOB SRC alpha/*.cpp)

add_executable(alpha ${SRC})
target_link_libraries(alpha monorepo::shared)
