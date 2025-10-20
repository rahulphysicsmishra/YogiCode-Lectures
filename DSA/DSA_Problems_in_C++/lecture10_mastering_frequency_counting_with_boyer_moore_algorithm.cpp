// lecture 10 : mastering frequency counting with boyer-moore algorithm

/*
Find the Element That Appears More Than n/2 Times
Example :
Input:  nums = [2, 2, 1, 1, 1, 2, 2]
Output: 2
*/

// Brute Force Approach
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> freq;
    int n = nums.size();
    
    for (int num : nums) {
        freq[num]++;
        if (freq[num] > n / 2) {
            return num;
        }
    }

    return -1; // Problem states majority always exists
}

// Efficient Approach: Boyer-Moore Voting Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int count = 0;
    int candidate = 0;

    for (int num : nums) {
        if (count == 0) {
            candidate = num; // Reset candidate
        }

        // Increment or decrement count
        count += (num == candidate) ? 1 : -1;
    }

    return candidate;
}

// Test the function
int main() {
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};

    cout << "Input array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    int result = majorityElement(arr);

    cout << "Majority Element: " << result << endl;

    return 0;
}

