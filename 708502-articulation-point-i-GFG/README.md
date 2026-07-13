# [Articulation Point - I](https://www.geeksforgeeks.org/problems/articulation-point-1/1?page=2&difficulty=Hard&sortBy=submissions)
## Hard
Given an undirected connected graph&nbsp;with&nbsp;V&nbsp;vertices and adjacency list&nbsp;adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components and return it in sorted manner.Note:&nbsp;Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.
Example 1:
Input:

Output:{1,4}
Explanation: Removing the vertex 1 will
discconect the graph as-

Removing the vertex 4 will disconnect the
graph as-


&nbsp;
Your Task:You don't need to read or print anything. Your task is to complete the function&nbsp;articulationPoints()&nbsp;which takes V and adj as input parameters and returns a list containing all the vertices removing which turn the graph into two or more disconnected components in sorted order. If there are no such vertices then returns a list containing -1.&nbsp;
Expected Time Complexity:&nbsp;O(V + E)Expected Auxiliary Space:&nbsp;O(V)&nbsp;
Constraints:1 ≤ V ≤ 105