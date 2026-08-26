class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans=0;
        for(long long i=1;i*(i+1)/2<=n;i++){
            long long rem = n - i*(i-1)/2; 

            if(rem%i==0){
                ans++;
            }
        }

        return ans;
        
        
    }
};