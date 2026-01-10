/**
 * @file compile_time_config.cpp
 * @brief Demonstrates compile-time configuration using preprocessor directives.
 *
 * This program shows how to enable or disable code at compile time using
 * macros such as DEBUG and platform-specific definitions. It illustrates
 * conditional compilation with #ifdef, #elif, #if, and #ifndef.
 *
 * @author suman
 * @date 2025/08/08
 */

#include <iostream>

/* -------- Compile-time configuration -------- */

/**
 * @def DEBUG
 * @brief Enables debug-specific code paths.
 *
 * Can be defined either directly in the source code or via the compiler
 * using -DDEBUG.
 */
#define DEBUG

/**
 * @def PLATFORM_LINUX
 * @brief Simulates building the program for a Linux platform.
 *
 * Only one platform macro should be defined at a time.
 */
#define PLATFORM_LINUX
// #define PLATFORM_WINDOWS
// #define PLATFORM_MACOS

/* ------------------------------------------- */

/**
 * @brief Entry point of the program.
 *
 * Prints messages based on compile-time flags to demonstrate how different
 * code paths are included or excluded during compilation.
 *
 * @return int Exit status (0 indicates successful execution)
 */
int main()
{
    std::cout << "Program started\n";

#ifdef DEBUG
    /// Debug-only code (compiled only when DEBUG is defined)
    std::cout << "DEBUG build enabled\n";
#endif

#ifdef PLATFORM_LINUX
    std::cout << "Running on Linux\n";
#elif defined(PLATFORM_WINDOWS)
    std::cout << "Running on Windows\n";
#elif defined(PLATFORM_MACOS)
    std::cout << "Running on macOS\n";
#else
    std::cout << "Unknown platform\n";
#endif

#if defined(DEBUG) && defined(PLATFORM_LINUX)
    /// Code compiled only for Linux debug builds
    std::cout << "Extra Linux debug diagnostics\n";
#endif

#ifndef DEBUG
    /// Compiled only in release builds
    std::cout << "Release build: debug code removed at compile time\n";
#endif

    return 0;
}
