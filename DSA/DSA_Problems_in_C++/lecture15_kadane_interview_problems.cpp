// lecture 15 : Kadane's Algorithm and Interview Problems

/*
Variation 1: Return the Subarray, Not Just the Sum
Problem: You’re given an array of integers (positive, negative, zero). 
Find the contiguous subarray (one piece, no skips) with the maximum sum 
and return the actual subarray, not just the total.

Example:
Array:        [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Task:         Pick a slice (contiguous) with max total sum
Goal:         Return the subarray → [4, -1, 2, 1]
Output:       Max sum = 6
              Subarray = [4, -1, 2, 1]

// Step-by-step over array:

Start:

i = 0 → -2 → start a new subarray → tempStart = 0
i = 1 → 1 > -2+1 → better to start fresh → tempStart = 1
i = 2 → -3 → keep going (sum = -2) → not better
i = 3 → 4 → restart from here → tempStart = 3
i = 4 → -1 → 4 + (-1) = 3 → keep going
i = 5 → +2 → 3 + 2 = 5 → good
i = 6 → +1 → 5 + 1 = 6 → best so far → update start = 3, end = 6
...
*/


/*
Variation 2: Maximum Sum in a Circular Subarray
Problem : You are given a circular array of integers (first and last elements are connected like a ring). 
Find the maximum sum of any contiguous subarray, which can wrap around the end.

Example:

Array:      [5, -3, 5]
Index:        0   1   2

Normal max subarray = [5] = 5
But wait... circular allows:
Wrap-around subarray = [5, _, 5] = 10
Skip -3, include both 5s = 5 + 5 = 10 ✅

Output: 10

// Step-by-step over array:

// Step 1: Normal Kadane
maxSum = 5 (at index 0)
→ add -3 → becomes 2 → keep
→ add +5 → becomes 7 → update max

// Step 2: Min Subarray
Track minimum contiguous subarray
→ Here it’s [-3]

// Step 3: Total Sum = 7
→ max of (normalKadane = 7, wrapKadane = 10)

// Step 4: Final answer = 10
*/


/*
Variation 3: Maximum Product Subarray
Problem:You’re given an array of integers (including negatives and zeros). 
Find the contiguous subarray with the maximum product.

Example:
Array: [2, 3, -2, 4]

Possible Products:
[2, 3]       → 6
[2, 3, -2]   → -12
..
[3, -2, 4]   → -24
[-2, 4]      → -8

But... maximum = 6 ✅

// Step-by-step over array:
Start:
  curr = 2 → max = 2, min = 2

Next = 3:
  max = max(3, 2×3, 2×3) = 6 ✅
  min = min(3, 2×3, 2×3) = 3

Next = -2:
  max = max(-2, 6×-2, 3×-2) = max(-2, -12, -6) = -2
  min = min(-2, 6×-2, 3×-2) = -12

Next = 4:
  max = max(4, -2×4, -12×4) = max(4, -8, -48) = 4
  min = min(4, -8, -48) = -48

Track highest max → answer = 6 ✅
*/


/*
Variation 4: Max Subarray Sum of Size K (Fixed Sliding Window)
Given an array and a number K, return the maximum sum of any subarray of 
exactly size K.

Example:

Array:   [2, 1, 5, 1, 3, 2]
K = 3

Windows:
[2,1,5] → sum = 8 ✅
[1,5,1] → sum = 7
[5,1,3] → sum = 9 ✅
[1,3,2] → sum = 6

Max = 9 ✅

// Step-by-step over array:

Start → sum = arr[0] + arr[1] + arr[2] = 8
Slide → subtract arr[0], add arr[3] → sum = 7
Continue sliding...

Always track the max.

Sliding window steps:

Start: [2, 1, 5] = 8 ✅
Next: [1, 5, 1] → 8 - 2 + 1 = 7
Next: [5, 1, 3] → 7 - 1 + 3 = 9 ✅
Next: [1, 3, 2] → 9 - 5 + 2 = 6

Max sum found = 9 ✅
*/


/*
Variation 5: Maximum Sum of Two Non-Overlapping Subarrays
Given an array, find two non-overlapping subarrays (with given lengths L and M) 
whose sum is maximum.

Example:

Array:   [0, 6, 5, 2, 2, 5, 1, 9, 4]
L = 1, M = 2

Choices:
[9] and [6,5] → sum = 9 + 11 = 20 ✅
[6] and [9,4] → sum = 6 + 13 = 19

Best non-overlapping = 20 ✅

// Step-by-step over array:

// Compute prefix sum
prefix[i] = prefix[i-1] + arr[i]

// For each i:
- Fix L-subarray ending at i
- Find best M-subarray before i (non-overlapping)
- Track max sum of both

Repeat with L and M swapped.

*/