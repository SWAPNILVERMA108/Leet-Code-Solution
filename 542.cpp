// brute force solution

// class Solution {
// public:
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         int n =mat.size();
//         int m= mat[0].size();
//         vector<vector<int>>ans(n,vector<int>(m,0));
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(mat[i][j]==0){
//                     ans[i][j]=0;
//                 }else{
//                     int mini = INT_MAX;
//                     for(int x=0;x<n;x++){
//                         for(int y=0;y<m;y++){
//                             if(mat[x][y]==0){
//                                 int dist = abs(i-x)+abs(j-y);
//                                 mini = min(mini,dist);

//                             }
//                         }
//                     }
//                     ans[i][j]=mini;
//                 }
//             }
//         }
//         return ans;
        
//     }
// };