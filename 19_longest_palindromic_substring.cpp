/*
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),
*/




class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), maxLen = 0;
        pair<int, int> substringAttributes;
        for (int i=0; i<n; ++i) {
            vector<pair<int, int>> start = {{i, i}, {i, i+1}};
            for (pair<int, int> lr : start) {
                int left = lr.first, right = lr.second;
                if (right < n) {
                    while (s[left] == s[right]) {
                        if (right-left+1 > maxLen) {
                            maxLen = right-left+1;
                            substringAttributes = {left, maxLen};
                        }
                        --left; ++right;
                        if (left < 0) break;
                        if (right >= n) break;
                    }
                }
            }
        }
        int index = substringAttributes.first;
        int length = substringAttributes.second;
        return s.substr(index, length);
    }
};

