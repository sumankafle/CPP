#include<iostream>

template<typename T>

class Numbers{
   T x, y;
    public:

        Numbers(T x, T y){
            this->x = x;
            this->y = y;
        }
        T max() const{
            return (x>y)?x:y;
        }
};

int main(){
    
    Numbers <int> n1(10, 20);
    std::cout<<"Max of 10 and 20 is: "<<n1.max()<<std::endl;

    Numbers<double> n2(15.5, 25.5);
    std::cout<<"Max of 15.5 and 25.5 is: "<<n2.max()<<std::endl;

    return 0;
}