#include <iostream>

/* -------- Compile-time configuration -------- */

// Toggle build type
// Uncomment OR pass -DDEBUG to compiler
#define DEBUG

// Platform simulation
#define PLATFORM_LINUX
// #define PLATFORM_WINDOWS
// #define PLATFORM_MACOS

/* ------------------------------------------- */

int main() {
    std::cout << "Program started\n";

#ifdef DEBUG
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
    std::cout << "Extra Linux debug diagnostics\n";
#endif

#ifndef DEBUG
    std::cout << "Release build: debug code removed at compile time\n";
#endif

    return 0;
}
