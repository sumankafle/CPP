#include<iostream>
#include<thread>
#include<queue>
#include<mutex>
#include<condition_variable>

template<typename T>

class ThreadSafeQueue {

private:

    std::queue<T> queue_;
    std::mutex mtx_;
    std::condition_variable cv_;

public:

    void push(T value){
        {
            std::lock_guard<std::mutex> lock(mtx_);
            queue_.push(std::move(value));
        }
        cv_.notify_one();
    }

    T pop() {

        std::unique_lock<std::mutex> lock(mtx_);
        cv_.wait(lock, [this] { return !queue_.empty();});

        T value = std::move(queue_.front());
        queue_.pop();
        return value;

    }
};

int main (){

    ThreadSafeQueue<int> queue;

    std::thread producer([&] () {
        for(int i = 1;i <=5;++i)
            queue.push(i);
    });

    std::thread consumer([&] () {
        for(int i = 1; i< 6; ++i){
            std::cout << "Received: "<< queue.pop() << std::endl;
        }
    });

    producer.join();
    consumer.join();

    return 0;
}