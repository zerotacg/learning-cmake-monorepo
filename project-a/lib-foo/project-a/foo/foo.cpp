#include <project-a/foo/foo.hpp>
#include <project-a/foo/other.hpp>

#include <iostream>

using namespace project_a::foo;

void project_a::foo::foo() {
    std::cout << "Hello foo! " << PRIVATE_VALUE << std::endl;
}
