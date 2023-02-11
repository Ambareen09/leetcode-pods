using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>>redAdjList(n);
        vector<vector<int>>blueAdjList(n);

        for(auto &it: redEdges) {
            redAdjList[it[0]].push_back(it[1]);
        }
        for(auto &it: blueEdges) {
            blueAdjList[it[0]].push_back(it[1]);
        }

        vector<vector<int>>distance(n, vector<int>(2, INT_MAX));
        distance[0][0] = 0;
        distance[0][1] = 0;

        queue<pair<int,int>>q; 

        q.push({0,0}); 
        q.push({0,1});

        while(!q.empty()) {
            int node = q.front().first;
            int color = q.front().second;
            q.pop();

            int otherColor = 1 - color;

            if(otherColor == 0) {
                for(auto it: redAdjList[node]) {
                    if(distance[it][otherColor] == INT_MAX) {
                        distance[it][otherColor] = distance[node][color]+1;
                        q.push({it, otherColor}); 
                    }
                }
            } else {
                for(auto it: blueAdjList[node]) {
                    if(distance[it][otherColor] == INT_MAX) {
                        distance[it][otherColor] = distance[node][color] + 1;
                        q.push({it, otherColor});
                    }
                }
            }
        }

        vector<int>ans(n);

        for(int i = 1; i < n; i++) {
            int num = min(distance[i][0], distance[i][1]);
            ans[i] = num == INT_MAX ? -1 : num;
        }

        return ans;
    }
};