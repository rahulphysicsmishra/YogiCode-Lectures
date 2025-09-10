"""
Problem : Subarray with Given Sum
We are given an integer array (can include positives & negatives) and a target integerK. Find if there exists a contiguous subarray whose sum equals K (or count how many such subarrays exist).

Important: The subarray must be continuous, meaning no skipping elements.
"""

# Brute Force Code (with detailed comments)
# Time Complexity: O(n^2), because we check all subarrays
# Space Complexity: O(1), we only use a few variables

def count_subarrays_with_sum(arr, target):
    n = len(arr)        # total number of elements in the array
    count = 0           # to keep track of how many subarrays equal target

    # Outer loop: choose starting point of subarray
    for i in range(n):
        current_sum = 0   # reset sum every time we pick a new start index

        # Inner loop: extend the subarray to the right
        for j in range(i, n):
            current_sum += arr[j]   # add current element to subarray sum

            # Print for understanding (can remove later if not needed)
            print(f"Subarray from index {i} to {j} → {arr[i:j+1]}, Sum = {current_sum}")

            # Check if subarray sum matches target
            if current_sum == target:
                count += 1
                print(f"✅ Found one! Count = {count}")

    return count


# Example usage
arr = [1, 2, 3, -2, 5]
target = 5
print("Total subarrays with sum =", target, "is:", count_subarrays_with_sum(arr, target))


# Prefix Sum Approach Full Code
# Time Complexity: O(n^2)
# Space Complexity: O(n) due to the prefix sum array

def count_subarrays_with_sum_prefix(arr, k):
    n = len(arr)

    # Step 1: Build prefix sum array
    prefix_arr = [0] * n
    prefix_arr[0] = arr[0]

    for i in range(1, n):
        prefix_arr[i] = prefix_arr[i-1] + arr[i]

    print("Prefix Sum Array:", prefix_arr)  # helpful to understand

    count = 0

    # Step 2: Check all possible subarrays using prefix sums
    for i in range(n):          # starting index
        for j in range(i, n):   # ending index
            if i == 0:
                # Subarray starts at index 0
                current_sum = prefix_arr[j]
            else:
                # Subarray sum = prefix[j] - prefix[i-1]
                current_sum = prefix_arr[j] - prefix_arr[i-1]

            # Print subarray and its sum for clarity
            print(f"Subarray arr[{i}:{j+1}] = {arr[i:j+1]}, Sum = {current_sum}")

            if current_sum == k:
                count += 1
                print(f"✅ Found one! Count = {count}")

    return count



#  Optimized HashMap Approach
# Time Complexity: O(n)
# Space Complexity: O(n) for the hashmap

def optimized_soln(arr, k):
    n = len(arr)
    
    count = 0                 # total subarrays with sum = k
    current_sum = 0           # running prefix sum
    hash_map = {0: 1}         # prefix sum frequencies (0 means no elements yet)
    
    print("Initial HashMap:", hash_map)
    print("Starting traversal...\n")
    
    for i in range(n):
        current_sum += arr[i]   # update prefix sum
        
        # Step 1: Check if there's a previous prefix that makes a valid subarray
        needed = current_sum - k
        
        print(f"Index {i}, Element = {arr[i]}")
        print(f"  Current Prefix Sum = {current_sum}")
        print(f"  Needed Prefix = {needed}")
        
        if needed in hash_map:
            count += hash_map[needed]
            print(f"  ✅ Found {hash_map[needed]} subarray(s) ending here with sum = {k}")
        
        # Step 2: Update hashmap with the current prefix_sum
        if current_sum in hash_map:
            hash_map[current_sum] += 1
        else:
            hash_map[current_sum] = 1
        
        print(f"  Updated HashMap: {hash_map}\n")
    
    print("Final Count:", count)
    return count


# Example usage
arr = [1, 2, 3, -2, 5]
k = 5
print("Total subarrays with sum =", k, "is:", optimized_soln(arr, k))