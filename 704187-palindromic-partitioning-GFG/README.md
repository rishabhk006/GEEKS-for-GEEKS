# [Palindromic Partitioning](https://www.geeksforgeeks.org/problems/palindromic-patitioning4845/1?page=1&difficulty=Hard&sortBy=submissions)
## Hard
Given a string s,&nbsp;a partitioning of the string is a&nbsp;palindrome partitioning&nbsp;if every sub-string of the partition is a palindrome.&nbsp;Determine the fewest cuts needed for palindrome partitioning of the given string.
Examples:
Input: s = "geek"&nbsp;Output: 2&nbsp;Explanation: We need to make minimum 2 cuts, i.e., "g | ee | k".
Input: s = "aaaa" Output: 0Explanation: The string is already a palindrome.
Input: s = "ababbbabbababa"&nbsp;Output: 3Explanation: We need to make minimum 3 cuts, i.e., "aba | bb | babbab | aba".
Constraints:1 ≤ |s| ≤ 103s contain lowercase letters only