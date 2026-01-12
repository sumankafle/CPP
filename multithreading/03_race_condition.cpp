/**
 * @file race_condition.cpp
 * @brief Demonstrates a data race caused by unsynchronized access to shared data.
 *
 * @details
 * A data race occurs when multiple threads access and modify shared data
 * simultaneously without proper synchronization.
 *
 * In this example, two threads increment the same global counter without
 * using a mutex or atomic variable. The final result is undefined and
 * usually less than the expected value.
 *
 * To see the correct solution, refer to: thread_safe_counters.cpp
 *
 * @author suman
 * @date 2025/08/10
 */

#include <thread>
#include <cassert>
#include <iostream>

/**
 * @brief Shared counter (NOT thread-safe).
 *
 * This variable is accessed by multiple threads
 * without synchronization, causing a data race.
 */
int counter = 0;

/**
 * @brief Unsafe increment function.
 *
 * Increments the shared counter without using:
 * - mutex
 * - atomic operations
 *
 * This function intentionally demonstrates a data race.
 */
void unsafe_increment()
{
    for (std::size_t j = 0; j < 1'000'000; ++j)
    {
        ++counter; // Data race occurs here
    }
}

/**
 * @brief Demonstrates thread-unsafe counter behavior.
 *
 * Spawns two threads that increment a shared variable
 * using an unsafe method. The final value is unpredictable.
 */
void thread_unsafe_counter()
{
    std::thread t1(unsafe_increment);
    std::thread t2(unsafe_increment);

    t1.join();
    t2.join();

    // Assertion passes, but correctness is NOT guaranteed
    assert(counter <= 2'000'000);

    std::cout << "Unsafe counter:\t"
              << counter
              << "\tTarget value: 2000000"
              << std::endl;
}

/**
 * @brief Entry point of the program.
 *
 * Executes the unsafe counter demonstration.
 *
 * @return int Program exit status
 */
int main()
{
    thread_unsafe_counter();
    return 0;
}
