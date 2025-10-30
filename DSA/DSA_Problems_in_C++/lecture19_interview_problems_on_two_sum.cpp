// lecture 19 : Interview Problems on Two Sum

/*
Variation 1 : Count Pairs with Given Sum
Given a sorted array and a target sum, count the total number of 
distinct pairs whose sum equals the target.

Input:  arr = [1, 2, 2, 3, 4], target = 5  
Output: 2  
Explanation: Pairs are (1,4) and (2,3)

Time: O(n), just one pass with two pointers
Space: O(1), no extra storage
*/

#include <bits/stdc++.h>
using namespace std;

int countPairsWithSum(vector<int>& arr, int target) {
    int n = arr.size();
    int low = 0, high = n - 1;
    int count = 0;

    while (low < high) {
        int sum = arr[low] + arr[high];

        if (sum == target) {
            count++;  // Found a valid pair

            // Move low forward skipping duplicates
            int currentLow = arr[low];
            while (low < high && arr[low] == currentLow) low++;

            // Move high backward skipping duplicates
            int currentHigh = arr[high];
            while (low < high && arr[high] == currentHigh) high--;
        }
        else if (sum < target) {
            low++; // Need a bigger sum
        }
        else {
            high--; // Need a smaller sum
        }
    }
    return count;
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 4};
    int target = 5;

    cout << "Number of unique pairs: " << countPairsWithSum(arr, target) << endl;

    return 0;
}


/*
Variation 3 : Closest Pair Sum
Given a sorted array and a target sum, find the pair (a, b) whose sum is 
closest to the target. If there are multiple equally-close sums, you can return any one of them.
*/

#include <iostream>
#include <vector>
#include <cmath>   // for abs()
#include <climits>  // for INT_MAX
using namespace std;

pair<int, int> closestPairSum(vector<int>& arr, int target) {
    int low = 0;                     // Start pointer at beginning
    int high = arr.size() - 1;        // End pointer at last element
    
    int closestDiff = INT_MAX;        // Track smallest difference found so far
    pair<int, int> bestPair;          // Store the pair giving closest sum
    
    // Loop until pointers meet
    while (low < high) {
        int sum = arr[low] + arr[high];   // Current sum of the two elements
        int diff = abs(sum - target);     // Absolute difference from target
        
        // If this sum is closer than any before, update best
        if (diff < closestDiff) {
            closestDiff = diff;           // Update smallest difference
            bestPair = {arr[low], arr[high]}; // Store current pair
        }
        
        // Two-pointer movement logic:
        // If sum is smaller than target → move low up to increase sum
        if (sum < target) {
            low++;
        }
        // If sum is larger than target → move high down to decrease sum
        else if (sum > target) {
            high--;
        }
        // If sum equals target → it's the closest possible (diff=0), break early
        else {
            break;
        }
    }
    
    return bestPair;
}

int main() {
    vector<int> arr = {1, 3, 4, 7, 10};   // Sorted input array
    int target = 15;                      // Target sum we want to get close to
    
    pair<int, int> result = closestPairSum(arr, target);
    cout << "Closest Pair: (" << result.first << ", " << result.second << ")\n";
    
    return 0;
}


// Output : Closest Pair: (4, 10)

/*
Variation 4 : k-Sum Reduction (3-Sum as Extension)
We’ve mastered two pointers for finding pairs.
Now, what if the interviewer says :

“Instead of finding two numbers with a given sum, find three numbers whose sum equals a target.”

This is the 3-Sum problem. It’s not as scary as it sounds, we just wrap our two-pointer logic inside another loop.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& arr, int target) {
    vector<vector<int>> result;

    // Step 1: Sort array
    sort(arr.begin(), arr.end());

    // Step 2: Loop for first element
    for (int i = 0; i < (int)arr.size() - 2; i++) {

        // Skip duplicates for first element
        if (i > 0 && arr[i] == arr[i - 1]) continue;

        int low = i + 1;
        int high = arr.size() - 1;

        while (low < high) {
            int sum = arr[i] + arr[low] + arr[high];

            if (sum == target) {
                result.push_back({arr[i], arr[low], arr[high]});

                // Skip duplicates for second number
                int currentLow = arr[low];
                while (low < high && arr[low] == currentLow) low++;

                // Skip duplicates for third number
                int currentHigh = arr[high];
                while (low < high && arr[high] == currentHigh) high--;
            }
            else if (sum < target) {
                low++; // Need a bigger sum
            }
            else {
                high--; // Need a smaller sum
            }
        }
    }

    return result;
}

int main() {
    vector<int> arr = {-4, -1, -1, 0, 1, 2};
    int target = 0;

    vector<vector<int>> triplets = threeSum(arr, target);

    cout << "Triplets with sum = " << target << ":\n";
    for (auto &t : triplets) {
        cout << "[" << t[0] << ", " << t[1] << ", " << t[2] << "]\n";
    }
}


// Output:

// Triplets with sum = 0:
// [-1, -1, 2]
// [-1, 0, 1]