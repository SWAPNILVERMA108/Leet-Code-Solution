class Solution {
public:

    vector<vector<int>>ans;
    vector<int>subset;

    void solve(int index,vector<int> & nums){
        if(index==nums.size()){
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        solve(index+1,nums);

        subset.pop_back();

        solve(index+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(0,nums);
        return ans;
        
    }
};