class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int maxlenth = 0;
        int zeros = 0;

        while (r < nums.size()) {
            if (nums[r] == 0) {
                zeros++;
            }

            while (zeros > k) {
                if (nums[l] == 0) {
                    zeros--;
                }
                l++; 
            }

            int len = r - l + 1;
            maxlenth = max(maxlenth, len);
            r++;
        }

        return maxlenth;
    }
};