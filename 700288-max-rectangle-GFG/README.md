# [Max rectangle](https://www.geeksforgeeks.org/problems/max-rectangle/1?page=2&difficulty=Hard&sortBy=submissions)
## Hard
You are given a 2D binary matrix mat[ ][ ], where each cell contains either&nbsp;0 or 1. Your task is to find the maximum area of a rectangle that can be formed using only 1's&nbsp;within the matrix.
Examples:
Input: mat[][] = [[0, 1, 1, 0],
                [1, 1, 1, 1],
                [1, 1, 1, 1],
                [1, 1, 0, 0]]
Output: 8
Explanation: The largest rectangle with only 1’s is from (1, 0) to (2, 3) which is
[1, 1, 1, 1]
[1, 1, 1, 1]
and area is 4 * 2 = 8.
Input: mat[][] = [[0, 1, 1],
                [1, 1, 1],
                [0, 1, 1]]
Output: 6
Explanation: The largest rectangle with only 1’s is from (0, 1) to (2, 2) which is
[1, 1]
[1, 1]
[1, 1]and area is 2 * 3 = 6.
Constraints:1 ≤ mat.size(), mat[0].size() ≤10000 ≤ mat[][] ≤1