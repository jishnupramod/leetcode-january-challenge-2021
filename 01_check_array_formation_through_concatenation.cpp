/*
You are given an array of distinct integers arr and an array of integer arrays pieces, where the integers in pieces are distinct. Your goal is to form arr by concatenating the arrays in pieces in any order. However, you are not allowed to reorder the integers in each array pieces[i].

Return true if it is possible to form the array arr from pieces. Otherwise, return false.

 

Example 1:

Input: arr = [85], pieces = [[85]]
Output: true
Example 2:

Input: arr = [15,88], pieces = [[88],[15]]
Output: true
Explanation: Concatenate [15] then [88]
Example 3:

Input: arr = [49,18,16], pieces = [[16,18,49]]
Output: false
Explanation: Even though the numbers match, we cannot reorder pieces[0].
Example 4:

Input: arr = [91,4,64,78], pieces = [[78],[4,64],[91]]
Output: true
Explanation: Concatenate [91] then [4,64] then [78]
Example 5:

Input: arr = [1,3,5,7], pieces = [[2,4,6,8]]
Output: false
 

Constraints:

1 <= pieces.length <= arr.length <= 100
sum(pieces[i].length) == arr.length
1 <= pieces[i].length <= arr.length
1 <= arr[i], pieces[i][j] <= 100
The integers in arr are distinct.
The integers in pieces are distinct (i.e., If we flatten pieces in a 1D array, all the integers in this array are distinct).
*/




// O(nlogn)
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> mp;
        for (int i=0; i<arr.size(); ++i) 
            mp[arr[i]] = i;
        sort(pieces.begin(), pieces.end(), [&](vector<int> a, vector<int> b) {
            return mp[a[0]] < mp[b[0]];
        });
        vector<int> pieces1D;
        for (vector<int>& piece : pieces) {
            for (int i : piece) pieces1D.push_back(i);
        }
        return pieces1D == arr;
    }
};




// O(n)
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> mp;
        for (int i=0; i<arr.size(); ++i)
            mp[arr[i]] = i + 1;
        for (vector<int>& p : pieces) {
            if (p.size() > 1) {
                for (int i=0; i<p.size()-1; ++i) {
                    if (mp[p[i+1]] < mp[p[i]])
                        return false;
                }
            }
        }
        for (vector<int>& p : pieces)
            for (int i : p)
                if (!mp[i]) return false;
        return true;
    }
};

