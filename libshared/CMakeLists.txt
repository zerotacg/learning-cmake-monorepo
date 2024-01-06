project(monorepo_libshared VERSION 1.0.0 LANGUAGES CXX)

file(GLOB SRC libshared/*.cpp)

add_library(shared ${SRC})
add_library(monorepo::shared ALIAS shared)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(shared
        INTERFACE
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

install(TARGETS shared
        EXPORT sharedTargets
)
install(EXPORT sharedTargets
        FILE monoreposharedTargets.cmake
        NAMESPACE monorepo::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/monoreposhared
)
