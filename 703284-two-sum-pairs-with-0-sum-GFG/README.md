# [Two sum -Pairs with 0 Sum](https://www.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1?page=1&difficulty=Easy&sortBy=submissions)
## Easy
Given an integer array&nbsp;arr, return all the&nbsp;unique&nbsp;pairs [arr[i], arr[j]] such that&nbsp;i != j and arr[i] + arr[j] == 0.
Note: The pairs must be returned in&nbsp;sorted&nbsp;order, the&nbsp;solution array should also be&nbsp;sorted, and the answer must not contain any&nbsp;duplicate&nbsp;pairs.
Examples:
Input: arr = [-1, 0, 1, 2, -1, -4]
Output: [[-1, 1]]
Explanation: arr[0] + arr[2] = (-1)+ 1 = 0.
arr[2] + arr[4] = 1 + (-1) = 0.
The distinct pair are [-1,1].

Input: arr = [6, 1, 8, 0, 4, -9, -1, -10, -6, -5]
Output: [[-6, 6],[-1, 1]]
Explanation: The distinct pairs are [-1, 1] and [-6, 6].
Constraints:3 ≤ arr.size ≤&nbsp;105-105 ≤&nbsp;arr[i] ≤&nbsp;105