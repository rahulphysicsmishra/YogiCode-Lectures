"""
Problem Statement: You are given an array of integers. An equilibrium index is an 
index i such that the sum of elements on the left of i is equal to the sum of elements 
on the right of i. You need to find the first such index (if it exists). 
If no equilibrium index exists, return -1.

 Input:

arr = [1, 3, 5, 2, 2]

Output : 2

Explanation:

Left of index 2 → [1, 3] = 4

Right of index 2 → [2, 2] = 4

Both sides are equal → equilibrium index = 2.
"""

# Brute Force Code (with detailed comments)
# Time Complexity: O(n^2), because we check all elements for each index
# Space Complexity: O(1), we only use a few variables

# An equilibrium index is a position where
# the sum of numbers on the LEFT side == the sum of numbers on the RIGHT side.


def equilibrium(arr):
    # Loop through every index in the array
    for i in range(len(arr)):
        # Step 1: Take all elements to the LEFT of current index (i.e., before i)
        left_sum = sum(arr[:i])  # Example: if i = 2 → arr[:2] = [first, second]

        # Step 2: Take all elements to the RIGHT of current index (i.e., after i)
        right_sum = sum(arr[i+1:])  # Example: if i = 2 → arr[3:] = [fourth, fifth...]

        # Step 3: Compare left and right
        if left_sum == right_sum:
            # If they match, we found our equilibrium index
            return i

    # If no index satisfies the condition, return -1 (means "not found")
    return -1


# ------------------- DEMO -------------------

arr = [1, 3, 5, 2, 2]
print("Equilibrium index is:", equilibrium(arr))

# Explanation:
# At index 2 (value = 5):
# Left side = [1, 3] → sum = 4
# Right side = [2, 2] → sum = 4
# Both are equal → Answer = 2



# Optimized Approach 1: Using a Prefix Sum Array

# Time Complexity: O(n)
# Space Complexity: O(n)

# --------------------------------------------------
# Idea:
#   - Precompute a prefix sum array, where prefix_arr[i] = sum of arr[0..i].
#   - For each index j:
#       left_sum  = prefix_arr[j-1] (sum before index j)
#       right_sum = prefix_arr[n-1] - prefix_arr[j] (total sum - sum up to j)
#   - If left_sum == right_sum → j is an equilibrium index.
#   - Return the first equilibrium index, else -1.

def equilibrium_prefix(arr):
    # Handle edge case: empty array
    if not arr:
        return -1

    n = len(arr)

    # Step 1: Build prefix sum array
    prefix_arr = [0] * n
    prefix_arr[0] = arr[0]
    for i in range(1, n):
        prefix_arr[i] = prefix_arr[i-1] + arr[i]

    # Step 2: Check each index
    for j in range(n):
        # Left sum = sum of all elements before index j
        left_sum = prefix_arr[j-1] if j > 0 else 0

        # Right sum = total sum - sum up to index j
        right_sum = prefix_arr[n-1] - prefix_arr[j]

        if left_sum == right_sum:
            return j  # Found equilibrium index

    return -1  # If no equilibrium index found


# ------------------- DEMO -------------------
arr = [1, 3, 5, 2, 2]
print("Equilibrium index (Prefix Sum):", equilibrium_prefix(arr))
# Expected: 2



# Optimized Approach 2: Space Efficient (No Prefix Array)
# --------------------------------------------------
# Idea:
#   - Compute total sum of array once.
#   - Traverse array while keeping a running left_sum.
#   - For each index i:
#       right_sum = total_sum - left_sum - arr[i]
#   - If left_sum == right_sum → i is equilibrium index.
#   - Update left_sum for next iteration.
#   - Return first equilibrium index, else -1.

def equilibrium_space_efficient(arr):
    # Handle edge case: empty array
    if not arr:
        return -1

    total_sum = sum(arr)   # Total sum of array
    left_sum = 0           # Start with nothing on the left

    for i, val in enumerate(arr):
        # Right sum = total sum - left sum - current value
        right_sum = total_sum - left_sum - val

        if left_sum == right_sum:
            return i  # Found equilibrium index

        # Update left_sum before moving to next index
        left_sum += val

    return -1  # If no equilibrium index found


# ------------------- DEMO -------------------
arr = [1, 3, 5, 2, 2]
print("Equilibrium index (Space Efficient):", equilibrium_space_efficient(arr))
# Expected: 2