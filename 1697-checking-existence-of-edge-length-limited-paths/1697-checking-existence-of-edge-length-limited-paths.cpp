class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[2]<b[2];
    }
    int find(int node,vector<int>& parent){
        if(node==parent[node]) return node;
        return parent[node]=find(parent[node],parent);
    }
    void Union(int u,int v,vector<int>& parent,vector<int>& size){
        u=find(u,parent);
        v=find(v,parent);
        if(u==v) return;
        if(size[v]>size[u]){
            parent[u]=v;
            size[v]+=size[u];
        }
        else{
            parent[v]=u;
            size[u]+=size[v];
        }
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<bool> ans(queries.size());
        vector<int> parent(n),size(n);

        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
        sort(edgeList.begin(),edgeList.end(),cmp);

        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }

        sort(queries.begin(),queries.end(),cmp);
        int j=0;
        for(int i=0;i<queries.size();i++){
            for(;j<edgeList.size() and edgeList[j][2]<queries[i][2];j++){
                Union(edgeList[j][0],edgeList[j][1],parent,size);
            }
            if(find(queries[i][0],parent)==find(queries[i][1],parent)){
                ans[queries[i][3]]=true;
            }
            else ans[queries[i][3]]=false;
        }

        return ans;
    }
};