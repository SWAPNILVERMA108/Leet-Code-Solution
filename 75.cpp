class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0=0;
        int cnt1 =0;
        int cnt2=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                cnt0++;

            }else if(nums[i]==1){
                cnt1++;
            }
            else{
                cnt2++;
            }
        }
        int ind=0;
        for(int i=0;i<cnt0;i++){
            nums[ind++]=0;
        }
        for(int i=0;i<cnt1;i++){
            nums[ind++]=1;
        }
        for(int i=0;i<cnt2;i++){
            nums[ind++]=2;
        }
        
    
    }
};


// Optimal approch

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n = nums.size();

        int low = 0;
        int mid = 0;
        int high = n-1;

        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
        
    
    }
};