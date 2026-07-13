# [Distribute Candies](https://www.geeksforgeeks.org/problems/distribute-candies-in-a-binary-tree/1?page=4&difficulty=Hard&sortBy=submissions)
## Hard
You are given the root of a binary tree with n nodes, where each node contains a certain number of candies, and the total number of candies across all nodes is n. In one move, you can select any two adjacent nodes and transfer one candy from one node to the other. The transfer can occur between a parent and child in either direction.
The task is to determine the minimum number of moves required to ensure that every node in the tree has exactly one candy.
Note: The testcases are framed such that it is always possible to achieve a configuration in which every node has exactly one candy, after some moves.
Examples:
Input: root = [5, 0, 0, N, N, 0, 0]  Output: 6Explanation:Move 1 candy from root to left child
Move 1 candy from root to right child
Move 1 candy from right child to root-&gt;right-&gt;left node
Move 1 candy from root to right child
Move 1 candy from right child to root-&gt;right-&gt;right node
Move 1 candy from root to right childso, total 6 moves required.
Input: root = [2, 0, 0, N, N, 3, 0]  Output: 4Explanation:Move 1 candy from root to left child
Move 1 candy from root-&gt;right-&gt;left node to root-&gt;right node
Move 1 candy from root-&gt;right node to root-&gt;right-&gt;right node
Move 1 candy from root-&gt;right-&gt;left node to root-&gt;right nodeso, total 4 moves required.
Constraints:1&nbsp;≤&nbsp;n&nbsp;≤ 3*1030&nbsp;≤ Node-&gt;data&nbsp;≤&nbsp;nThe sum of all Node-&gt;data = n