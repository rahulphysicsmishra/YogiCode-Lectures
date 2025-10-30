// lecture 18 : Types of Difference Array Problems

/*
Variation 1 : Multiple Range Updates + Final Query
You’re given:

An array of size n (initially zeros or given values)
m range update operations (l, r, val) — add val to every element from index l to r
At the end, you need the final array after all updates are applied

n = 5, m = 3
Updates:
1 3 2    → Add 2 to [1..3]
2 4 3    → Add 3 to [2..4]
3 5 1    → Add 1 to [3..5]

Step-by-Step Logic

1. Initialize a difference array diff of size n+1 with zeros.
diff = [0, 0, 0, 0, 0, 0]  // size n+1

2. For each update (l, r, val):
diff[l] += val
diff[r+1] -= val (if r+1 <= n)

After all updates:
After (1,3,2): [2, 0, 0, -2, 0, 0]
After (2,4,3): [2, 3, 0, -2, -3, 0]
After (3,5,1): [2, 3, 1, -2, -3, -1]

3. Take prefix sum of diff to get the final array.

Final array after all updates: [2, 5, 6, 4, 1]
*/


/*
Variation 2 : Range Multiplication/Custom Operation
You’re given:

An array of size n (initially given or zeros)
m operations of the form: multiply every element in [l, r] by k
Output the final array after all operations.

n = 5, m = 2
Initial: [1, 1, 1, 1, 1]
Operations:
1 3 × 2    → Multiply elements 1..3 by 2
2 5 × 3    → Multiply elements 2..5 by 3

Expected output:
[2, 6, 6, 3, 3]


Approach:
The normal difference array trick works only for additions, 
because addition is linear and prefix sums naturally combine them.

For multiplication, addition-based diff breaks :
Example: multiplying by 2 twice ≠ adding 4.

Instead, we:

Switch to logarithmic space (using log values)
Initial array in logs:
[0, 0, 0, 0, 0] (log(1) = 0)

2. Store additions of logs in a difference array (because multiplication becomes addition in log space)

For (l, r, k) → diff[l] += log(k) and diff[r+1] -= log(k)

3. Prefix sum of diff = total log multiplier

4. Exponentiate to get final array values
*/


/*
Variation 3 : 2D Range Updates
You’re given a 2D grid (n × m).
You need to perform updates like:
“Add val to every cell in the rectangle (x1, y1) to (x2, y2).”

Initial 4×4 grid (all 0):

0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0

Update: Add 5 to rectangle (2,2) → (3,3)

Visual Approach
In 1D difference array, we mark start and end+1.
In 2D, we do a similar marking, but in four corners of the rectangle.

For an update (x1, y1, x2, y2, val):

diff[x1][y1]       += val
diff[x1][y2+1]     -= val
diff[x2+1][y1]     -= val
diff[x2+1][y2+1]   += val
*/


/*
Variation 4 : Range Addition with Point Queries in Between
Normally, in difference array problems, we

apply all updates first,
then take a prefix sum at the end to get the final array.
But what if the interviewer says:

“You’ll get a mix of updates and queries, and queries can appear before all updates are done.”

Array size = 5
Ops:
+ Add 3 to [2,4]
? Query index 3
+ Add 2 to [1,5]
? Query index 2


Approach
In standard difference array: prefix sum is applied once at the end.
Here, we need the prefix sum effect on demand when a query comes in.
Idea:

Keep the diff array as usual.
When a point query q comes, compute prefix sum only up to that index.

*/


/*
Variation 5 : Reversing the Problem: Range Subtraction Queries
What if the interviewer flips the script:

“Instead of adding values to a range, subtract them.”

At first glance, it feels like we need a new algorithm.
In reality, it’s the same difference array logic, but with a negative value.

Array size = 6
Ops:
- Subtract 5 from [2,4]
- Subtract 2 from [1,6]

Why It Works Without New Logic

Difference array just stores net change at each index.
Subtraction is simply addition of a negative number.
So range_subtract(l, r, k) = range_add(l, r, -k)
*/