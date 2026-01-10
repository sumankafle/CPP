#include<iostream>


int addition(int a, int b) {
    return a + b;
}

int subtraction(int a, int b) {
    return a - b;
}

int operation(int x, int y, int (*functocall)(int, int)) {

    int result{};
    result = functocall(x, y);
    return result;
}

int main() {
    int m{};
    int n{};

    int (*minus)(int, int) = subtraction;
    int (*plus)(int, int) = addition;

    m = operation(7, 5, plus);
    std::cout << "Addition is: " << m << std::endl;     

    n = operation(20, m, minus);
    std::cout << "Subtraction is: " << n << std::endl;

    
    return EXIT_SUCCESS;
}