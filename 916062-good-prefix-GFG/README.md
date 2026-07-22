# [Good Prefix](https://www.geeksforgeeks.org/problems/good-prefix--130942/1?page=12&difficulty=Hard&sortBy=submissions)
## Hard
You are given an integer array arr[] and an integer k. 
Define F(x, len) as the count of&nbsp;occurrences&nbsp;of x in prefix of given array arr1, arr2, . . ., arrlen. 
A prefix of length len is&nbsp;considered&nbsp;good if, for every integers x and y of the given array such that x&nbsp;≤&nbsp;y, following condition holds : F(y, len) - F(x, len) ≤ k.
Your task is to find the length of the longest good prefix such that every smaller prefix of arr[]&nbsp;is also "good".
Examples:
Input: arr[] = [1, 2, 2, 1, 3], k = 1
Output: 5
Explanation: The longest good prefix is the entire array because all prefixes with lengths from 1 to 5 are good.
Input: arr[] = [1, -2, -1, 2], k = 0Output: 0
Explanation: For len = 1, take x = -2 and y = 1. Then F(y,len) = 1 and F(x,len) = 0, so F(y,len) - F(x,len) &gt; k, and prefix is not good. Hence answer is 0.
Constraints:

1 ≤ arr.size() ≤ 105
10-9 ≤ arr[i] ≤ 109
0 ≤ k ≤ arr.size()
