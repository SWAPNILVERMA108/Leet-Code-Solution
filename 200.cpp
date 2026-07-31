class Solution {
public:
int m,n;

void dfs(vector<vector<char>> & grid,int row , int col){
    if(row<0 || row>=n  || col<0 || col>=m){
        return;
    }
    if(grid[row][col] == '0'){
        return;
    }
    grid[row][col]='0';
    dfs(grid,row-1,col);
    dfs(grid,row+1,col);
    dfs(grid,row,col-1);
    dfs(grid,row,col+1);


}
    int numIslands(vector<vector<char>>& grid) {

        n = grid.size();
        m= grid[0].size();

        int islands=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    islands++;
                    dfs(grid,i,j);
                }
            }
        }
        return islands;

        
    }
};