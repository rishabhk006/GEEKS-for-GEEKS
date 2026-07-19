# [Shortest Unique Prefix for Every Word](https://www.geeksforgeeks.org/problems/shortest-unique-prefix-for-every-word/1)
## Hard
Given an array of strings arr[ ], find the shortest prefix of each string that uniquely identifies it among all strings in the array. A prefix is unique if it is not a prefix of any other string in the array. Return the shortest unique prefix for every string in the same order as the input.
Note: No string in the array is a prefix of another string.
Examples :
Input: arr[] = {"zebra", "dog", "duck", "dove"}
Output: z dog du dov
Explanation: z =&gt; zebra, dog =&gt; dog, duck =&gt; du, dove =&gt; dov 

Input: arr[] = {"geeksgeeks", "geeksquiz", "geeksforgeeks"}
Output: geeksg geeksq geeksfExplanation: geeksgeeks =&gt; geeksg, geeksquiz =&gt; geeksq, geeksforgeeks =&gt; geeksf
Constraints:
1 ≤ length of arr, length of each word ≤ 1000