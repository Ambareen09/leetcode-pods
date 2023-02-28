class Solution {
public:
    void f(vector<int>& nums,vector<vector<int>> &ans, vector<int> temp, int n ,int i, int target, int t){
        if(t == target){
            
            ans.push_back(temp);
            return;
        }
        
        if(t > target or i >=n) return;
        
        temp.push_back(nums[i]);
        f(nums, ans, temp, n, i,target,  t+nums[i]);
        
        temp.pop_back();
        f(nums, ans, temp, n, i+1,target, t);
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        
        f(nums,ans, temp, n, 0, target, 0);
        
        return ans;
    }
};