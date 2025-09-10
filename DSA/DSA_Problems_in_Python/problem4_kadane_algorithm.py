"""
Problem : Maximum Subarray Sum
We are given an integer array (can have positives & negatives). We need to 
find the contiguous subarray (continuous elements, no skipping) that has the 
maximum sum.
"""

# Brute Force Approach for Maximum Subarray Problem
# Time Complexity: O(n^2), because we check all subarrays
# Space Complexity: O(1), we only use a few variables

def max_subarray_bruteforce(arr):
    n = len(arr)
    max_sum = float('-inf')   # Start with the lowest possible value
    
    # Outer loop: starting index of subarray
    for i in range(n):
        current_sum = 0  # to keep sum of arr[i...j]
        
        # Inner loop: ending index of subarray
        for j in range(i, n):
            current_sum += arr[j]   # add current element to subarray sum
            max_sum = max(max_sum, current_sum)  # update max if needed
            
            # Print for understanding (optional, can comment out)
            print(f"Checking subarray {arr[i:j+1]} → sum = {current_sum}, max = {max_sum}")
    
    return max_sum


# Example usage
arr = [1, -2, 3]
print("Maximum Subarray Sum (Brute Force):", max_subarray_bruteforce(arr))



# Kadane's Algorithm - Optimized O(n) Solution
# Time Complexity: O(n)
# Space Complexity: O(1)

def max_subarray_kadane(arr):
    n = len(arr)
    
    # Initialize with the first element
    current_sum = arr[0]
    max_sum = float('-inf')
    
    # Traverse the array from 2nd element onwards
    for i in range(1, n):
        # Either extend the previous subarray OR start new from arr[i]
        current_sum = max(arr[i], current_sum + arr[i])
        
        # Update global max if needed
        max_sum = max(max_sum, current_sum)
        
        # Print for dry run understanding (optional)
        print(f"Element: {arr[i]}, Current Sum: {current_sum}, Max Sum: {max_sum}")
    
    return max_sum


# Example usage
arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
print("Maximum Subarray Sum (Kadane’s Optimized):", max_subarray_kadane(arr))