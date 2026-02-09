#include<iostream>

class Example {
public:
    void displayMessage() {
        std::cout << "Hello from Example class!" << std::endl;
    }
};

int main() {

    Example object;
    object.displayMessage();
    Example* pObject = &object;
    pObject->displayMessage();
    return 0;
}