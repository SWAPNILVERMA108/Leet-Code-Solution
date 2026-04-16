// 904 : Fruit Into Baskets
// Brute Force Approach : not for leetcode submission ( Time Limit Exceeded ) so use my given optimal approach below

// class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {
//         int maxlen =0;
//         int n = fruits.size();
//         for(int i=0;i<n;i++){
//             set<int>st;
//             for(int j=i;j<n;j++){
//                 st.insert(fruits[j]);
//                 if(st.size()<=2){
//                     maxlen = max(maxlen,j-i+1);
//                 }
//                     else{
//                         break;
            
//                 }
//             }
//         }
//         return maxlen;
        
//     }
// };


// Optimal Approach : Sliding Window Technique

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0;
        int maxlen=0;
        unordered_map<int,int> mp;

        for(int r=0;r<fruits.size();r++){
            mp[fruits[r]]++;

            while(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            maxlen = max(maxlen,r-l+1);
        }
        return maxlen;

    }
};