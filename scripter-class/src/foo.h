#include <iostream>
struct Foo {
    int bar = 1;

    Foo() {std::cout << "Making a foo!" << std::endl;}
    Foo(const Foo& a) {bar = a.bar; std::cout << "Copying a new foo" << std::endl;}
    ~Foo() {std::cout << "Bye-bye foo!" << std::endl;}
};

