#ifndef FOO_H
#define FOO_H
#include <iostream>
#include "bar.h"
struct Foo {
    Bar bar{};

    Foo() {std::cout << "Making a foo!" << std::endl;}
    Foo(const Foo& a) {bar = a.bar; std::cout << "Copying a new foo" << std::endl;}
    ~Foo() {std::cout << "Bye-bye foo!" << std::endl;}
};
#endif
