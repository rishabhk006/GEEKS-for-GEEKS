# [Minimum swap required to convert binary tree to binary search tree](https://www.geeksforgeeks.org/problems/minimum-swap-required-to-convert-binary-tree-to-binary-search-tree/1?page=9&difficulty=Hard&sortBy=submissions)
## Hard
Given an array&nbsp;arr[]&nbsp;which represents&nbsp;a&nbsp;Complete Binary Tree i.e, if index&nbsp;i&nbsp;is the parent, index&nbsp;2*i + 1&nbsp;is the left child and index&nbsp;2*i + 2&nbsp;is the right child.The task is to find the minimum number of swaps required to convert it into a Binary Search Tree.&nbsp;
Examples :
Input: arr[] = [5, 6, 7, 8, 9, 10, 11]
Output: 3
Explanation: 
Binary tree of the given array:
 Swap 1: Swap node 8 with node 5.
Swap 2: Swap node 9 with node 10.
Swap 3: Swap node 10 with node 7.
 So, minimum 3 swaps are required.
Input: arr[] = [1, 2, 3]Explanation: Binary tree of the given array: After swapping node 1 with node 2, obtain the below binary search tree:Output: 1
Constraints:1 &lt;= arr.size() &lt;= 1051 &lt;= arr[i] &lt;= 109