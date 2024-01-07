cmake_minimum_required(VERSION 3.16)

project(monorepo-libshared VERSION 1.0.0 LANGUAGES CXX)

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


file(GLOB SRC libshared/*.cpp)

add_library(monorepo-shared ${SRC})
add_library(monorepo::shared ALIAS monorepo-shared)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(monorepo-shared
        INTERFACE
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

set(config_install_dir "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")
set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(version_config "${generated_dir}/${PROJECT_NAME}-config-version.cmake")
set(component_config "${generated_dir}/${PROJECT_NAME}-config.cmake")
set(project_config "${CMAKE_CURRENT_SOURCE_DIR}/../cmake/Findmonorepo.cmake")
set(targets_export_name "${PROJECT_NAME}-targets")
set(namespace "monorepo::")

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
        "${version_config}" COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
        "cmake/config.cmake.in"
        "${component_config}"
        INSTALL_DESTINATION "${config_install_dir}"
)

install(TARGETS monorepo-shared
        EXPORT "${targets_export_name}"
)

install(FILES "${project_config}" "${component_config}" "${version_config}"
        DESTINATION "${config_install_dir}"
)

install(EXPORT "${targets_export_name}"
        NAMESPACE "${namespace}"
        DESTINATION "${config_install_dir}"
)

include(CPack)
