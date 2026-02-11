#include <iostream>
#include <string>

namespace math_utilis{
    int add(int a, int b){
        return a + b;
    }

    void print(int value){
        std::cout<< "[math utilis] value =" << value << std::endl;
    }
}

namespace string_utilis {

    void print(const std:: string& text){
        std::cout << "[string_utils] text = " << text << std::endl;
    }
}

int main(){

    int sum = math_utilis::add(10, 20);
    math_utilis::print(sum);
    string_utilis::print("Hello Namespace");

    using math_utilis:: add;

    int result = add(5, 7);
    std::cout << "Result = " << result << std::endl;

    return 0;
}