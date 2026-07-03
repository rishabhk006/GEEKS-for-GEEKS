# [Doubly Linked List Traversal](https://www.geeksforgeeks.org/problems/display-doubly-linked-list--154650/1?page=6&category=Linked%20List&sortBy=submissions)
## Easy
Given head of a doubly linked list containing n nodes, return a 2D array where:

The first row contains the elements obtained by traversing the linked list in forward direction.
The second row contains the elements obtained by traversing the linked list in backward direction.

Examples:
Input: head: 1 &lt;-&gt; 2 &lt;-&gt; 3 &lt;-&gt; 4 &lt;-&gt; 5 Output: [[1, 2, 3, 4, 5], [5, 4, 3, 2, 1]]Explanation: After traversing forward the linked list will look like 1 -&gt; 2 -&gt; 3 -&gt; 4 -&gt; 5 and from backward will 5 -&gt; 4 -&gt; 3 -&gt; 2 -&gt; 1.
Input: head: 34 &lt;-&gt; 22 Output: [[34, 22], [22, 34]]Explanation: After traversing forward the linked list will look like 34 -&gt; 22 and from backward will 22 -&gt; 34.
Constraints:1&nbsp;≤&nbsp;n&nbsp;≤&nbsp;1050&nbsp;≤ data&nbsp;of nodes ≤&nbsp;105