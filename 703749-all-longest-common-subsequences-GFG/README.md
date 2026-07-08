# [All Longest Common Subsequences](https://www.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1?page=3&difficulty=Hard&sortBy=submissions)
## Hard
Given two strings s1 and s2, return all distinct Longest Common Subsequences (LCS) in lexicographical order.
Note: A subsequence is derived from another string by deleting some or none of the elements without changing the order of the remaining elements.
Examples:
Input: s1 = "abaaa", s2 = "baabaca"
Output: ["aaaa", "abaa", "baaa"]Explanation: Length of lcs is 4, in lexicographical order they are "aaaa", "abaa", "baaa".

Input: s1 = "aaa", s2 = "a"
Output: ["a"]Explanation: Length of lcs is 1 and it is "a".
Input: s1 = "geeksforgeeks", s2 = "abcd"
Output: []Explanation: There is no common subsequence present in both strings.
Constraints:1 ≤ s1.size(), s2.size() ≤ 50s1 and s2 contain only lowercase English letters.