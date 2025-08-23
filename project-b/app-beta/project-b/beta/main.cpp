#include <iostream>
#include <project-a/shared/shared.hpp>

int main() {
    // b changes
    std::cout << "beta: ";
    project_a::shared::helloWorld();
    return 0;
}
