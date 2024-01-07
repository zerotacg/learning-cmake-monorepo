set(_project_prefix "monorepo")
if (CMAKE_VERSION VERSION_LESS 3.16.0)
    message(FATAL_ERROR "${_project_prefix} requires at least CMake version 3.16.0")
endif()

if (NOT $<{$_project_prefix}_FIND_COMPONENTS>)
    set(monorepo_NOT_FOUND_MESSAGE "The ${_project_prefix} package requires at least one component")
    set(monorepo_FOUND False)
    return()
endif()

set(_monorepo_FIND_PARTS_REQUIRED)
if (monorepo_FIND_REQUIRED)
    set(_monorepo_FIND_PARTS_REQUIRED REQUIRED)
endif()
set(_monorepo_FIND_PARTS_QUIET)
if (monorepo_FIND_QUIETLY)
    set(_monorepo_FIND_PARTS_QUIET QUIET)
endif()

get_filename_component(_monorepo_install_prefix "${CMAKE_CURRENT_LIST_DIR}/.." ABSOLUTE)

set(_monorepo_NOTFOUND_MESSAGE)

foreach(module ${monorepo_FIND_COMPONENTS})
    find_package(monorepo${module}
            ${_monorepo_FIND_PARTS_QUIET}
            ${_monorepo_FIND_PARTS_REQUIRED}
            PATHS ${_monorepo_module_paths} NO_DEFAULT_PATH
    )
    if (NOT monorepo${module}_FOUND)
        string(CONFIGURE ${_monorepo_module_location_template} _expected_module_location @ONLY)

        if (monorepo_FIND_REQUIRED_${module})
            set(_monorepo_NOTFOUND_MESSAGE "${_monorepo_NOTFOUND_MESSAGE}Failed to find ${_project_prefix} component \"${module}\" config file at \"${_expected_module_location}\"\n")
        elseif(NOT monorepo_FIND_QUIETLY)
            message(WARNING "Failed to find ${_project_prefix} component \"${module}\" config file at \"${_expected_module_location}\"")
        endif()

        unset(_expected_module_location)
    endif()
endforeach()

if (_monorepo_NOTFOUND_MESSAGE)
    set(monorepo_NOT_FOUND_MESSAGE "${_monorepo_NOTFOUND_MESSAGE}")
    set(monorepo_FOUND False)
endif()

_monorepo_Core_check_file_exists("${CMAKE_CURRENT_LIST_DIR}/monorepo-config-version.cmake")
