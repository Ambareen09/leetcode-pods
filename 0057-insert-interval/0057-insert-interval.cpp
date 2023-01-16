class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& newInterval) {
        in.push_back(newInterval);
        sort(in.begin(), in.end());
        vector<vector<int>> ans;
        vector<int> temp = in[0];
        
        for(int i=1;i<in.size();i++){
            if(in[i][0] <= temp[1]){
                int mx = max(in[i][1], temp[1]);
                temp[1] = mx;
            }
            else{
                ans.push_back(temp);
                temp = in[i];
            }
        }
        
        ans.push_back(temp);
        
        return ans;
    }
};