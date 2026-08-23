class Solution {
public:

    typedef long long ll;

    ll countSmaller(ll mid,vector<int>& coins){
        ll correctedCount = 0;
        int n = coins.size();

        for(int expression =1;expression <= (1<<n)-1;expression++){
            ll lcm =0;
            ll order = 0;

            for(int i=0;i<n;i++){
                if(expression & (1<<i)){
                    order++;

                    if(lcm==0){
                        lcm = coins[i];
                    }else{
                        lcm = lcm * coins[i] /gcd(lcm, coins[i]);
                    }

                }
            }
            if(order%2==0){
                correctedCount -= mid/lcm;
            }else{
                correctedCount +=mid/lcm;
            }
        }
        return correctedCount;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        ll result = -1;
        
        ll l = 1;
        ll r = (ll)(*max_element(begin(coins),end(coins)))*k;

        while(l<=r){
            ll mid = l+(r-l)/2;

            if(countSmaller(mid,coins) >= k){
                result = mid;
                r = mid-1;

            } else{
                l = mid+1;
            }

        }
        return result;

        
    }
};