"""
Problem Statement: Trapping Rain Water
You are given an array of non-negative integers where each element represents the 
height of a vertical bar. The bars are placed side by side, and together they form 
a landscape.

When it rains, water gets trapped between taller bars, forming small “pits.” Your 
task is to calculate the total amount of water trapped.

Example:
Input:

arr = [0,1,0,2,1,0,1,3,2,1,2,1]

Output:

6

"""



# Brute Force Code
# Time Complexity: O(n^2), because for each bar we look left and right
# Space Complexity: O(1), we only use a few variables

def rain_trap_bruteforce(heights):
    # Edge case: if array is empty or too small, no water can be trapped
    if not heights or len(heights) < 3:
        return 0

    n = len(heights)
    water = 0  # total water trapped

    # Step 1: Traverse each bar in the array
    for i in range(n):
        # Step 2: For current bar 'i', find the tallest bar on its left
        left_max = max(heights[:i+1])

        # Step 3: Find the tallest bar on its right
        right_max = max(heights[i:])

        # Step 4: Water above current bar depends on the shorter of left & right walls
        trapped = min(left_max, right_max) - heights[i]

        # Step 5: Only add if trapped water is positive
        if trapped > 0:
            water += trapped

    return water


# ---------------- DEMO TEST CASES ----------------

# Case 1: Classic example
arr1 = [0,1,0,2,1,0,1,3,2,1,2,1]
print("Total water trapped (Brute Force):", rain_trap_bruteforce(arr1))
# Expected: 6

# Case 2: No pits → no water
arr2 = [3, 2, 1, 0]
print("Total water trapped (Brute Force):", rain_trap_bruteforce(arr2))
# Expected: 0

# Case 3: All bars same height → no water
arr3 = [4, 4, 4, 4]
print("Total water trapped (Brute Force):", rain_trap_bruteforce(arr3))
# Expected: 0

# Case 4: Small array (cannot trap water)
arr4 = [2, 1]
print("Total water trapped (Brute Force):", rain_trap_bruteforce(arr4))
# Expected: 0




# Prefix & Suffix Arrays Approach
# O(n) Time & O(n) Space


# Trapping Rain Water - Prefix & Suffix Arrays (Optimized O(n) approach)
# --------------------------------------------------------------------
# Idea:
#  - For each bar i, water trapped above it depends on the tallest bar to its left
#    and the tallest bar to its right: trapped_i = min(left_max[i], right_max[i]) - height[i]
#  - Precompute left_max[] and right_max[] in two passes so we can compute trapped water
#    for every index in a single final pass.
#
# Time Complexity: O(n)    (three linear passes over the array)
# Space Complexity: O(n)   (two extra arrays: left_max and right_max)

def rain_trap_prefix_suffix(heights):
    # Edge cases: empty or too small -> no water
    if not heights or len(heights) < 3:
        return 0

    n = len(heights)

    # left_max[i] will hold the max height from index 0..i
    left_max = [0] * n
    left_max[0] = heights[0]
    for i in range(1, n):
        # the tallest to the left of i is either the previous tallest or current height
        left_max[i] = max(left_max[i - 1], heights[i])

    # right_max[i] will hold the max height from index i..n-1
    right_max = [0] * n
    right_max[n - 1] = heights[n - 1]
    for i in range(n - 2, -1, -1):
        # the tallest to the right of i is either the next tallest or current height
        right_max[i] = max(right_max[i + 1], heights[i])

    # Now compute trapped water using left_max and right_max
    water = 0
    for i in range(n):
        # water that can sit on top of bar i is limited by the shorter side
        trapped = min(left_max[i], right_max[i]) - heights[i]
        # only add positive trapped amounts
        if trapped > 0:
            water += trapped

    return water


# ---------------- DEMO TEST CASES ----------------

arr1 = [0,1,0,2,1,0,1,3,2,1,2,1]
print("Total water trapped (Prefix/Suffix):", rain_trap_prefix_suffix(arr1))  # Expected: 6

arr2 = [3, 2, 1, 0]
print("Total water trapped (Prefix/Suffix):", rain_trap_prefix_suffix(arr2))  # Expected: 0

arr3 = [4, 4, 4, 4]
print("Total water trapped (Prefix/Suffix):", rain_trap_prefix_suffix(arr3))  # Expected: 0

arr4 = [2,0,2]
print("Total water trapped (Prefix/Suffix):", rain_trap_prefix_suffix(arr4))  # Expected: 2



# Two-Pointer Approach
# Time Complexity: O(n)
# Space Complexity: O(1)

# Trapping Rain Water - Two Pointer Approach (Optimal)
# ----------------------------------------------------
# Idea:
#   - Instead of building extra arrays, we can trap water on the fly
#     by using two pointers (left and right) moving inward.
#   - We keep track of the tallest bar seen so far from the left (left_max)
#     and from the right (right_max).
#   - At each step:
#       -> Compare heights[left] and heights[right].
#       -> The smaller side limits how much water can be trapped.
#       -> Move that pointer inward and calculate trapped water there.
#
# Time Complexity: O(n)   (one pass through the array)
# Space Complexity: O(1)  (only a few variables)

def rain_trap_two_pointer(heights):
    # Edge case: small array cannot trap water
    if not heights or len(heights) < 3:
        return 0

    left, right = 0, len(heights) - 1   # two pointers at both ends
    left_max, right_max = 0, 0          # track tallest walls seen so far
    water = 0                           # total water trapped

    # Process until pointers meet
    while left <= right:
        # If left side is shorter, handle left pointer
        if heights[left] <= heights[right]:
            if heights[left] >= left_max:
                # update left_max if we found a taller bar
                left_max = heights[left]
            else:
                # current bar is shorter -> water can be trapped here
                water += left_max - heights[left]
            left += 1  # move left pointer inward
        else:
            # If right side is shorter, handle right pointer
            if heights[right] >= right_max:
                # update right_max if we found a taller bar
                right_max = heights[right]
            else:
                # current bar is shorter -> water can be trapped here
                water += right_max - heights[right]
            right -= 1  # move right pointer inward

    return water


# ---------------- DEMO TEST CASES ----------------

arr1 = [0,1,0,2,1,0,1,3,2,1,2,1]
print("Total water trapped (Two Pointers):", rain_trap_two_pointer(arr1))
# Expected: 6

arr2 = [3, 2, 1, 0]
print("Total water trapped (Two Pointers):", rain_trap_two_pointer(arr2))
# Expected: 0

arr3 = [4, 4, 4, 4]
print("Total water trapped (Two Pointers):", rain_trap_two_pointer(arr3))
# Expected: 0

arr4 = [2,0,2]
print("Total water trapped (Two Pointers):", rain_trap_two_pointer(arr4))
# Expected: 2