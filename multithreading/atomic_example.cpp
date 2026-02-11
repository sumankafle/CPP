#include<iostream>
#include<thread>
#include<atomic>
#include<vector>

class AtomicCounter {
private:
    std::atomic<int> counter_ {0};
public:
    void increment() {
        counter_ ++;
    }
    int value() const {
        return counter_.load();
    }
};

int main() {

    AtomicCounter counter;
    std::vector<std::thread>threads;

    for(int i = 0;i < 4;++i){
        threads.emplace_back([&counter](){
            for(int j = 0; j<100;++j)
                counter.increment();
        });
    }

    for (auto &t: threads)
        t.join();
   
    std::cout<< "Final Value: "<< counter.value()<< std::endl;

    return 0;
}