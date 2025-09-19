// Problem 1 :  Function to find the maximum value in an array


#include <iostream>
#include <vector>
using namespace std;

int findMax(const vector<int>& arr) {
    if (arr.empty()) return -1; // Handle empty array case

    int maxElement = arr[0]; // Assume first is max

    for (int num : arr) {
        if (num > maxElement) {
            maxElement = num; // Update if we find a bigger one
        }
    }

    return maxElement;
}

int main() {
    vector<int> arr = {10, 25, 3, 56, 89, 2};
    cout << findMax(arr) << endl; // Output: 89
}


// Problem 2 :  Function to perform binary search
// Given a sorted array of integers and a target value, find its index.
// If the target is not found, return -1.

int binarySearch(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Prevent overflow

        if (arr[mid] == target)
            return mid; // Found

        else if (arr[mid] < target)
            low = mid + 1; // Go right

        else
            high = mid - 1; // Go left
    }

    return -1; // Not found
}

