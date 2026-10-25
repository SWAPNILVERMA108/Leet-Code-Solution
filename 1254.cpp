class Solution {
public:
int m , n;

    bool dfs(vector<vector<int>>& grid,int r, int c){
        if(r>=m || r<0 || c>=n || c<0 ){
            return false;
        }

            if(grid[r][c]==1){
                return true;
            }


    grid[r][c]=1;
    bool left_closed = dfs(grid,r,c-1);
    bool right_closed = dfs(grid,r,c+1);
    bool up_closed = dfs(grid,r-1,c);
    bool down_closed = dfs(grid,r+1,c);

    return up_closed && right_closed && left_closed && down_closed;
        
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int cnt =0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j]==0){
                    if(dfs(grid,i,j)==true){
                        cnt++;
                    }
                }
            }
        }

        return cnt;
        
    }
};