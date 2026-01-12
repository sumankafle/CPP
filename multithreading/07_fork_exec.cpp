/**
 * @file fork_exec_args.cpp
 * @brief Demonstrates fork() + exec() using command-line arguments.
 *
 * The program forks a child process. The child replaces itself
 * with a command provided via command-line arguments.
 *
 * Example:
 *   ./fork_exec ls -l
 *
 * @note POSIX/Linux specific
 *
 * @author suman
 * @date 2025/08/10
 */

#include <iostream>
#include <unistd.h>     // fork(), execvp()
#include <sys/wait.h>   // waitpid()
#include <sys/types.h>

/**
 * @brief Entry point of the program.
 *
 * @param argc Argument count
 * @param argv Argument vector
 * @return int Program exit status
 */
int main(int argc, char* argv[])
{
    // Ensure a command is provided
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <command> [args...]\n";
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0)
    {
        std::cerr << "fork() failed\n";
        return 1;
    }
    else if (pid == 0)
    {
        // Child process
        std::cout << "Child PID " << getpid()
                  << " executing command...\n";

        // Execute command from argv[1]
        // argv + 1 shifts argument list to command
        execvp(argv[1], &argv[1]);

        // execvp returns only on failure
        std::cerr << "execvp() failed\n";
        return 1;
    }
    else
    {
        // Parent process
        std::cout << "Parent PID " << getpid()
                  << " waiting for child...\n";

        waitpid(pid, nullptr, 0);

        std::cout << "Child process finished.\n";
    }

    return 0;
}
