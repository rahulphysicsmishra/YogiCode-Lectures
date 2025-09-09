# Revised Problem : Left Rotation of an Array

# Block Swap Approach
def rotate_blockswap(a, k):
    """
    In-place left rotation by k using the Block-Swap algorithm.
    Time: O(n), Space: O(1)

    This rotates 'a' so that a[i] moves to a[(i - k) mod n].
    """
    n = len(a)
    if n <= 1:
        return a

    # Normalize k to [0, n)
    k %= n
    if k == 0:
        return a

    # We'll maintain a window [start .. start + i + j) split as:
    # A = a[start .. start + i - 1]       (size i = k initially)
    # B = a[start + i .. start + i + j - 1] (size j = n - k initially)
    start = 0
    i = k           # size of A
    j = n - k       # size of B

    def swap_block(arr, p, q, m):
        """Swap m elements starting at p with m elements starting at q."""
        for t in range(m):
            arr[p + t], arr[q + t] = arr[q + t], arr[p + t]

    # Chip away until A and B become equal-sized
    while i != j:
        if i < j:
            # A is smaller: swap A with the first i elements of B
            # [A | B1 B2] -> swap(A, B1) => [B1 | A B2]
            swap_block(a, start, start + i, i)
            # Move the window right past B1
            start += i
            # B shrinks by i
            j -= i
            # A size stays i
        else:
            # B is smaller: swap the last j elements of A with B
            # [A1 A2 | B] -> swap(A2, B) => [A1 | B A2]
            swap_block(a, start + i - j, start + i, j)
            # A shrinks by j (we consumed A2)
            i -= j
            # B size stays j; start stays the same

    # i == j: one final equal-sized swap finishes rotation
    swap_block(a, start, start + i, i)
    return a
    
print(rotate_blockswap([1, 2, 3, 4, 5, 6, 7], 3))