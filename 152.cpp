// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int maxi = nums[0];
//         int mini = nums[0];
//         int ans = nums[0];
//         for(int i =1;i<nums.size();i++){
//             if(nums[i]<0){
//                 swap(maxi,mini);
//             }
//             maxi = max(nums[i],maxi*nums[i]);

//             mini = min(nums[i],mini*nums[i]);   
//             ans = max(ans,maxi);
//         }
//         return ans;

        
//     }
// };


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int pre = 1;
        int suff = 1;
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            if (pre == 0)
                pre = 1;
            if (suff == 0)
                suff = 1;

            pre = pre * nums[i];
            suff = suff * nums[n - i - 1];

            ans = max(ans, max(pre, suff));
        }
        return ans;
    }
};
