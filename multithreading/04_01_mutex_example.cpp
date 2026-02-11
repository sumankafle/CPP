#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

class Counter
{
public:
    void increment() {
        std::lock_guard<std::mutex> lock(mtx);
        ++value_;
    }
    int value() const{
        std::lock_guard<std::mutex>lock(mtx);
        return value_;
    }
private:
    mutable std::mutex mtx;
    int value_ {0};
};

int main() {

    Counter counter;
    std::vector<std::thread>threads;

    for(int i = 0; i<4;++i){
        threads.emplace_back([&counter](){
            for(int j = 0; j<100;++j)
                counter.increment();
        });
    }

    for(auto& t : threads)
        t.join();

    std::cout << "Final value: " << counter.value() << "\n";
 
    return 0;
}
