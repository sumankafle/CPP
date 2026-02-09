#include<iostream>

template<typename T> T max (T a, T b){
    return (a>b)?a:b;
}

template <typename T> class Max{

    public:

    T x, y;

    Max(T val1, T val2): x(val1), y(val2){

    }
    void getValues(){
        std::cout << x <<"  "<< y << std::endl;
    }

};
int main () {

    int maxInt = max<int>(10, 20);
    std::cout<<" Max of 10 and 20 is: "<< maxInt<<std::endl;
    double maxDouble = max<double>(15.5, 25.5);
    std::cout<<" Max of 15.5 and 25.5 is: "<< maxDouble<<std::endl;     
    Max<int> maxObj(30, 40);
    maxObj.getValues(); 
    return 0;
}