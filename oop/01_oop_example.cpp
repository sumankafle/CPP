#include <iostream>
#include <string>

enum AnimalType{

    cat,
    dog,
    chicken,
};

constexpr std::string_view animalName(AnimalType type) {

    switch(type){

        case cat: return "cat";
        case dog: return "dog";
        case chicken: return "chicken";
        default: return "";
    }
}

constexpr int numLegs(AnimalType type){

        switch(type){
        case cat: return 4;
        case dog: return 4;
        case chicken: return 2;
        default: return 0;
    }
}

int main(){


constexpr AnimalType myAnimal {0};
std::cout << "My animal is a " << animalName(myAnimal) << " and has " << numLegs(myAnimal) << " legs." << std::endl;
return 0;

}