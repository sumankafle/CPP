/**
 * @file fork_example.cpp
 * @brief Demonstrates process creation using fork() in Linux.
 *
 * This program shows how a parent process creates a child process
 * using fork(). The return value of fork() is used to distinguish
 * between parent and child processes.
 *
 * @note This program is POSIX-specific and works on Linux/Unix systems.
 *
 * @author suman
 * @date 2025/08/10
 */

#include <iostream>
#include <unistd.h>   // fork(), getpid()
#include <sys/types.h>

/**
 * @brief Entry point of the program.
 *
 * Creates a child process using fork() and prints
 * the process ID (PID) of both parent and child.
 *
 * @return int Program exit status
 */
int main()
{
    // fork() creates a new process
    // Return value:
    //  < 0 : fork failed
    //  = 0 : child process
    //  > 0 : parent process (returns child PID)
    pid_t npid = fork();

    if (npid < 0)
    {
        std::cerr << "Fork failed" << std::endl;
    }
    else if (npid > 0)
    {
        // Parent process
        std::cout << "Parent Process ID: " << getpid() << std::endl;
    }
    else if (npid == 0)
    {
        // Child process
        std::cout << "Child Process ID: " << getpid() << std::endl;
    }
    else
    {
        // This branch is logically unreachable
        std::cerr << "Unexpected case encountered." << std::endl;
    }

    return EXIT_SUCCESS;
}
