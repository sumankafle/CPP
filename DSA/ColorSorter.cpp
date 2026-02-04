#include <bits/stdc++.h>
using namespace std;

/*
    OOP version of "Sort Colors" problem (LeetCode)
    Author: Suman Kafle
    Date: 2026-02-03

    Input Example:
    6
    1 0 2 0 1 2

    Output:
    0 0 1 1 2 2
    0 0 1 1 2 2
*/

class ColorSorter {
private:
    vector<long long> arr;

    // Swap utility
    void swap(long long &a, long long &b) {
        long long temp = a;
        a = b;
        b = temp;
    }

public:
    // Constructor to initialize array
    ColorSorter(const vector<long long> &input) : arr(input) {}

    // Method 1: Dutch National Flag Algorithm
    void sortColorsDNF() {
        long long r0 = 0, l2 = arr.size() - 1, curr = 0;
        while (curr <= l2) {
            if (arr[curr] == 0) {
                swap(arr[r0], arr[curr]);
                r0++;
                curr++;
            }
            else if (arr[curr] == 2) {
                swap(arr[l2], arr[curr]);
                l2--;
            }
            else {
                curr++;
            }
        }
    }

    // Method 2: Counting sort like approach
    void sortColorsSimple() {
        long long x = -1;
        for (long long y = 0; y < arr.size(); y++) {
            if (arr[y] == 0) swap(arr[++x], arr[y]);
        }
        long long z = x;
        for (long long y = x + 1; y < arr.size(); y++) {
            if (arr[y] == 1) swap(arr[++z], arr[y]);
        }
    }

    // Print the array
    void printArray() const {
        for (auto num : arr) cout << num << " ";
        cout << endl;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    long long N;
    cin >> N;

    if (N <= 0 || N > 1e7) { // limit to reasonable size
    cerr << "Invalid array size!" << endl;
    return 1;
}   

    vector<long long> inputArr(N);
    for (long long i = 0; i < N; i++) cin >> inputArr[i];

    ColorSorter sorter(inputArr);

    // Using Method 1
    sorter.sortColorsDNF();
    sorter.printArray();

    // Using Method 2
    sorter.sortColorsSimple();
    sorter.printArray();

    return 0;
}
