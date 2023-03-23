class Solution {
public:
    void dfs(vector<vector<int>> &adj, int s, vector<bool> &vis){
        vis[s] = true;
        for(auto u : adj[s])
        {
            if(vis[u] == false)
                dfs(adj, u, vis);
        }
    }
    
    
    
    int makeConnected(int n, vector<vector<int>>& c) {
        int e = c.size();
        if(e < n-1) return -1;
        vector<vector<int>> adj(n);
        for(int i = 0; i<e;i++){
            adj[c[i][0]].push_back(c[i][1]);
            adj[c[i][1]].push_back(c[i][0]);
                
            }
        vector<bool> vis(e, false);
        int ans = 0;
        
        for(int i=0;i<n;i++){
            if(vis[i] == false){
                dfs(adj, i, vis);
                ans++;
                }
                
        }
        return ans-1;
    }
};