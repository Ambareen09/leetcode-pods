class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> x;
        vector<int> y;
        vector<int> ans;
        
        for(int i=0;i<n;i++) x.push_back(nums[i]);
        for(int i=n;i<2*n;i++) y.push_back(nums[i]);
        
        for(int i=0;i<n;i++){
            ans.push_back(x[i]);
            ans.push_back(y[i]);
        }
        
        return ans;
    }
};