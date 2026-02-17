#include<iostream>

int main (){

    float f = 3.5;
    int a = f;
    std::cout<<"The value of a: "<< a <<std::endl;

    int b = static_cast<int> (f);
    std::cout<<"The value of b: "<< b <<std::endl;
    return 0;
}