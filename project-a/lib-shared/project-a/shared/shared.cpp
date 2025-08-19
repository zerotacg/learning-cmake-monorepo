#include <project-a/shared/shared.hpp>
#include <project-a/shared/other.hpp>

#include <iostream>

void project_a::shared::helloWorld() {
    std::cout << "Shared Hello World!" << PRIVATE_VALUE << std::endl;
}
