#include <project-a/shared/shared.hpp>
#include <project-a/shared/other.hpp>

#include <fmt/color.h>

void project_a::shared::helloWorld() {
    fmt::print(fg(fmt::color::forest_green), "Shared Hello World!\n");
    fmt::print(fg(fmt::color::indian_red), " - With 'PRIVATE_VALUE' {}\n", PRIVATE_VALUE);
}
