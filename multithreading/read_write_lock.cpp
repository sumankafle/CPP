/**
 * @file ReadWriteLockExample.cpp
 * @brief Example implementation of a Reader-Writer Lock in C++ with multiple readers and single writer.
 *
 * This file demonstrates a thread-safe Reader-Writer lock using std::mutex
 * and std::condition_variable. It allows multiple readers to read simultaneously,
 * but ensures exclusive access for a writer. The code also contains
 * a simple test to verify the behavior.
 *
 * @author Suman Kafle
 * @date 2026-01-10
 */

 #include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>   
#include <condition_variable>

class ReadWriteLock {

    private:
    std::mutex mtx;
    std::condition_variable cvReader;
    std::condition_variable cvWriter;
    int activeReaders{0};
    int waitingWriters{0};
    bool writerActive = false;
public:

    void acquireReadLock() {
        std::unique_lock<std::mutex> lock(mtx);
        cvReader.wait(lock, [this]() { return waitingWriters == 0 && !writerActive; });
        ++activeReaders;
    }

    void releaseReadLock() {
        std::unique_lock<std::mutex> lock(mtx);
        --activeReaders;
        if (activeReaders == 0 && waitingWriters > 0) {
            cvWriter.notify_one();
        }
    }

    void acquireWriteLock() {
        std::unique_lock<std::mutex> lock(mtx);
        ++waitingWriters;
        cvWriter.wait(lock, [this]() { return activeReaders == 0 && !writerActive; });
        --waitingWriters;
        writerActive = true;
    }

    void releaseWriteLock() {
        std::unique_lock<std::mutex> lock(mtx);
        writerActive = false;
        if (waitingWriters > 0) {
            cvWriter.notify_one();
        } else {
            cvReader.notify_all();
        }
    }
};

void reader(int id, ReadWriteLock& rwLock) {
    rwLock.acquireReadLock();
    std::cout << "Reader " << id << " is reading." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "Reader " << id << " has finished reading." << std::endl;
    rwLock.releaseReadLock();
}

void writer(int id, ReadWriteLock& rwLock) {
    rwLock.acquireWriteLock();
    std::cout << "Writer " << id << " is writing." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    std::cout << "Writer " << id << " has finished writing." << std::endl;
    rwLock.releaseWriteLock();
}

int main() {
    ReadWriteLock rwLock;

    std::vector<std::thread> threads;

    // Create reader threads
    for (int i = 1; i <= 3; ++i) {
        threads.emplace_back(reader, i, std::ref(rwLock));
    }

    // Create writer thread
    threads.emplace_back(writer, 1, std::ref(rwLock));

    // Create additional reader threads
    for (int i = 4; i <= 5; ++i) {
        threads.emplace_back(reader, i, std::ref(rwLock));
    }

    // Join all threads
    for (auto &t : threads) {
        t.join();
    }

    std::cout << "Test complete.\n";
    return 0;
}