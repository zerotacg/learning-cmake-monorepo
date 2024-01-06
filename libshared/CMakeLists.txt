cmake_minimum_required(VERSION 3.16)

project(monorepo-libshared LANGUAGES CXX)

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


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

include(CPack)
