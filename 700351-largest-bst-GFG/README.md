# [Largest BST](https://www.geeksforgeeks.org/problems/largest-bst/1?page=7&difficulty=Medium&sortBy=submissions)
## Medium
You're given a binary tree. Your task is to find the size of the largest subtree within this binary tree that also satisfies the properties of a Binary Search Tree (BST). The size of a subtree is defined as the number of nodes it contains.
Note: A subtree of the binary tree is considered a BST if for every node in that subtree, the left child is less than the node, and the right child is greater than the node, without any duplicate values in the subtree.
Examples :
Input: root = [5, 2, 4, 1, 3]Output: 3Explanation:The following sub-tree is a BST of size 3
Input: root = [6, 7, 3, N, 2, 2, 4]Output: 3Explanation: The following sub-tree is a BST of size 3:
Constraints:1 ≤ number of nodes ≤ 1051 ≤ node-&gt;data ≤ 105