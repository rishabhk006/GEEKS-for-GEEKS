# [Wildcard string matching](https://www.geeksforgeeks.org/problems/wildcard-string-matching1126/1?page=3&difficulty=Hard&sortBy=submissions)
## Hard
Given two strings wild and pattern. Determine if the given two strings can be matched given that, wild string may contain * and ? but string pattern will not.&nbsp;*&nbsp;and ? can be converted to another character according to the following rules:
* --&gt; This character in string wild can be replaced by any sequence of characters, it can also be replaced by an empty string.
? --&gt; This character in string wild can be replaced by any one character.
Example 1:
Input: wild = ge*kspattern = geeks
Output: Yes
Explanation: Replace the '*' in wild string 
with 'e' to obtain pattern "geeks".
Example 2:
Input: wild = ge?ks*pattern = geeksforgeeks
Output: Yes
Explanation: Replace '?' and '*' in wild string with
'e' and 'forgeeks' respectively to obtain pattern 
"geeksforgeeks"

Your Task:You don't need to read&nbsp;input or print anything. Your task is to&nbsp;complete the function match() which takes&nbsp;the string wild and pattern as input parameters and returns true if the string wild can be made equal to the string pattern, otherwise, returns&nbsp;false.
Expected Time Complexity: O(length of wild string *&nbsp;length of pattern string)Expected Auxiliary Space: O(length of wild string *&nbsp;length of pattern string)
Constraints:1 &lt;= length of the two string &lt;= 10^3&nbsp;