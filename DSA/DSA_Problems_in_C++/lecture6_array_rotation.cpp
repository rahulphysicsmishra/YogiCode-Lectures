/*

Understanding Array Rotation, Left Rotation by D Positions

You are given an array and a number d. You need to rotate the array 
to the left by d positions.

Example:

Input: arr = [1, 2, 3, 4, 5], d = 2  
Output: [3, 4, 5, 1, 2]

*/


// Brute force Approach: Using Extra Space
// Time Complexity: O(n), Space Complexity: O(n)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    int d = 2; // Rotate by 2 positions

    // Step 1: Create a temporary array for first d elements
    vector<int> temp;
    for (int i = 0; i < d; i++) {
        temp.push_back(arr[i]); // Copy first 2 elements
    }

    // Step 2: Shift the remaining elements to the left
    for (int i = d; i < n; i++) {
        arr[i - d] = arr[i]; // Move elements forward
    }

    // Step 3: Copy temp elements to the end
    for (int i = 0; i < d; i++) {
        arr[n - d + i] = temp[i]; // Place saved elements at end
    }

    // Step 4: Print rotated array
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}


// Optimal Approach: In-place, No Extra Space
// Time Complexity: O(n), Space Complexity: O(1)


#include <iostream>
#include <vector>
#include <algorithm> // for std::reverse
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    int d = 2; 
    d = d % n; // Important: if d > n, we only need d % n rotations

    // --- Step 1: Reverse the first d elements ---
    // This will reverse [1, 2] → [2, 1]
    reverse(arr.begin(), arr.begin() + d);
    // Expected array now: [2, 1, 3, 4, 5]

    // --- Step 2: Reverse the remaining n-d elements ---
    // This will reverse [3, 4, 5] → [5, 4, 3]
    reverse(arr.begin() + d, arr.end());
    // Expected array now: [2, 1, 5, 4, 3]

    // --- Step 3: Reverse the entire array ---
    // This will reverse [2, 1, 5, 4, 3] → [3, 4, 5, 1, 2]
    reverse(arr.begin(), arr.end());
    // Final rotated array: [3, 4, 5, 1, 2]

    // --- Step 4: Print the result ---
    cout << "Rotated Array: ";
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}