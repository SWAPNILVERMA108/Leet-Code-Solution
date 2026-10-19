// class Solution {
// public:
//     vector<int> targetIndices(vector<int>& nums, int target) {
//         sort(nums.begin(),nums.end());
//         vector<int>idx;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==target){
//                 idx.push_back(i);
//             }
            
//         }

//         return idx;
        
//     }
// };


// Approch 2



class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int small=0;
        int trgt = 0;

    vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<target){
                small++;
            }else if(nums[i]==target){
                trgt++;
            }
        }

        for(int i=small;i<small+trgt;i++){
            ans.push_back(i);

        }
        return ans;
        
    }
};