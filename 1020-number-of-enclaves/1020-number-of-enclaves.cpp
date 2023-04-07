class Solution {
public:
    void dfs(vector<vector<int>> &board,int row,int col)
    {
        if(row<0 || row>=board.size() || col<0 || col>=board[0].size() || board[row][col] != 1) return;
        board[row][col] = 0;
		
        dfs(board,row+1,col);
        dfs(board,row-1,col);
        dfs(board,row,col+1);
        dfs(board,row,col-1);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0; i<n ; i++){
            int j =0 ;
            if(grid[i][j] == 1)
                dfs(grid, i , j);
            j =m-1 ;
            if(grid[i][j] == 1)
                dfs(grid, i , j);
        }
        for(int j = 0; j<m ; j++){
            int i =0 ;
            if(grid[i][j] == 1)
                dfs(grid, i , j);
            i =n-1 ;
            if(grid[i][j] == 1)
                dfs(grid, i , j);
        }
        int ans = 0;
        for(auto i : grid)
            for(auto j : i)
                if (j == 1)ans++;
        return ans;
    }
};