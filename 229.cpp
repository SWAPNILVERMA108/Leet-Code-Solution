//better approach

// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         vector<int>ls;
//         map<int,int>mpp;
//         int n = nums.size();
//         int mini = (int)(n/3)+1;
//         for(int i =0;i<n;i++){
//             mpp[nums[i]]++;
//             if(mpp[nums[i]]==mini){
//                 ls.push_back(nums[i]);


//             }
//             if(ls.size()==2){
//                 break;

//             }

//         }
//         sort(ls.begin(),ls.end());
//         return ls;

        
        

//     }
// };



// Optimal approach

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;

        // Boyer Moore Voting
        for (int i = 0; i < nums.size(); i++) {

            if (cnt1 == 0 && nums[i] != el2) {
                el1 = nums[i];
                cnt1 = 1;
            }

            else if (cnt2 == 0 && nums[i] != el1) {
                el2 = nums[i];
                cnt2 = 1;
            }

            else if (nums[i] == el1) cnt1++;

            else if (nums[i] == el2) cnt2++;

            else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == el1) cnt1++;
            if (nums[i] == el2) cnt2++;
        }

        vector<int> ls;
        int n = nums.size();
        int mini = (n / 3) + 1;

        if (cnt1 >= mini) ls.push_back(el1);
        if (cnt2 >= mini) ls.push_back(el2);

        sort(ls.begin(), ls.end());

        return ls;
    }
};