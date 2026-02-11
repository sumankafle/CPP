#include <iostream>
#include <thread>
#include <string>

class Config {

public:
    Config(std::string name, int max)
        : appName(std::move(name)), maxConnections(max) {}
    const std::string appName;
    const int maxConnections;
};

void printConfig(const Config& cfg){

    std::cout<<cfg.appName <<" | "<< cfg.maxConnections<< std::endl;
}

int main() {

    Config config("MyServer", 256);
    std::thread t1(printConfig, std::cref(config));
    std::thread t2(printConfig, std::cref(config));

    t1.join();
    t2.join();

    return 0;
}