"""
Given an array nums and an integer k, rotate the array to the right by k steps.
Right rotation means elements move to higher indices, wrapping around to the front. 
For example:

Input : nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]

Key detail: k can be bigger than n. Always reduce with k = k % n.



Quick visual (rough sketch)
Think of the array as a ring / conveyor belt:

Index:  0  1  2  3  4  5  6
nums : [1, 2, 3, 4, 5, 6, 7]
                    ^  ^  ^-- these 3 (k=3) wrap to the front

After rotate right by 3:
[5, 6, 7, 1, 2, 3, 4]

"""



### Approach 1 : Brute force (rotate by 1, repeat k times)

# function to take 2 inputs(array, rotation steps to the right)
def rotate_bruteforce(nums, k):
    n = len(nums)
    # if length is less than or equal to 1, no point of rotation
    if n <= 1:
        return nums
    # very important step, if k is greater than the length of array, it reset
    k %= n
    # first we save the last element, then loop over the array in reverse
    # order, then we move array by one step at a time in the right direction
    # once the inner loop finishes, we replace the first element with the last
    for _ in range(k):
        last = nums[-1]
        # shift right by 1
        for i in range(n - 1, 0, -1):
            nums[i] = nums[i - 1]
        nums[0] = last
    # once we rotate by k steps, just return the nums
    return nums




"""
If you feel this brute force visualisation is also hard to understand, 
I’m adding code with more comments and each loop run, take time to understand
the code by going through output

"""



from typing import List

nums = [1,2,3,4,5,6,7]

def _print_indices(n: int):
    """
    Helper printer: shows index positions 0..n-1 in a single line.
    Purely for visual alignment with array prints below.
    """
    idx = " ".join(f"{i:2d}" for i in range(n))  # format each index in width=2 for clean columns
    print(f"idx:  {idx}")

def _print_array(a: List[int], label: str = "arr"):
    """
    Helper printer: shows the array values in one line with a label.
    Matches spacing of _print_indices for easy reading.
    """
    vals = " ".join(f"{v:2d}" for v in a)       # width=2 so columns line up with indices
    print(f"{label}:{vals}")

def rotate_bruteforce_debug(nums: List[int], k: int, *, verbose: bool = True) -> List[int]:
    """
    Rotate an array `nums` to the right by `k` steps using a brute-force method.

    Brute-force idea (right-rotation by 1, repeated `k` times):
      - Take the last element and place it at the front.
      - Shift every other element one position to the right.
      - Repeat this single-step rotation `k` times.

    Parameters
    ----------
    nums : List[int]
        The array to rotate (modified in-place and also returned).
    k : int
        Number of steps to rotate to the right. Can be >= len(nums).
    verbose : bool, keyword-only
        If True, print detailed step-by-step debug output.

    Returns
    -------
    List[int]
        The same list object, after rotation.

    Complexity
    ----------
    Time:  O(n * k)  (because we perform k passes, each shifting ~n elements)
    Space: O(1)      (in-place, aside from a few scalar temporaries)

    Notes
    -----
    - We normalize k with k %= n so that unnecessary full cycles are skipped.
      Rotating by `n` (array length) results in the same array, so only the remainder matters.
    - This function is focused on clarity and step-by-step visibility, not efficiency.
      For large arrays / large k, prefer the reversal method or juggling/cycles method.
    """

    # n is the length of the array. We'll use it a lot.
    n = len(nums)

    # Quick exit for arrays of length 0 or 1: rotation does nothing.
    if n <= 1:
        if verbose:
            print("Array length ≤ 1 → nothing to do.")
        return nums  # Return original list reference for consistency.

    # Preserve the original k for logging; then reduce k into [0, n-1].
    orig_k = k
    k %= n  # After this, k == 0 means "no net change"
    if verbose:
        print(f"Normalize k: original k={orig_k}, n={n} → k={k}")
        _print_indices(n)            # Show index row once for orientation
        _print_array(nums, "start")  # Show the starting array

    # Perform k single-step right rotations.
    # Each pass: pick up the last element, shift the rest to the right, drop the last at index 0.
    for rot in range(1, k + 1):
        if verbose:
            print(f"\n--- Rotation {rot}/{k} ---")
            print("Take last element to front on this pass.")

        # 1) Save the last element before overwriting anything.
        last = nums[-1]  # same as nums[n-1]
        if verbose:
            print(f"last = nums[{n-1}] = {last}")

        # 2) Shift elements right by one position.
        #    We must go RIGHT→LEFT so we don't overwrite values we still need to move.
        #    Example for n=5: i goes 4→1; we set nums[i] = nums[i-1].
        for i in range(n - 1, 0, -1):
            moved = nums[i - 1]  # value that will move to position i
            if verbose:
                print(f"move nums[{i-1}] ({moved}) → nums[{i}] (was {nums[i]})")
            nums[i] = moved

        # 3) Place the saved last element at the new front.
        nums[0] = last

        # 4) Show the array after this single rotation step (if verbose).
        if verbose:
            _print_array(nums, "after")

    # If k reduced to 0, explicitly call that out (means no net rotation).
    if verbose and k == 0:
        print("k is 0 after normalization → array unchanged.")

    # Return the same list object, now rotated.
    return nums

# I'm gonna share output with k = 2
print(rotate_bruteforce_debug(nums, 2))





### Approach 2 : Extra space (clean & Pythonic)

def rotate_slicing(nums, k):
    n = len(nums)
    if n <= 1:
        return nums
    k %= n
    # last k to front, rest after
    rotated = nums[-k:] + nums[:-k]
    # write back if in-place required
    nums[:] = rotated
    return nums



### Approach 3 : Optimal in place (reversal trick)


def rotate_inplace(nums, k):
    """
    Rotate an array to the right by k steps, in-place (no extra array used).

    This uses the **reversal algorithm**:
      1. Reverse the entire array.
      2. Reverse the first k elements.
      3. Reverse the remaining n-k elements.

    Time Complexity:  O(n)   (we touch each element at most twice)
    Space Complexity: O(1)   (in-place, only constant extra variables)

    Example:
    ----------
    nums = [1, 2, 3, 4, 5, 6, 7], k = 3

    Step 1: Reverse entire array
        [7, 6, 5, 4, 3, 2, 1]
    Step 2: Reverse first k (=3) elements
        [5, 6, 7, 4, 3, 2, 1]
    Step 3: Reverse remaining n-k (=4) elements
        [5, 6, 7, 1, 2, 3, 4]
    Final → rotated array
    """

    n = len(nums)

    # If array length is 0 or 1, rotating does nothing
    if n <= 1:
        return nums

    # Normalize k, because rotating by n (or multiple of n) = no change
    k %= n

    # ---------------------------
    # Define a local helper function for reversing part of the array
    # ---------------------------
    def reverse(i, j):
        """
        Reverse nums[i..j] in place by swapping from both ends inward.

        Example:
        nums = [1, 2, 3, 4, 5], reverse(1, 3)
        swaps → (2,4) → nums = [1, 4, 3, 2, 5]
        """
        while i < j:
            # Swap elements at positions i and j
            nums[i], nums[j] = nums[j], nums[i]
            # Move inward
            i += 1
            j -= 1

    # Step 1: Reverse the entire array
    reverse(0, n - 1)

    # Step 2: Reverse the first k elements (these are the "rotated front")
    reverse(0, k - 1)

    # Step 3: Reverse the rest of the array (the "rotated back")
    reverse(k, n - 1)

    return nums