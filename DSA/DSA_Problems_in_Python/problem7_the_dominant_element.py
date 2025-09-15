"""
Problem Statement: Majority Element
You are given an array of integers of size n. A majority element is the one that 
appears more than ⌊n/2⌋ times in the array.

Your task: Find and return the majority element if it exists, otherwise return -1. 
For example:

arr = [3, 3, 4, 2, 3, 3, 5] , output = 3

Explanation:

Array size = 7

n/2 = 3.5 → so element must appear more than 3 times.

3 appears 4 times → majority element = 3.
"""


# Brute Force Code (with detailed comments)
# Time Complexity: O(n^2), because we have a nested loop to count occurrences
# Space Complexity: O(1), we only use a few variables
# Problem: Find the Majority Element in an array (appears more than n/2 times)

def brute_majority_element(arr):
    n = len(arr)
    threshold = n // 2   # majority element must appear MORE than this value

    # Loop through each element in the array
    for i in range(n):
        count = 0  # reset count for this element

        # Count how many times arr[i] appears in the entire array
        for j in range(n):
            if arr[i] == arr[j]:
                count += 1

        # Check if this element is majority
        if count > threshold:
            return arr[i]  # return as soon as we find a majority

    # If no element appears more than n/2 times
    return -1


# ------------------- TEST CASES -------------------

# Case 1: Majority exists
arr1 = [3, 3, 4, 2, 3, 3, 5]
print("Majority element:", brute_majority_element(arr1))  
# Expected Output: 3 (appears 4 times, > 7//2 = 3)

# Case 2: No majority element
arr2 = [1, 2, 3, 4]
print("Majority element:", brute_majority_element(arr2))  
# Expected Output: -1 (no element appears more than 2 times)

# Case 3: Single element array
arr3 = [7]
print("Majority element:", brute_majority_element(arr3))  
# Expected Output: 7 (appears once, and 1 > 0)

# Case 4: All elements same
arr4 = [9, 9, 9, 9]
print("Majority element:", brute_majority_element(arr4))  
# Expected Output: 9 (appears 4 times, > 4//2 = 2)



# Optimized Code using Hash Map (Dictionary)
# Time Complexity: O(n), we traverse the array twice (once for counting, once for checking)
# Space Complexity: O(n), we use a dictionary to store counts
# Problem: Find the Majority Element in an array using Hash Map (Dictionary)

def hashmap_majority_element(arr):
    n = len(arr)
    threshold = n // 2   # majority must appear more than this

    # Step 1: Count frequency of each element using a dictionary
    freq = {}
    for num in arr:
        if num not in freq:
            freq[num] = 1   # if number not in dictionary, initialize count = 1
        else:
            freq[num] += 1  # if already present, increment count

    # Step 2: Check if any element crosses the majority threshold
    for num, count in freq.items():
        if count > threshold:
            return num   # found majority element

    # Step 3: If no element satisfies condition
    return -1


# ------------------- TEST CASES -------------------

# Case 1: Majority exists
arr1 = [3, 3, 4, 2, 3, 3, 5]
print("Majority element (Hash Map):", hashmap_majority_element(arr1))
# Expected Output: 3 (appears 4 times, > 7//2 = 3)

# Case 2: No majority element
arr2 = [1, 2, 3, 4]
print("Majority element (Hash Map):", hashmap_majority_element(arr2))
# Expected Output: -1

# Case 3: Single element array
arr3 = [10]
print("Majority element (Hash Map):", hashmap_majority_element(arr3))
# Expected Output: 10

# Case 4: All elements same
arr4 = [5, 5, 5, 5, 5]
print("Majority element (Hash Map):", hashmap_majority_element(arr4))
# Expected Output: 5





# Optimized Code using Sorting
# Time Complexity: O(n log n) due to sorting step
# Space Complexity: O(1) if sorting in place, otherwise O(n)

def sort_majority_element(arr):
    n = len(arr)
    
    # Step 1: Handle trivial cases
    if n == 0:
        return -1
    if n == 1:
        return arr[0]

    # Step 2: Sort the array
    arr.sort()

    # Step 3: Pick the middle element as candidate
    candidate = arr[n // 2]

    # Step 4: Count occurrences of candidate
    count = arr.count(candidate)

    # Step 5: Verify majority condition
    if count > n // 2:
        return candidate
    else:
        return -1


# ------------------- TEST CASES -------------------

# Case 1: Majority exists
arr1 = [3, 3, 4, 2, 3, 3, 5]
print("Majority element (Sorting):", sort_majority_element(arr1))
# Expected Output: 3

# Case 2: No majority element
arr2 = [1, 2, 3, 4]
print("Majority element (Sorting):", sort_majority_element(arr2))
# Expected Output: -1

# Case 3: Single element array
arr3 = [10]
print("Majority element (Sorting):", sort_majority_element(arr3))
# Expected Output: 10

# Case 4: All same elements
arr4 = [9, 9, 9, 9]
print("Majority element (Sorting):", sort_majority_element(arr4))
# Expected Output: 9