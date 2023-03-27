class Solution {
public:
    int f(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<int>> &dp){
        if(i>=m or j>=n) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        if(i==m-1 and j==n-1) return grid[i][j];
        
        int right = f(grid, i+1, j, m, n, dp);
        int down = f(grid, i, j+1, m, n, dp) ;
        
        return dp[i][j] =  grid[i][j] +  min(right, down);
    }
    
    
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return f(grid, 0, 0, m, n, dp);
        
    }
};