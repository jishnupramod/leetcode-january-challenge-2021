/*
Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/




// Using deque
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        deque<char> sub;
        unordered_map<char, int> indexMap;
        int n = s.length(), maxLen = 0;
        for (int i=0; i<n; ++i) {
            sub.push_back(s[i]);
            if (!indexMap[s[i]]) {
                ++indexMap[s[i]];
            } else {
                char rem = s[i];
                while (sub.front() != rem) {
                    --indexMap[sub.front()];
                    sub.pop_front();
                }
                sub.pop_front();
            }
            int sz = sub.size();
            maxLen = max(maxLen, sz);
        }
        return maxLen;
    }
};




// Two pointers
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> cnts;
        int fnc = 0, lnc = 0, len = 0;
        while (lnc < s.length()) {
            if (cnts[s[lnc]] == 1) {
                --cnts[s[lnc]];
                len = max(len, lnc-fnc);
                while (s[fnc] != s[lnc]) {
                    --cnts[s[fnc]];
                    ++fnc;
                }
                ++fnc;
            }
            ++cnts[s[lnc]];
            ++lnc;
        }
        return max(len, lnc-fnc);
    }
};
