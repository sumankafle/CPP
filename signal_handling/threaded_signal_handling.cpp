/**
 * @file threaded_signal_handling.cpp
 * @brief Demonstrates signal handling in a multithreaded C++ application.
 *
 * Uses a dedicated signal-handling thread with sigwait().
 * This is the recommended approach for Linux/POSIX systems.
 *
 * @author Suman Kafle
 * @date 2026
 */

#include <iostream>
#include <thread>
#include <atomic>
#include <csignal>
#include <pthread.h>
#include <unistd.h>

/**
 * @brief Global flag to control application lifetime.
 */
std::atomic<bool> g_running(true);

/**
 * @brief Worker thread function.
 *
 * Simulates normal application work.
 */
void workerThread()
{
    while (g_running.load())
    {
        std::cout << "[Worker] Running...\n";
        sleep(1);
    }

    std::cout << "[Worker] Shutdown complete.\n";
}

/**
 * @brief Signal handling thread.
 *
 * Blocks SIGINT and SIGTERM and waits synchronously
 * using sigwait().
 *
 * @param signalSet Set of signals to wait for.
 */
void signalHandlerThread(sigset_t signalSet)
{
    int receivedSignal;

    while (true)
    {
        if (sigwait(&signalSet, &receivedSignal) == 0)
        {
            switch (receivedSignal)
            {
                case SIGINT:
                    std::cout << "[Signal] SIGINT received\n";
                    break;

                case SIGTERM:
                    std::cout << "[Signal] SIGTERM received\n";
                    break;

                default:
                    std::cout << "[Signal] Unknown signal\n";
                    break;
            }

            g_running.store(false);
            break;
        }
    }
}

/**
 * @brief Main function.
 *
 * Blocks signals globally and starts worker and signal threads.
 *
 * @return int Exit status.
 */
int main()
{
    std::cout << "Process ID: " << getpid() << std::endl;
    std::cout << "Press Ctrl+C to stop\n";

    /**
     * Step 1: Block signals in all threads
     */
    sigset_t signalSet;
    sigemptyset(&signalSet);
    sigaddset(&signalSet, SIGINT);
    sigaddset(&signalSet, SIGTERM);

    if (pthread_sigmask(SIG_BLOCK, &signalSet, nullptr) != 0)
    {
        perror("pthread_sigmask");
        return 1;
    }

    /**
     * Step 2: Start worker thread(s)
     */
    std::thread worker(workerThread);

    /**
     * Step 3: Start dedicated signal handling thread
     */
    std::thread signalThread(signalHandlerThread, signalSet);

    /**
     * Step 4: Join threads
     */
    worker.join();
    signalThread.join();

    std::cout << "Application exited cleanly.\n";
    return 0;
}
