#include <iostream>
#include <project-a/shared/shared.hpp>

int main() {
    // c changes
    std::cout << "gamma: ";
    project_a::shared::helloWorld();
    return 0;
}
