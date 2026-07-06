# [Linked List Group Reverse](https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1?page=1&difficulty=Hard&sortBy=submissions)
## Hard
Given the head of a Singly linked list. Reverse&nbsp;every&nbsp;k&nbsp;node in the linked list and return the head of the modified list.Note:&nbsp;If the number of nodes is not a multiple of&nbsp;k&nbsp;then the left-out nodes at the end, should be considered as a group and must be&nbsp;reversed.
Examples:
Input: head: 1 -&gt; 2 -&gt; 3 -&gt; 4 -&gt; 5 -&gt; 6, k = 2Output: 2 -&gt; 1 -&gt; 4 -&gt; 3 -&gt; 6 -&gt; 5Explanation: Linked List is reversed in a group of size k = 2.
Input: head: 1 -&gt; 2 -&gt; 3 -&gt; 4 -&gt; 5 -&gt; 6, k = 4,Output: 4 -&gt; 3 -&gt; 2 -&gt; 1 -&gt; 6 -&gt; 5Explanation: Linked List is reversed in a group of size k = 4.
Constraints:
1 ≤ size of linked list ≤ 105
0 ≤ node-&gt;data ≤ 1061 ≤ k ≤&nbsp;size of linked list&nbsp;