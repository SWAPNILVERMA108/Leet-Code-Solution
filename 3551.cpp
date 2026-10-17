class Solution {
public:

    int getDigitSum(int num){
        int sum =0;

        while(num>0){
            sum += (num%10);
            num /= 10;

        }
        return sum ;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<int> afterSort(nums);

        auto lambda = [&](int nums1,int nums2){
            int num1DigitSum = getDigitSum(nums1);
            int num2DigitSum = getDigitSum(nums2);

            if(num1DigitSum != num2DigitSum){
                return num1DigitSum < num2DigitSum;


            }
            return nums1<nums2;
        };

        sort(begin(afterSort),end(afterSort),lambda);


        unordered_map<int,int> valToIdx;
        for(int i = 0 ;i<n;i++){
            valToIdx[nums[i]] = i;

        }

        int swapCnt = 0 ;

        for(int i =0; i<n;i++){
            int expectedVal = afterSort[i];
            int currVal = nums[i];


            if(expectedVal == currVal){
                continue;
            }
            int idx = valToIdx[expectedVal];

            nums[i]= expectedVal;
            nums[idx]= currVal;

            valToIdx[expectedVal] = i;
            valToIdx[currVal]= idx;
            swapCnt++;

        }
        return swapCnt;
        
    }
};