#include <iostream>
#include <project-a/shared/shared.hpp>

int main() {
    // dependant change
    std::cout << "gamma: ";
    project_a::shared::helloWorld();
    return 0;
}
