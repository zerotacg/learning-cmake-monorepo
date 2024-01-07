file(GLOB SRC beta/*.cpp)

add_executable(beta ${SRC})
target_link_libraries(beta monorepo::shared)
