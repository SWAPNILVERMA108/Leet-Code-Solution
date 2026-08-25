class Solution {
public:

    int gcd(int a, int b){
        while(b){
            int temp = a % b;
            a=b;
            b = temp;
        }
        return a;
    }
    int findGCD(vector<int>& nums) {
        int mn = *min_element(nums.begin(),nums.end());
        int mx = *max_element(nums.begin(),nums.end());
        return gcd(mn,mx);
        
    }
};