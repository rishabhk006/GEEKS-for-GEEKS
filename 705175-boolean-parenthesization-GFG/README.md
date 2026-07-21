# [Boolean Parenthesization](https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1?page=1&difficulty=Hard&sortBy=submissions)
## Hard
You are given a boolean expression s&nbsp;containing&nbsp;&nbsp;&nbsp; 'T' ---&gt; true&nbsp;&nbsp;&nbsp; 'F' ---&gt; false&nbsp;and following operators between symbols&nbsp; &nbsp;&amp;&nbsp;&nbsp; ---&gt; boolean AND&nbsp;&nbsp;&nbsp; |&nbsp;&nbsp; ---&gt; boolean OR&nbsp; &nbsp;^&nbsp;&nbsp; ---&gt; boolean XORCount the number of ways we can parenthesize the expression so that the value of expression evaluates to true.
Note: The answer is guaranteed to fit within a 32-bit integer.
Examples:
Input: s = "T|T&amp;F^T"
Output: 4
Explaination: The expression evaluates to true in 4 ways: ((T|T)&amp;(F^T)), (T|(T&amp;(F^T))), (((T|T)&amp;F)^T) and (T|((T&amp;F)^T)).
Input: s = "T^F|F"
Output: 2
Explaination: The expression evaluates to true in 2 ways: ((T^F)|F) and (T^(F|F)).
Constraints:1 ≤ |s| ≤ 100&nbsp;