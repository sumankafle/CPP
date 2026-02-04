/**
 * @file find_duplicate_number.cpp
 * @brief Find duplicate numbers in an array using two different approaches.
 *
 * This program demonstrates two methods to find a duplicate number
 * in an integer array:
 *
 * 1. Frequency counting using an auxiliary array
 * 2. Floyd’s Tortoise and Hare (Cycle Detection) algorithm
 *
 * Problem reference:
 * https://leetcode.com/problems/find-the-duplicate-number/
 *
 * Example:
 * Input:
 *  6
 *  1 2 2 5 3 3
 *
 * Output:
 *  2
 *  2
 *
 * @author Suman
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Program entry point
 *
 * Reads array input and finds a duplicate number using:
 * - Method 1: Frequency counting
 * - Method 2: Cycle detection (race pointers)
 *
 * @return int Exit status
 */
int main() {

#ifndef ONLINE_JUDGE
    /**
     * @brief Redirect input/output for local testing
     *
     * Reads input from ../input.txt
     * Writes output to ../output.txt
     */
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    long long N;           ///< Number of elements
    cin >> N;

    long long arr[N];      ///< Input array
    for (long long i = 0; i < N; i++) {
        cin >> arr[i];
    }

    /* ============================================================
     * Method 1: Frequency Counting
     * ============================================================
     */

    /**
     * @brief Finds duplicate using frequency array
     *
     * Counts occurrences of each number.
     * The first number whose frequency becomes 2 is the answer.
     *
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    bool found = false;
    long long answer = -1;

    long long count[100005] = {0}; ///< Frequency array

    for (long long i = 0; i < N; i++) {
        if (count[arr[i]] == 1) {
            found = true;
            answer = arr[i];
            break;
        }
        count[arr[i]]++;
    }

    cout << answer << endl;

    /* ============================================================
     * Method 2: Floyd’s Cycle Detection (Tortoise and Hare)
     * ============================================================
     */

    /**
     * @brief Finds duplicate using cycle detection
     *
     * Treats array values as pointers.
     * If a duplicate exists, a cycle will form.
     *
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    long long slow = arr[0]; ///< Slow pointer
    long long fast = arr[0]; ///< Fast pointer

    // Phase 1: Detect intersection point
    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    // Phase 2: Find entry point of cycle
    slow = arr[0];
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }

    cout << slow << endl;

    return 0;
}
