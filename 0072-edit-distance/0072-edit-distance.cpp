class Solution {
public:
    int solve(string &s,string &t,int i,int j,vector<vector<int>> &dp)
    {
        
        if(i<0) return j+1;
        if(j<0) return i+1;
        
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==t[j]) return dp[i][j]= solve(s,t,i-1,j-1,dp);

        return dp[i][j]= 1+ min(min(solve(s,t,i-1,j,dp), solve(s,t,i,j-1,dp)), solve(s,t,i-1,j-1,dp));
    }
    
    
    
    int minDistance(string s, string t) {
        int m=s.size();
        int n=t.size();

        vector<vector<int>> dp(m+1,vector<int>(n+1, -1));
        return solve(s, t, m - 1, n - 1,dp);
    }
};