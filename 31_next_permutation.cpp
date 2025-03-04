/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
Example 4:

Input: nums = [1]
Output: [1]
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100
*/




class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), upto = -1, curr;
        for (int i=n-1; i>0; --i) {
            for (int j=i-1; j>upto; --j) {
                if (nums[i] > nums[j]) {
                    curr = i;
                    upto = j;
                }
            }
        }
        if (upto != -1)
            swap(nums[upto], nums[curr]);
        reverse(nums.begin()+upto+1, nums.end());
    }
};

