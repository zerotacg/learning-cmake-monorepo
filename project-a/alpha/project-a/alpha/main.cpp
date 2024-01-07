#include <iostream>
#include <project-a/shared/shared.hpp>
#include <project-a/special/special.hpp>

using namespace project_a;

int main() {
    std::cout << "alpha: ";
    shared::helloWorld();
    std::cout << "alpha: ";
    special::helloWorld();
    return 0;
}
