class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        queue<pair<int,int>> q;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 1) q.push({i,j});
            }
        }
        int dist = -1;
        while(!q.empty()){
            dist++;
            int x = q.size();
            for(int i = 0 ; i < x ; i++){
                auto [r,c] = q.front();
                q.pop();
                for(int di = 0 ; di < 4 ; di++){
                    int nr = r+dy[di];
                    int nc = c+dx[di];
                    if(nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == 0) {
                        grid[nr][nc] = 1;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return dist == 0 ? -1 : dist; 
    }
};