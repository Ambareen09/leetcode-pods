class Solution {
    #define ll long long
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int>ans;
        
        for(int i = 0; i < spells.size(); i++){
            
            int d = 0;
            ll g = success/spells[i];
            
            if(success%spells[i]) g++;
            
            int f = lower_bound(potions.begin(),potions.end(), g) - potions.begin();
            d += potions.size()-f;
            ans.push_back(d);
        }
        return ans;
    }
};