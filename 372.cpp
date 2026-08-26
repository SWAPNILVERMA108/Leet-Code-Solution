class Solution {
public:

    const int mod = 1337;

    int modPow(int a , int k){
        int res = 1;
        a%= mod;
        while(k){
            if(k&1){
                res = (res*a)%mod;
                
            }
            a = (a*a)%mod;
                k >>=1;
        }
        return res;
    }
    int superPow(int a, vector<int>& b) {
        
        int res = 1;
        for(int digit: b){
            res = modPow(res,10);
            res = (res*modPow(a,digit))%mod;
        }
        return res;
    }
};