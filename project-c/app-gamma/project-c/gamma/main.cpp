#include <project-a/shared/shared.hpp>
#include <fmt/color.h>

int main() {
    fmt::print(fg(fmt::color::aquamarine) | fmt::emphasis::bold,"gamma: ");
    project_a::shared::helloWorld();
    return 0;
}
