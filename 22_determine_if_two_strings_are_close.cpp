/*
Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

 

Example 1:

Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"
Example 2:

Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.
Example 3:

Input: word1 = "cabbba", word2 = "abbccc"
Output: true
Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1: "cabbba" -> "caabbb"
Apply Operation 2: "caabbb" -> "baaccc"
Apply Operation 2: "baaccc" -> "abbccc"
Example 4:

Input: word1 = "cabbba", word2 = "aabbss"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any amount of operations.
 

Constraints:

1 <= word1.length, word2.length <= 105
word1 and word2 contain only lowercase English letters.
*/




class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        if (n1 != n2) return false;
        unordered_set<char> word2Set(word2.begin(), word2.end());
        unordered_map<char, int> freq1, freq2, freqCnt;
        for (char ch : word1) {
            if (word2Set.find(ch) == word2Set.end())
                return false;
            ++freq1[ch];
        }
        for (char ch : word2) {
            if (freq1.find(ch) == freq1.end())
                return false;
            ++freq2[ch];
        }
        for (auto it=freq1.begin(); it!=freq1.end(); ++it)
            ++freqCnt[it->second];
        for (auto it=freq2.begin(); it!=freq2.end(); ++it)
            --freqCnt[it->second];
        for (auto it=freqCnt.begin(); it!=freqCnt.end(); ++it)
            if (it->second) return false;
        return true;
    }
};

