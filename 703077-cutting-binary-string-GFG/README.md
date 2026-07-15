# [Cutting Binary String](https://www.geeksforgeeks.org/problems/cutting-binary-string1342/1?page=24&difficulty=Medium&sortBy=submissions)
## Medium
You are given a binary string&nbsp;s&nbsp;consisting only of characters&nbsp;'0'&nbsp;and&nbsp;'1'. Your task is to split this string into the&nbsp;minimum number&nbsp;of non-empty&nbsp;substrings&nbsp;such that:

Each substring represents a&nbsp;power of 5&nbsp;in decimal (e.g., 1, 5, 25, 125, ...).
No substring should have&nbsp;leading zeros.

Return the&nbsp;minimum number of such pieces&nbsp;the string can be divided into.Note:&nbsp;If it is&nbsp;not possible&nbsp;to split the string in this way, return&nbsp;-1.
Examples:
Input: s = "101101101"Output: 3Explanation:&nbsp;The string can be split into three substrings: "101", "101", and "101", each of which is a power of 5 with no leading zeros.
Input: s = "1111101"
Output: 1
Explanation: The string can be split into one binary string "1111101" which is 125 in decimal and a power of 5 with no leading zeros.
Input: s = "00000"Output: -1Explanation: There is no substring that can be split into power of 5.
