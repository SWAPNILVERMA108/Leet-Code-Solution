class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool check = n>0 && (n & (n-1))==0;
        if(check){
            return true;
        }
        else{
            return false;
        }

        
    }
};