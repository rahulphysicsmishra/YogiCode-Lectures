// lecture 7 : mastering prefix sum

// Problem: Find the Sum of Elements in a Given Range
/*
You are given an array of integers and several queries. Each query 
consists of two indices L and R, and you must return the sum of 
elements from index L to R (inclusive).

Input:
arr = [2, 4, 1, 3, 5]
queries = [(0, 2), (1, 3), (0, 4)]

Output:
7   (2 + 4 + 1)
8   (4 + 1 + 3)
15  (2 + 4 + 1 + 3 + 5)
*/

// Brute Force Approach(space)
// time complexity: O(n) for each query
// space complexity: O(1)


#include <iostream>
#include <vector>
using namespace std;

int rangeSumBrute(const vector<int>& arr, int L, int R) {
    int sum = 0;
    for (int i = L; i <= R; i++) { // Looping over L to R to sum elements
        sum += arr[i];
    }
    return sum;
}

int main() {
    vector<int> arr = {2, 4, 1, 3, 5};
    vector<pair<int, int>> queries = {{0, 2}, {1, 3}, {0, 4}};
    
    for (auto q : queries) {
        cout << rangeSumBrute(arr, q.first, q.second) << endl;
    }
    return 0;
}


// Optimal Approach: Prefix Sum
// Time Complexity: O(n) for preprocessing, O(1) for each query
// Space Complexity: O(n) for prefix sum array

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {2, 4, 1, 3, 5};
    int n = arr.size();

    // --- Step 1: Build prefix sum array ---
    vector<int> prefix(n);
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    // Now, prefix[] = [2, 6, 7, 10, 15]
    // Meaning:
    // prefix[0] = 2
    // prefix[1] = 2 + 4 = 6
    // prefix[2] = 2 + 4 + 1 = 7
    // and so on...

    // --- Step 2: Answer multiple queries in O(1) time ---
    vector<pair<int, int>> queries = {{0, 2}, {1, 3}, {0, 4}};

    for (auto q : queries) {
        int L = q.first;
        int R = q.second;

        int sum;
        if (L == 0)
            sum = prefix[R];             // Sum from 0 to R
        else
            sum = prefix[R] - prefix[L - 1]; // Sum from L to R

        cout << "Sum from " << L << " to " << R << " = " << sum << endl;
    }

    return 0;
}

