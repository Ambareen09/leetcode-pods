class Solution {
public:
    int countOdds(int low, int high) {
        int ans = (high - low)/2;
        if(low%2 or high%2) ans++;
        return ans;
    
    }
};