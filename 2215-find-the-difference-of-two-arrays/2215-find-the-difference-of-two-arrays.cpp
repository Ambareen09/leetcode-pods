class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;

        for(int i:nums1)
            m[i] = 1;
        
        for(int i:nums2)
            m[i] = 2;

        vector<int> v;
        for(auto i:m){
            if(i.second == 1)
                v.push_back(i.first);
        }
        
        for(int i:nums1)
            m[i] = 1;
        
        vector<int> v2;
        for(auto i:m){
            if(i.second == 2)
                v2.push_back(i.first);
        }

        vector<vector<int>> ans;
        ans.push_back(v);
        ans.push_back(v2);
        return ans;
    }
};