#include <iostream>
#include <project-a/foo/foo.hpp>
#include <project-a/shared/shared.hpp>

int main() {
    std::cout << "gamma: ";
    project_a::foo::foo();
    project_a::shared::helloWorld();
    return 0;
}
