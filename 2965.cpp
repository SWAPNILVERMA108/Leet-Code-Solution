class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> freq(n*n +1,0);

        for(auto row: grid){
            for(auto val :row){
                freq[val]++;
            }
        }
        int repeated =-1;
        int missing = -1;
        for(int i=1;i<=n*n;i++){
            if(freq[i]==2){
                repeated =i;
            }
            if(freq[i]==0){
                missing = i;
            }
        }
        return {repeated , missing};



    }
};