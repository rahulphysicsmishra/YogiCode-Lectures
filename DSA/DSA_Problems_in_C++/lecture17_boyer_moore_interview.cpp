// lecture 17 : Boyer-Moore Voting Algorithm and Interview Problems

/*
Variation 1 : Classic Majority Element (> n/2)
“Given an array of size n, find the element that appears more than n/2 times. If no such element exists, say so.”

This is the most common Boyer Moore base case. If you can’t nail this, you won’t get the harder variations. 
Interviewers use it to test if you understand the voting + elimination concept without wasting extra memory.

Array: [2, 2, 1, 2, 3, 2, 2]
Task: Find element occurring > n/2 times

n = 7 → n/2 = 3.5 → More than 3 times
Answer here → 2

Step-by-step thought process

Start: candidate = None, count = 0
See 2 → count 1, candidate = 2
See 2 → count 2
See 1 → count 1 (different from candidate)
See 2 → count 2
See 3 → count 1
See 2 → count 2
See 2 → count 3
At the end: candidate = 2
Verify: 2 appears 5 times → Yes, > 3.5 → majority element.

*/


/*
Variation 2 : Two Majority Elements (> n/3)
“Given an array of size n, find all elements that appear more than n/3 times.”

This is the next natural twist after the classic majority element. Here, there 
can be at most two candidates that satisfy the condition, so Boyer Moore’s 
logic needs a small but important upgrade. Interviewers love this because many
 candidates overcomplicate it or forget the “verify” step.

Array: [1, 2, 3, 1, 2, 1, 1]
n = 7 → n/3 = 2.33 → More than 2 times

Answer → [1]

Step-by-step thought process

Start: cand1 = None, count1 = 0, cand2 = None, count2 = 0
See 1 → cand1 = 1, count1 = 1
See 2 → cand2 = 2, count2 = 1
See 3 → both counts drop → count1 = 0, count2 = 0
See 1 → cand1 = 1, count1 = 1
See 2 → cand2 = 2, count2 = 1
See 1 → cand1 = 1, count1 = 2
See 1 → cand1 = 1, count1 = 3
At the end: candidates = [1, 2]
Verify: 1 appears 4 times (> 2) → keep
2 appears 2 times (not > 2) → drop

Final answer: [1]

*/


/*
Variation 3 : Majority Element in a Stream
“You’re receiving a continuous stream of numbers. Find the majority element (> n/2) without storing the full stream in memory.”

When data is too large or infinite, you can’t store it. Boyer Moore’s constant space nature makes it perfect for streaming. 
Interviewers use this to test if you can adapt offline algorithms to real-time data situations.

Stream:  1, 2, 1, 1, 3, 1, ...
Goal: Find the element that appears more than half the time seen so far.

Approach:

Maintain only:
- 1 candidate
- 1 counter

For each incoming number:
- If counter = 0 → set candidate to this number
- If same as candidate → counter++
- Else → counter--

Step-by-step thought process
Start: candidate = None, count = 0
See 1 → cand = 1, count = 1
See 2 → different → count = 0
See 1 → count = 0 → cand = 1, count = 1
See 1 → same → count = 2
See 3 → different → count = 1
See 1 → same → count = 2

At any time, candidate is the current leader. If the stream ends, 
you must do a quick pass (or use a running verification) to check if it 
really is > n/2.
*/


/*
Variation 4 : Weighted Majority Vote
“You’re given a list of elements, but each element has a weight (influence level). Find the majority element (> half of total weight).”

Real world votes or rankings aren’t always equal, some votes carry more power. Boyer Moore can be adapted by adding/subtracting weights instead of 1. 
This tests if you can generalize a known algorithm to a weighted scenario.

Rough sketch of problem statement:

Elements:  A(3), B(2), A(5), C(4)
Goal: Find element whose total weight > 50% of total weight.

Approach:

Maintain:
- candidate
- total_weight_counter

For each element:
- If counter = 0 → candidate = this element, counter = weight
- If same as candidate → counter += weight
- Else → counter -= weight

Step-by-step thought process

Start: cand = None, count = 0
See A(3) → count = 0 → cand = A, count = 3
See B(2) → different → count = 1 (3–2)
See A(5) → same → count = 6 (1 + 5)
See C(4) → different → count = 2 (6–4)
Candidate after pass = A.
Verify by summing weights:

A: 3 + 5 = 8
Total weight = 3 + 2 + 5 + 4 = 14
8 > 14/2 → ✅ majority found.
*/


/*
Variation 5 : Verify Majority Element
“You’ve applied Boyer Moore and found a candidate. But what if no element actually occurs more than n/2 times? How do you make sure?”

Boyer–Moore only guarantees a correct candidate if a majority exists. If no majority is present, the algorithm still gives some element 
which can be wrong. Interviewers love checking if you remember the verification pass.

Array: [1, 2, 3, 2, 2]
Candidate after Boyer–Moore: 2
We must check if it really appears > n/2 times.

Approach:

Step 1: Run Boyer–Moore → get candidate
Step 2: Count how many times candidate appears
Step 3: If count > n/2 → return candidate, else → "No Majority"


Step-by-step thought process
Pass 1 (Boyer–Moore): Candidate = 2
Pass 2: Count occurrences of 2 → 3 times
Array length = 5 → n/2 = 2.5 → 3 > 2.5 ✅ majority confirmed.
*/