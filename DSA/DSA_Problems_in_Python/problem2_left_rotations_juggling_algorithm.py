"""
Problem : Left Rotation with Reversal
In left rotation, every element of the array is shifted to the left by k positions, 
and the elements that fall off at the front wrap around to the end.

Input:  [1, 2, 3, 4, 5, 6], k = 2  
Output: [3, 4, 5, 6, 1, 2]
"""

# Code for Left Rotation (with comments) using Reversal Algorithm

def rotate_left_reverse(a, k):
    n = len(a)
    if n < 2:
        return a
    
    k %= n  # normalize k
    
    # helper function to reverse in-place between indices i and j
    def reverse(i, j):
        while i < j:
            a[i], a[j] = a[j], a[i]
            i, j = i+1, j-1
    
    # For RIGHT rotation by k, the order was:
    # 1) Reverse whole array
    # 2) Reverse first k elements
    # 3) Reverse remaining n-k elements
    
    # For LEFT rotation by k, the pattern is different:
    # 1) Reverse first k elements
    # 2) Reverse remaining n-k elements
    # 3) Reverse whole array
    
    reverse(0, k-1)      # reverse the first k elements
    reverse(k, n-1)      # reverse the remaining n-k elements
    reverse(0, n-1)      # reverse the entire array
    
    return a


print(rotate_left_reverse([1, 2, 3, 4, 5, 6], 2))

# Output : [3, 4, 5, 6, 1, 2]



# Code for Left Rotation (with comments) using Juggling Algorithm

from math import gcd

def rotate_left_juggling(a, k):
    """
    Left-rotate array a by k positions in-place using the Juggling Algorithm.
    Time: O(n), Space: O(1)
    """
    n = len(a)
    if n < 2:
        return a  # nothing to do for empty or single-element arrays

    k %= n               # normalize k so 0 <= k < n
    if k == 0:
        return a         # rotation by 0 or n is a no-op

    g = gcd(n, k)        # number of disjoint cycles

    # We will process each cycle independently.
    # For each cycle, we:
    # 1) remember the first element in `temp`
    # 2) walk through the cycle by jumping +k each time (mod n)
    # 3) at each step, pull the element from the next position into the current "hole"
    # 4) when we loop back to the start, drop `temp` into the final hole
    for start in range(g):
        temp = a[start]  # stash the first value of this cycle
        i = start        # current hole position

        while True:
            j = (i + k) % n  # in a LEFT rotation, the element from j should move to i
            if j == start:
                break         # we've closed the cycle; time to place `temp`
            a[i] = a[j]       # pull forward the element from j into the hole at i
            i = j             # the hole moves to index j; continue the cycle

        a[i] = temp           # drop the saved first element into the last hole

    return a

print(rotate_left_juggling([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11], 3))

# Output : [3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 1, 2]

