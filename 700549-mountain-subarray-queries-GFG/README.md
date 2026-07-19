# [Mountain Subarray Queries](https://www.geeksforgeeks.org/problems/mountain-subarray-problem/1)
## Medium
Given an array arr[] and a list of queries. For each query [l, r], find whether the subarray arr[l...r] is a mountain array. A subarray is called a mountain array if there exists an index k (l ≤ k ≤ r) such that: arr[l] ≤ arr[l + 1] ≤ ... ≤ arr[k] ≥ arr[k + 1] ≥ ... ≥ arr[r].

Elements of a Mountain subarray are first non-decreasing and then non-increasing. 
A subarray that is entirely non-decreasing or entirely non-increasing is also considered a mountain.

Examples:
Input: arr[] = [2, 3, 2, 4, 4, 6, 3, 2], queries[][] = [[0, 2], [1, 3]]
Output: [true, false]
Explanation: For query [0, 2], the subarray is [2, 3, 2]. The elements first increase and then decrease, so it forms a mountain.For query [1, 3], the subarray is [3, 2, 4]. The elements decrease and then increase, so it does not form a mountain.

Input: arr[] = [2, 2, 2, 2], queries[][] = [[0, 2], [1, 3]]
Output: [true, true]
Explanation: All subarrays of the given array are mountain.
Constraints:1 &lt;= arr.size(), queries.size() &lt;= 1051 &lt;= arr[i] &lt;= 1060 &lt;= l &lt;= r &lt; arr.size()