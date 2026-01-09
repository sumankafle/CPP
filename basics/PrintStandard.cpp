/**
 * @file cpp_standard.cpp
 * @brief Prints the C++ language standard currently used by the compiler.
 *
 * This program determines the active C++ language standard by inspecting
 * predefined compiler macros such as `__cplusplus` or `_MSVC_LANG` and
 * maps the result to a human-readable C++ standard name.
 *
 * Freely redistributable, courtesy of learncpp.com:
 * https://www.learncpp.com/cpp-tutorial/what-language-standard-is-my-compiler-using/
 *
 * @author suman
 * @date 2025/08/08
 */

#include <iostream>

/// Total number of supported (and preview) C++ standards
const int numStandards = 7;

/**
 * @brief Numeric language standard codes defined by the C++ standard.
 *
 * The C++26 value is a placeholder, as the final value will only be known
 * once the standard is officially finalized.
 */
const long stdCode[numStandards] = {
    199711L,  // Pre-C++11
    201103L,  // C++11
    201402L,  // C++14
    201703L,  // C++17
    202002L,  // C++20
    202302L,  // C++23
    202612L   // C++26 (placeholder)
};

/// Human-readable names corresponding to each C++ standard code
const char* stdName[numStandards] = {
    "Pre-C++11",
    "C++11",
    "C++14",
    "C++17",
    "C++20",
    "C++23",
    "C++26"
};

/**
 * @brief Detects the C++ language standard used by the compiler.
 *
 * Uses compiler-specific macros to determine the active language standard:
 * - `_MSVC_LANG` for modern Visual Studio versions
 * - `__cplusplus` for standard-conforming compilers
 *
 * @return Language standard code (e.g., 201703L for C++17),
 *         or `-1` if the standard cannot be determined.
 *
 * @note Older versions of Microsoft Visual C++ may not correctly report
 *       `__cplusplus` without additional compiler flags.
 */
long getCPPStandard()
{
#if defined (_MSVC_LANG)
    // Correct standard macro for modern MSVC
    return _MSVC_LANG;
#elif defined (_MSC_VER)
    // Older MSVC versions are non-conforming
    return -1;
#else
    // Standard-compliant way of querying the C++ language version
    return __cplusplus;
#endif
}

/**
 * @brief Program entry point.
 *
 * Determines the compiler's C++ language standard and prints a descriptive
 * message indicating whether the compiler uses a finalized or preview
 * version of the standard.
 *
 * @return Exit status code (always 0).
 */
int main()
{
    long standard = getCPPStandard();

    if (standard == -1)
    {
        std::cout << "Error: Unable to determine your language standard. Sorry.\n";
        return 0;
    }

    for (int i = 0; i < numStandards; ++i)
    {
        // Exact match with a finalized C++ standard
        if (standard == stdCode[i])
        {
            std::cout << "Your compiler is using " << stdName[i]
                      << " (language standard code " << standard << "L)\n";
            break;
        }

        // Preview or experimental support between two standards
        if (standard < stdCode[i])
        {
            std::cout << "Your compiler is using a preview/pre-release of "
                      << stdName[i]
                      << " (language standard code " << standard << "L)\n";
            break;
        }
    }

    return 0;
}
