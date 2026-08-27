class Solution {
public:

    vector<int>getFreq(int n){
        vector<int> freq(10,0);
        while(n>0){
            int digit = n%10;
            freq[digit]++;
            n /=10;
        }
        return freq;

    }
    bool reorderedPowerOf2(int n) {

        vector<int>target = getFreq(n);
        for(int i=0;i<=30;i++){
            int power = 1<<i;

            if(getFreq(power)==target){
                return true;
            }

        }
        return false;
        
    }
};