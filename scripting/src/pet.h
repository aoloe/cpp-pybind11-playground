#include <string>

class Dog {
public:
    Dog(const std::string &name) : name(name) {}
    void setName(const std::string &n) {name = n;}
    const std::string getName() const {return name;}
private:
    std::string name;
};

class Cat {
public:
    Cat(const std::string &name) : name(name) {}
    void setName(const std::string &n) {name = n;}
    const std::string getName() const {return name;}
private:
    std::string name;
};

