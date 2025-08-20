#include <project-a/shared/shared.hpp>
#include <project-a/shared/other.hpp>

#include <fmt/core.h>

void project_a::shared::helloWorld() {
    fmt::print("Shared Hello World! With 'PRIVATE_VALUE' {}\n", PRIVATE_VALUE);
}
