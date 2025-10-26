// lecture 14 : secret to fast range update problem

/*  
Problem: Range Increment Updates
You are given an array of size n initialized with all 0s.

You are also given q update operations. Each operation is in the form:
[l, r, val]

You need to add val to every index from l to r (inclusive).

After all operations, return the final state of the array.

Example:
Input:

n = 8  
operations = [
  {2, 4, 5},   // add 5 to index 2 to 4
  {5, 7, 3},   // add 3 to index 5 to 7
  {0, 1, 2}    // add 2 to index 0 to 1
]

Output: [2, 2, 5, 5, 5, 3, 3, 3]
*/

// Smart approach using Difference Array
// Time Complexity: O(n + q)

#include <iostream>
#include <vector>
using namespace std;

vector<int> applyRangeUpdates(int n, vector<vector<int>>& operations) {
    vector<int> diff(n + 1, 0); // difference array of size n+1

    // Step 1: Apply all updates in diff array
    for (auto& op : operations) {
        int l = op[0];
        int r = op[1];
        int val = op[2];

        diff[l] += val;          // start adding val from index l
        if (r + 1 < n) {
            diff[r + 1] -= val;  // stop adding after index r
        }
    }

    // Step 2: Build final array by taking prefix sum
    vector<int> result(n, 0);
    result[0] = diff[0];
    for (int i = 1; i < n; ++i) {
        result[i] = result[i - 1] + diff[i];
    }

    return result;
}

int main() {
    int n = 8;
    vector<vector<int>> operations = {
        {2, 4, 5},
        {5, 7, 3},
        {0, 1, 2}
    };

    vector<int> result = applyRangeUpdates(n, operations);

    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}