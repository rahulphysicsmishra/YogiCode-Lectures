/*
Problem: Move All Zeros to the End of the Array

Given an array of integers, move all the zeros to the end while maintaining 
the relative order of the non-zero elements. Do it in-place without using 
extra arrays if possible.

Input: [0, 1, 0, 3, 12]

Output: [1, 3, 12, 0, 0]

*/


// Brute force Approach: Using Extra Space
// Time Complexity: O(n), Space Complexity: O(n)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {0, 1, 0, 3, 12};

    // Step 1: Create a new array to store result
    vector<int> result;

    // Step 2: Add all non-zero elements to result
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) {
            result.push_back(arr[i]);  // Keep only non-zero elements
        }
    }

    // Step 3: Count how many zeros were in original array
    int zeros = arr.size() - result.size();

    // Step 4: Add that many zeros to the end of result
    for (int i = 0; i < zeros; i++) {
        result.push_back(0);
    }

    // Step 5: Print final result
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}


// Optimal Approach: In-place, No Extra Space
// Time Complexity: O(n), Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {0, 1, 0, 3, 12};

    int pos = 0; // Step 1: This marks where the next non-zero will go

    // Step 2: Go through the array
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) {
            arr[pos] = arr[i]; // Step 3: Move non-zero to the front
            pos++;             // Step 4: Move the pointer forward
        }
    }

    // Step 5: After all non-zeros, fill the rest with 0
    while (pos < arr.size()) {
        arr[pos] = 0;
        pos++;
    }

    // Step 6: Print final array
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}