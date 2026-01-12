/**
 * @file basic_thread.cpp
 * @brief Demonstrates basic usage of std::thread in C++.
 *
 * This program creates a separate thread to execute
 * a user-defined function and synchronizes it with
 * the main thread using join().
 *
 * @author suman
 * @date 2025/08/10
 */

#include <iostream>
#include <thread>

/**
 * @brief Function executed by the spawned thread.
 *
 * Prints a message indicating execution
 * from a separate thread.
 */
void threadFunction()
{
    std::cout << "Hello from the thread!" << std::endl;
}

/**
 * @brief Entry point of the program.
 *
 * Creates a thread, waits for its completion,
 * and then finishes execution in the main thread.
 *
 * @return int Program exit status
 */
int main()
{
    // Create a new thread that runs threadFunction()
    std::thread t(threadFunction);

    // Wait for the thread to finish execution
    t.join();

    // Executed after the worker thread completes
    std::cout << "Main thread finished." << std::endl;

    return 0;
}
