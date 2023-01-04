class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans=0;
        unordered_map<int,int>mp;
        
        for(auto i : tasks){
            mp[i]++;
        }
        
        for(auto i : mp){
            int k = i.second;
            if(k == 1)return -1;
            
            if(k%3 == 0)
                ans += k/3;
            else 
                ans += (k/3)+1;
        }
     return ans;
    }
};