#include <iostream>

class Example {
public:
    Example() {
        std::cout << "A";
    }
    Example(const Example &aux) {
        std::cout << "B";
    }
    ~Example() {
        std::cout << "C";
    }
};

// ABACAAAAAACCC

int main() {
    Example ex1{};
    Example ex2(ex1);
    Example ex3{};
    ex3.~Example();
    for (int i = 0; i < 6; ++i) {
        ex1 = *new Example{};
    }
    return 0;
}