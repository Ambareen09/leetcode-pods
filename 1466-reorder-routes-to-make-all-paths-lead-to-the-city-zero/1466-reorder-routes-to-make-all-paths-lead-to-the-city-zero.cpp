class Solution {
public:
    void dfs(int u, vector<int> adj[], vector<int>&vis, set<pair<int, int>>&st, int n, int &c){
        vis[u] = 1;
        
        for(auto i : adj[u]){
            if(vis[i]==1) continue;
            if(st.find({u, i}) != st.end()) c++;
            dfs(i, adj, vis, st, n, c);
        }
    }
    
    
    int minReorder(int n, vector<vector<int>>& graph) {
        set<pair<int, int>> st;
        vector<int> adj[n];
        
        for(int i=0;i<graph.size();i++){
            int u = graph[i][0];
            int v = graph[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            st.insert({u, v});
        }
        
        vector<int> vis(n, 0);
        int c = 0;
        dfs(0, adj, vis, st, n, c);
        
        return c;
    }
};