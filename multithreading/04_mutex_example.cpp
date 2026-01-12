/**
 * @file mutex_example.cpp
 * @brief Demonstrates thread synchronization using std::mutex.
 *
 * This program shows how multiple threads safely access
 * and modify a shared resource using a mutex to prevent
 * race conditions.
 *
 * @author suman
 * @date 2025/08/10
 */

#include <iostream>
#include <thread>
#include <mutex>

/**
 * @brief Mutex used to protect shared resources.
 */
std::mutex mtx;

/**
 * @brief Shared resource accessed by multiple threads.
 */
int counter = 0;

/**
 * @brief Increments the shared variable safely.
 *
 * Locks the mutex before modifying the shared variable
 * and unlocks it after the operation is complete.
 */
void safe_increment()
{
    // Lock the mutex to ensure exclusive access
    mtx.lock();

    // Critical section: modify shared resource
    for (int i = 0; i < 1000000; ++i)
    {
        counter++;
    }

    // Unlock the mutex
    mtx.unlock();
}

/**
 * @brief Entry point of the program.
 *
 * Creates two threads that increment a shared variable.
 * Mutex ensures the final result is correct and race-free.
 *
 * @return int Program exit status
 */
int main(){
    
    // Create threads
    std::thread t1(safe_increment);
    std::thread t2(safe_increment);

    // Wait for threads to finish
    t1.join();
    t2.join();

    // Print final value
    std::cout << "Number after execution of t1 and t2 is " << counter << std::endl;

    return 0;
}
