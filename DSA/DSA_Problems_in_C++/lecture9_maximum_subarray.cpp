// lecture 9 : maximum subarray with kadane’s trick

/*
Problem: Maximum Subarray Sum
Given an integer array nums, find the contiguous subarray 
(containing at least one number) which has the largest sum, 
and return its sum.
*/

// Brute Force Approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = nums.size();
    int maxSum = INT_MIN;

    // Try every possible subarray
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j]; // Add current element to sum
            maxSum = max(maxSum, sum); // Update maxSum if needed
        }
    }

    cout << "Maximum Subarray Sum: " << maxSum << endl;
    return 0;
}

// Optimal Approach: Kadane's Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int currentSum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < nums.size(); i++) {
        currentSum += nums[i];           // Add current element
        maxSum = max(maxSum, currentSum); // Update max sum
        if (currentSum < 0) currentSum = 0; // Reset if negative
    }

    cout << "Maximum Subarray Sum: " << maxSum << endl;
    return 0;
}



