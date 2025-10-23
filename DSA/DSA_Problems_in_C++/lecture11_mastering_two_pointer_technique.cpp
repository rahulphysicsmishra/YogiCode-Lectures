// lecture 11 : mastering two pointer technique

/*
Problem : Pair With Target Sum
Given a sorted array and a target sum, determine if there are two numbers in the array whose sum equals the target.

Example:

Input:  arr = [1, 2, 3, 4, 6], target = 7  
Output: true  
// Explanation: 3 + 4 = 7

*/

// Brute Force Approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

bool hasPairWithSum(vector<int>& arr, int target) {
    int n = arr.size();

    // Check every possible pair in the array
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            // Print the current pair we're checking (for explanation)
            cout << "Checking pair: (" << arr[i] << ", " << arr[j] << ")";

            // Check if their sum matches the target
            if (arr[i] + arr[j] == target) {
                cout << " => Found a match!" << endl;
                return true;
            } else {
                cout << " => No match." << endl;
            }
        }
    }

    // If no pair found after checking all combinations
    return false;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 6};
    int target = 7;

    if (hasPairWithSum(arr, target)) {
        cout << "Yes, a pair exists that sums to " << target << "." << endl;
    } else {
        cout << "No, no such pair exists." << endl;
    }

    return 0;
}

// Efficient Approach: Two Pointer Technique
// Time Complexity: O(n)
// Space Complexity: O(1)   

#include <iostream>
#include <vector>
using namespace std;

bool hasPairWithSum(vector<int>& arr, int target) {
    int left = 0;                   // Start from the beginning
    int right = arr.size() - 1;     // Start from the end

    while (left < right) {
        int sum = arr[left] + arr[right];

        // Show the pair we're checking
        cout << "Checking: " << arr[left] << " + " << arr[right] << " = " << sum << endl;

        if (sum == target) {
            cout << "✅ Found a pair: " << arr[left] << " + " << arr[right] << " = " << target << endl;
            return true;
        }
        else if (sum < target) {
            // Sum too small → move left to a bigger number
            left++;
        }
        else {
            // Sum too big → move right to a smaller number
            right--;
        }
    }

    // If no such pair found
    return false;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 6};
    int target = 7;

    if (hasPairWithSum(arr, target)) {
        cout << "Yes, a pair exists!" << endl;
    } else {
        cout << "No pair found." << endl;
    }

    return 0;
}