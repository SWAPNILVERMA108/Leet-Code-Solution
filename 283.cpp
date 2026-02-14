// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         vector<int> temp;
//         for(int i =0;i<nums.size();i++){
//             if(nums[i]!=0){
//                 temp.push_back(nums[i]);
//             }
//         }

//         int nz = temp.size();
//         for(int i =0;i<nz;i++){
//             nums[i]=temp[i];
//         }
//         for(int i=nz;i<nums.size();i++){
//             nums[i]=0;
//         }
        
        
//     }
// };


// Optimal solution

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = 0;  // points to position to place next non-zero

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};

