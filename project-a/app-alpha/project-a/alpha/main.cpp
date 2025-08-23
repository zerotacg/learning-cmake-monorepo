#include <project-a/shared/shared.hpp>
#include <project-a/special/special.hpp>
#include <fmt/color.h>

using namespace project_a;

int main() {
    fmt::print(fg(fmt::color::forest_green) | fmt::emphasis::bold,"alpha: ");
    shared::helloWorld();
    fmt::print(fg(fmt::color::indian_red) | fmt::emphasis::bold,"alpha: ");
    special::helloWorld();
    return 0;
}
