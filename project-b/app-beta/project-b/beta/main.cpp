#include <project-a/shared/shared.hpp>
#include <fmt/color.h>

int main() {
    fmt::print(fg(fmt::color::lavender_blush) | fmt::emphasis::bold,"beta: ");
    project_a::shared::helloWorld();
    return 0;
}
