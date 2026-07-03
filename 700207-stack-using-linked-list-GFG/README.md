# [Stack using Linked List](https://www.geeksforgeeks.org/problems/implement-stack-using-linked-list/1?page=2&category=Linked%20List&sortBy=submissions)
## Easy
Implement a Stack using a Linked List. The stack has dynamic size and can grow until memory is available.The Stack must support the following operations:
(i)&nbsp;push(x):&nbsp;Insert an element x at the top of the stack.(ii)&nbsp;pop():&nbsp;Remove the element from the top of the stack.(iii)&nbsp;peek():&nbsp;Return top element if not empty, else -1.(iv)&nbsp;isEmpty():&nbsp;Return true if the stack is empty else return false.(v)&nbsp;size():&nbsp;Return the number of elements currently in the stack.
There will be a sequence of queries&nbsp;queries[][] in numeric form:&nbsp;

1 x : Call push(x)
2: Call pop()
3: Call peek()
4: Call isEmpty()
5: Call size()

Implement only the functions push, pop, peek, isEmpty, and size. The driver code handles input and output.
Examples:
Input: q = 7, queries[][] = [[1, 5], [1, 3], [1, 4], [3], [2], [5], [4]]
Output: [4, 2, false]
Explanation: Queries on queue are as follows:push(5): Insert 5 at the top of the stack.push(3): Insert 3 at the top of the stack.push(4): Insert 4 at the top of the stack.peek(): Return the top element i.e 4.pop(): Remove the top element 4 from the stack.size(): Stack contains 2 elements return 2.isEmpty(): Stack is not empty return false.
Input: q = 4, queries[][] = [[4], [3], [1, 10], [5]]
Output: [true, -1, 1]
Explanation: Queries on queue are as follows:isEmpty(): Stack is empty return true.peek(): Stack is empty return -1.push(10): Insert 10 at the top of the stack.size(): Stack contains 1 element return 1.
Constraints:1 ≤ number of query ≤ 1030 ≤ x&nbsp;≤ 105