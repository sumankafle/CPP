/**
 * @file thread_join_detach.cpp
 * @brief Demonstrates std::thread join(), detach(), and thread IDs.
 *
 * This program shows:
 * - How to create multiple threads
 * - How to obtain thread IDs
 * - Difference between join() and detach()
 * - Use of sleep to allow detached thread to run
 *
 * @author suman
 * @date 2025/08/10
 */

#include <iostream>
#include <thread>
#include <chrono>

/**
 * @brief Function executed by the first thread.
 *
 * Prints the thread ID of the executing thread.
 */
void task1()
{
    std::cout << "Thread 1 is running. ID: "
              << std::this_thread::get_id() << "\n";
}

/**
 * @brief Function executed by the second thread.
 *
 * Prints the thread ID of the executing thread.
 */
void task2()
{
    std::cout << "Thread 2 is running. ID: "
              << std::this_thread::get_id() << "\n";
}

/**
 * @brief Entry point of the program.
 *
 * Creates two threads:
 * - One thread is joined (main waits)
 * - One thread is detached (runs independently)
 *
 * Demonstrates safe checking using joinable().
 *
 * @return int Program exit status
 */
int main()
{
    // Create two threads
    std::thread t1(task1);
    std::thread t2(task2);

    // Print thread IDs from main thread
    std::cout << "t1 ID: " << t1.get_id() << "\n";
    std::cout << "t2 ID: " << t2.get_id() << "\n";

    // Join t1 (main thread waits for completion)
    if (t1.joinable())
    {
        t1.join();
        std::cout << "t1 joined\n";
    }

    // Detach t2 (runs independently)
    if (t2.joinable())
    {
        t2.detach();
        std::cout << "t2 detached\n";
    }

    // Sleep to allow detached thread to finish
    std::cout << "Main thread sleeping for 1 second...\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Main thread awake.\n";

    return 0;
}
