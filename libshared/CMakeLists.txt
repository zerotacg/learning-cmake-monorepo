cmake_minimum_required(VERSION 3.16)

project(monorepo-shared VERSION 1.0.0 LANGUAGES CXX)
set(COMPONENT_NAME ${PROJECT_NAME})

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


file(GLOB SRC libshared/*.cpp)

add_library(${COMPONENT_NAME} ${SRC})
add_library(monorepo::shared ALIAS ${COMPONENT_NAME})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(${COMPONENT_NAME}
        INTERFACE
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

set(config_install_dir "${CMAKE_INSTALL_LIBDIR}/cmake/${COMPONENT_NAME}")
set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(version_config "${generated_dir}/${PROJECT_NAME}-config-version.cmake")
set(component_config "${generated_dir}/${PROJECT_NAME}-config.cmake")
set(project_config "${CMAKE_CURRENT_SOURCE_DIR}/../cmake/Findmonorepo.cmake")
set(TARGETS_EXPORT_NAME "${PROJECT_NAME}-targets")
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
        EXPORT "${TARGETS_EXPORT_NAME}"
)

install(FILES "${component_config}" "${version_config}"
        DESTINATION "${config_install_dir}"
)

install(FILES "${project_config}"
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/monorepo"
        RENAME "monorepo-config.cmake"
)

install(EXPORT "${TARGETS_EXPORT_NAME}"
        NAMESPACE "${namespace}"
        DESTINATION "${config_install_dir}"
)

include(CPack)
