// lecture 16 : Sliding Window and Interview Problems

/*
Variation 1: Minimum Size Subarray Sum ≥ Target
You’re given an array of positive integers and a target sum. Find the smallest length of a subarray whose sum is greater than or equal to the target.
If no such subarray exists, return 0.

Example:

arr = [2, 3, 1, 2, 4, 3], target = 7
start = 0, end = 0, sum = 0

[2]   → sum = 2     ❌
[2,3] → sum = 5     ❌
[2,3,1] → sum = 6   ❌
[2,3,1,2] → sum = 8 ✅ length = 4
Then try shrinking...
[3,1,2] → sum = 6   ❌ (too small)
[1,2,4] → sum = 7 ✅ length = 3
[4,3] → sum = 7 ✅ length = 2 ← best so far
*/

/*
Variation 2 : Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without repeating characters.

You’re allowed to move through the string, and at any point, you’re building a 
substring. If a repeating character shows up, you’re forced to cut it off from 
the left and keep moving forward.

Example:

s = "abcabcbb"

"abc" → length = 3  
"bca" → length = 3  
"cab" → length = 3  
"abc" → length = 3  
"cb" → length = 2  
"b" → length = 1

Maximum length = 3 ✅
*/

/*
Variation 3 : Count of Anagram Substrings (Pattern-based Window)
Given a string s and a pattern p, count how many substrings of s are anagrams of p.

You’re not just matching letters, you’re finding scrambled versions of the pattern hidden 
inside the string.

s = "cbaebabacd"
p = "abc"

What does an anagram of "abc" look like?

"abc", "acb", "bac", "bca", "cab", "cba"

We slide a window of size 3:

"cba" ✅ anagram!
"bae" ❌
"aeb" ❌
"eba" ❌
"bab" ❌
"aba" ❌
"bac" ✅ anagram!
"acd" ❌

Total anagram substrings = 2 ✅
*/


/*
Variation 4: Longest Substring with At Most K Distinct Characters
Given a string s and an integer k, find the length of the longest substring 
that contains at most k distinct characters.

This is a variable window problem, where the window expands while valid, 
and shrinks when it becomes invalid.

Example:

s = "eceba"
k = 2

What are the valid substrings? Let’s slide

"ec" ✅ (2 chars)
"ece" ✅ (3 chars)
"eceb" ❌ (3 distinct chars)
"ceb"❌ (3 distinct chars)
"eb"✅ (2 distinct chars)
"eba"❌ (3 distinct chars)
"ba" ✅ (2 chars)
→ Answer is 3, from "ece", that's the longest.

We also track the max length of any valid window.

s = "eceba"
k = 2

Initial:
window = ""
char_count = {}

Step-by-step:

1. Add 'e' → {"e":1}
2. Add 'c' → {"e":1, "c":1}
3. Add 'e' → {"e":2, "c":1}
   ✅ still ≤ 2 distinct → maxLen = 3
4. Add 'b' → {"e":2, "c":1, "b":1}
   ❌ 3 distinct → shrink window from left:
      - Remove 'e' → {"e":1, "c":1, "b":1}
      - Remove 'c' → {"e":1, "b":1}
   ✅ back to 2 distinct → maxLen still = 3
*/