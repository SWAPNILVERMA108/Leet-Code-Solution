class Solution {
public:

    void nQueens(int row, int n ,vector<bool>& cols,vector<bool> & dig1, vector<bool> dig2, vector<string> & board , vector<vector<string>> & result){
        if(row == n){
            result.push_back(board);
            return;
        }

        for(int col = 0;col<n;col++){
            int d1 = row-col + n - 1;
            int d2 = row + col;

            if(cols[col]||dig1[d1]||dig2[d2]) continue;

            board[row][col]='Q';
            cols[col]=dig1[d1]=dig2[d2]=true;

            nQueens(row+1, n , cols, dig1,dig2 , board, result);

            board[row][col]='.';

            cols[col]=dig1[d1]=dig2[d2] = false;
            

        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));    
    
        vector<bool> cols(n, false);
        vector<bool> dig1(2 * n - 1, false);
        vector<bool> dig2(2 * n - 1, false);

        vector<vector<string>> result;

        nQueens(0, n, cols, dig1, dig2, board, result);

        return result;
        
    }
};