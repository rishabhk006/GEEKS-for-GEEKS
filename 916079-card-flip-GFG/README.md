# [Card Flip](https://www.geeksforgeeks.org/problems/card-flip--150358/1?page=12&difficulty=Hard&sortBy=submissions)
## Hard
You are given n cards arranged in a row. Each card has a number on the front and back, represented by two integer arrays front[] and back[]. For the i-th card, front[i] is the number on the front and back[i] is the number on the back.&nbsp;Initially, all cards are placed with their front side visible.
You can perform the following operation on the cards.

Choose any card at position i (1 ≤ i &lt; n) and swap it with the card at position (i+1).
After swapping, flip both cards so that the opposite side becomes visible.

Determine the minimum number of operations required to arrange the cards such that the numbers on the visible sides are in non-decreasing order. If arranging the cards in non-decreasing order is impossible, return -1.
Examples:
Input: front[] = [4, 1, 3], back[] = [2, 1, 6]Output: 1Explanation: The current visible numbers are 4, 1, 3. If we choose i = 1, we would swap i = 1 and i = 2 and then flip the cards. Now the current visible numbers are 1, 2, 3 which are in non-decreasing order. Hence, in one operation the cards are placed in non-decreasing order.
Input: front[] = [2, 1], back[] = [4, 5]Output: -1Explanation: We can't make the visible side of cards non-decreasing in any number of operations.
Constraints:

1 ≤ n ≤ 16
1 ≤ front[i] ≤ 30
1 ≤ back[i] ≤ 30
