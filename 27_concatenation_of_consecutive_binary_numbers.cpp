/*
Given an integer n, return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order, modulo 109 + 7.

 

Example 1:

Input: n = 1
Output: 1
Explanation: "1" in binary corresponds to the decimal value 1. 
Example 2:

Input: n = 3
Output: 27
Explanation: In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
After concatenating them, we have "11011", which corresponds to the decimal value 27.
Example 3:

Input: n = 12
Output: 505379714
Explanation: The concatenation results in "1101110010111011110001001101010111100".
The decimal value of that is 118505380540.
After modulo 109 + 7, the result is 505379714.
 

Constraints:

1 <= n <= 105
*/




class Solution {
private:
    int mulmod(int a, int b) {
        const int mod = 1e9 + 7;
        int res = 0;
        a %= mod;
        while (b) {
            if (b % 2)
                res = (res + a) % mod;
            a = (a * 2) % mod;
            b /= 2;
        }
        return res % mod;
    }
public:
    int concatenatedBinary(int n) {
        const int mod = 1e9 + 7;
        int concat = 0;
        for (int i=1; i<=n; ++i) {
            int temp = i, steps = 0;
            while (temp) {
                temp /= 2;
                ++steps;
            }
            concat = mulmod(concat, 1 << steps) + i;
            concat %= mod;
        }
        return concat;
    }
};

