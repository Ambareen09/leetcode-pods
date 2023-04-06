class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i , int j, int r, int c){
        if(i<0 or j<0 or i>=r or j>=c or grid[i][j] != 0)
            return ;
        
        grid[i][j] = 1;
        
        dfs(grid, i+1, j, r, c);
        dfs(grid, i-1, j, r, c);
        dfs(grid, i, j+1, r, c);
        dfs(grid, i, j-1, r, c);
    }
    
    
    int closedIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        if(r==0) return 0;
        
        for(int i=0;i<r;i++){
            int j=0;
            if(grid[i][j] == 0)
                dfs(grid, i, j, r, c);
            j = c-1;
            if(grid[i][j] == 0)
                dfs(grid, i, j, r, c);
            
        }
        for(int j=0;j<c;j++){
            int i=0;
            if(grid[i][j] == 0)
                dfs(grid, i, j, r, c);
            i = r-1;
            if(grid[i][j] == 0)
                dfs(grid, i, j, r, c);
            
        }
        int ans = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==0){ 
                    ans++;
                    (dfs(grid, i, j, r, c));}
            }
        
    }
        return ans;
    }
}; 