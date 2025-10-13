// lecture 8 : sliding window technique

/*
Problem: Maximum Sum of K Consecutive Elements
Given an array of integers and an integer k, find the maximum sum of any 
subarray of size k.
*/

// Brute Force Approach
// Time Complexity: O(n*k)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3; // Subarray size
    int n = arr.size();
    int maxSum = 0;

    // --- Outer loop: go through each possible starting point of subarray of size k ---
    // It runs from index 0 to (n - k)
    for (int i = 0; i <= n - k; i++) {
        int currentSum = 0;

        // --- Inner loop: calculate the sum of subarray starting at index i ---
        for (int j = i; j < i + k; j++) {
            currentSum += arr[j];
        }

        // --- Update maxSum if the current sum is greater ---
        maxSum = max(maxSum, currentSum);
    }

    cout << "Maximum sum of subarray of size " << k << " is: " << maxSum << endl;
    return 0;
}

// Optimal Approach: Sliding Window Technique
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3; // Size of subarray
    int n = arr.size();

    int windowSum = 0;
    int maxSum = 0;

    // --- Step 1: Compute the sum of the first window of size k ---
    for (int i = 0; i < k; i++) {
        windowSum += arr[i]; // Add first k elements
    }

    maxSum = windowSum; // Initialize maxSum with first window sum

    // --- Step 2: Slide the window ---
    // Start from index k, and go till end of array
    for (int i = k; i < n; i++) {
        // Slide the window forward:
        // Subtract the element going out of the window (i - k)
        // Add the new element coming into the window (i)
        windowSum = windowSum - arr[i - k] + arr[i];

        // Update maxSum if needed
        maxSum = max(maxSum, windowSum);
    }

    // --- Step 3: Print the result ---
    cout << "Maximum sum of subarray of size " << k << " is: " << maxSum << endl;

    return 0;
}