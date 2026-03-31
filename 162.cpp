// Find Peak Element (Brute Force Approach)

// Instructions : Not for leetcode submission, just for understanding the concept of brute force approach.

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if ((i == 0 || nums[i] > nums[i - 1]) &&
                (i == n - 1 || nums[i] > nums[i + 1])) {
                return i;
            }
        }

        return -1;
    }
};