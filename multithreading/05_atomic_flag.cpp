/**
 * @file atomic_flag.cpp
 * @brief Demonstrates thread synchronization using std::atomic_flag.
 *
 * This program uses an atomic flag as a lightweight spinlock
 * to synchronize access to a critical section between threads.
 *
 * Unlike mutexes, atomic_flag provides low-level atomic operations
 * and is often used in lock-free or performance-critical systems.
 *
 * @author suman
 * @date 2026
 */

#include <atomic>
#include <iostream>
#include <thread>

/**
 * @brief Atomic flag used as a spinlock.
 *
 * ATOMIC_FLAG_INIT initializes the flag to a clear (false) state.
 */
std::atomic_flag flag = ATOMIC_FLAG_INIT;

/**
 * @brief Function executed by each thread.
 *
 * Uses atomic_flag to ensure only one thread
 * enters the critical section at a time.
 *
 * @param id Thread identifier
 */
void thread_function(int id)
{
    for (int i = 0; i < 5; ++i)
    {
        // Spin until the flag is successfully set (lock acquired)
        while (flag.test_and_set(std::memory_order_acquire))
        {
            // Busy-wait (spinlock)
        }

        // Critical section
        std::cout << "Thread " << id << " is running." << std::endl;

        // Release the lock
        flag.clear(std::memory_order_release);
    }
}

/**
 * @brief Entry point of the program.
 *
 * Creates two threads that synchronize access
 * to a shared resource using atomic_flag.
 *
 * @return int Program exit status
 */
int main()
{
    std::thread t1(thread_function, 1);
    std::thread t2(thread_function, 2);

    t1.join();
    t2.join();

    return 0;
}
