#include <iostream>
#include <csignal>   // signal(), SIGINT
#include <unistd.h>  // sleep()

/**
 * @brief Flag modified by signal handler
 *
 * sig_atomic_t guarantees atomic access between
 * normal code and signal handler.
 * volatile prevents compiler optimization.
 */
volatile sig_atomic_t flag = 0;

/**
 * @brief Signal handler for SIGINT (Ctrl+C)
 *
 * @param sig Signal number received
 *
 * IMPORTANT:
 * - Only async-signal-safe operations are allowed here
 * - No I/O, no heap, no locks
 */
void signalHandler(int sig)
{
    flag = 1;  // Set termination flag
}

/**
 * @brief Main function
 *
 * Registers signal handler and runs until Ctrl+C is pressed.
 *
 * @return int Exit status
 */
int main()
{
    // Register signalHandler for SIGINT (Ctrl+C)
    std::signal(SIGINT, signalHandler);

    std::cout << "Press Ctrl+C to call the signal handler\n";

    // Main loop runs until signalHandler sets flag
    while (!flag) {
        std::cout << "HelloWorld!\n";

        // Prevent busy waiting (CPU hogging)
        sleep(1);
    }

    std::cout << "Program will be terminated!\n";

    return 0;
}
