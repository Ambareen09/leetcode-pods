class Solution {
public:
    bool bfs(int s, vector<vector<int>>& graph,vector<int> &color){
        queue<int> q;
        q.push(s);
        color[s] = 1;
        
        while(!q.empty()){
            int v = q.front();
            q.pop();
            
            for(auto u : graph[v]){
                if(color[u] == -1){
                    color[u] = 1-color[v];
                    q.push(u);
                }
                else if(color[u] == color[v])
                    return false;
            }
         }
        return true;
    }   
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color (n, -1);
        
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(!bfs(i, graph, color))
                    return false;
            }
        }
        return true;
    }
};