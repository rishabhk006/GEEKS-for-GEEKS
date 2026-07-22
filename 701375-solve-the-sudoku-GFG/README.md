# [Solve the Sudoku](https://www.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1?page=2&difficulty=Hard&sortBy=submissions)
## Hard
Given an&nbsp;incomplete&nbsp;Sudoku&nbsp;in the form of matrix mat[][] of order 9*9, the task is to solve the Sudoku.&nbsp;It is guaranteed that the input Sudoku will have exactly one solution.
A sudoku solution must satisfy&nbsp;all of the following rules:

Each of the digits&nbsp;1-9&nbsp;must occur exactly once in each row.
Each of the digits&nbsp;1-9&nbsp;must occur exactly once in each column.
Each of the digits&nbsp;1-9 must occur exactly once in each of the 9,&nbsp;3x3&nbsp;sub-boxes of the grid.

Note: Zeros represent blanks to be filled with numbers 1-9, while non-zero cells are fixed and cannot be changed.
Examples:
Input: mat[][] = 

Output:
Explanation: Each row, column and 3 x 3 box of the output matrix contains unique numbers.
Input: mat[][] = 
Output:Explanation: Each row, column and 3 x 3 box of the output matrix contains unique numbers.
Constraints:0 ≤ mat[i][j] ≤ 9