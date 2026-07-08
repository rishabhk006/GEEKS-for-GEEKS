# [Huffman Encoding](https://www.geeksforgeeks.org/problems/huffman-encoding3345/1?page=2&difficulty=Hard&sortBy=submissions)
## Hard
Given a string&nbsp;s of distinct characters and their corresponding frequency f[ ] i.e. character s[i] has f[i] frequency. You need to build the Huffman tree and return all the huffman codes in preorder traversal of the tree.Note: While merging, if two nodes have the same value (frequency), then the node whose subtree contains the character that appears earlier in the string s will be taken on the left of the Binary Tree and the other one to the right. Otherwise, the node with smaller value will be taken on the left of the subtree and the other one to the right.
Examples:
Input: s = "abcdef", f[] = {5, 9, 12, 13, 16, 45}
Output: [0, 100, 101, 1100, 1101, 111]
Explanation:
HuffmanCodes will be:
f : 0
c : 100
d : 101
a : 1100
b : 1101
e : 111
Constraints:1 ≤ s.size() = f.size() ≤ 26