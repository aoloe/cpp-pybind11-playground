#ifndef BAR_H
#define BAR_H
#include <iostream>
struct Bar {
    int value = 1;

    Bar() {std::cout << "Making a bar!" << std::endl;}
    Bar(const Bar& a) {value = a.value; std::cout << "Copying a new bar" << std::endl;}
    ~Bar() {std::cout << "Bye-bye bar!" << std::endl;}
};
#endif
