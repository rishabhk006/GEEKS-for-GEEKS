# [Subtraction in Linked List](https://www.geeksforgeeks.org/problems/subtraction-in-linked-list/1?page=2&difficulty=Hard&sortBy=submissions)
## Hard
You are given two linked lists&nbsp;representing two large positive numbers. The linked lists represent these two numbers, subtract the smaller number from the larger one and return the head&nbsp;of the&nbsp;linked list&nbsp;representing the result. Please take a look at the examples to get a better understanding of the task.
The linked list does not contain leading zeros, except for the number zero itself.
Examples:
Input: LinkedList1: 1-&gt;0-&gt;0, LinkedList2: 1-&gt;2Output:  LinkedList: 8-&gt;8Explanation: First linked list represents 100 and the second one represents 12. 12 subtracted from 100 gives us 88 as the result. It is represented as 8-&gt;8 in the linked list.
Input: LinkedList1: 6-&gt;3, LinkedList2: 7-&gt;1-&gt;0Output: LinkedList: 6-&gt;4-&gt;7Explanation: First linked list represents 63 and the second one represents 710. 63 subtracted from 710 gives us 647 as the result. It is represented as 6-&gt;4-&gt;7 in the linked list.
Constraints:1 ≤ size of both linked lists ≤ 1060 ≤ node-&gt;data ≤ 9