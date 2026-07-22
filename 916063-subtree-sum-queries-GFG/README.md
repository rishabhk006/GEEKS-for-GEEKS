# [Subtree Sum Queries](https://www.geeksforgeeks.org/problems/subtree-sum-queries--130945/1?page=12&difficulty=Hard&sortBy=submissions)
## Hard
You are given a tree consisting of n nodes rooted at node 1. The nodes are numbered from 1 to n. The tree is represented by an array edges[] of n - 1 edges, where edges[i] = [ui, vi] is an edge between the nodes ui and vi. Additionally, each node has an integer value assigned to it. You are given an integer array values[] of length n, where values[i] is the value assigned to the ith node. You are also given an array queries[][]&nbsp;of q queries, where queries[j] is of two types:
1. 1 u x: Add x to the value of each node in the subtree of node u (including u).2. 2 u: Return the sum of the values of the nodes in the subtree of node u (including u) except the prime nodes.
A prime node is a node whose node number is a prime number. Return an array containing the answer to each query of type 2.
Examples:
Input: n = 3, edges[] = [[1, 2], [1, 3]], values[] = [1, 2, 3], q = 3, queries[][] = [[2, 1], [1, 1, 1], [2, 1]]Output: [1, 2]Explanation:    The initial values are [1, 2, 3].
For the first query, the subtree of node 1 is [1, 2, 3]. The prime nodes are [2, 3]. The sum of the values of the nodes in the subtree of node 1 except the prime nodes is 1.
For the second query, add 1 to the value of each node in the subtree of node 1. The new values are [2, 3, 4].
For the third query, the subtree of node 1 is [1, 2, 3]. The prime nodes are [2, 3]. The sum of the values of the nodes in the subtree of node 1 except the prime nodes is 2.
Input: n = 3, edges[] = [[1, 2], [2, 3]], values[] = [3, 3, 3], q = 3, queries[][] = [[2, 1], [2, 2], [2, 3]]Output: [3, 0, 0]Explanation:
The initial values are [3, 3, 3].
For the first query, the subtree of node 1 is [1, 2, 3]. The prime nodes are [2, 3]. The sum of the values of the nodes in the subtree of node 1 except the prime nodes is 3.
For the second query, the subtree of node 2 is [2, 3]. The prime nodes are [2, 3]. The sum of the values of the nodes in the subtree of node 2 except the prime nodes is 0.
For the third query, the subtree of node 3 is [3]. The prime nodes are [3]. The sum of the values of the nodes in the subtree of node 3 except the prime nodes is 0.
Constraints:

1 ≤ n, q, values[i], x ≤ 105
edges.length == n - 1
1 ≤ ui, vi ≤&nbsp;n
1 ≤&nbsp;queries[j][0]&nbsp;≤&nbsp;2
1 ≤&nbsp;queries[j][1]&nbsp;≤&nbsp;n
