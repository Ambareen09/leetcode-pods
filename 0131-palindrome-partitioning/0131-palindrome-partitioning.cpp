class Solution {
public:
    bool isPalindrome(string s, int ind, int i) {
       while(ind <= i) {
           if(s[ind++] != s[i--]) return false; 
       }
        return true;
        
    }
void f(int ind, string s, vector<string>&temp, vector<vector<string>>&ans, int n) {
        if(ind == n){
            ans.push_back(temp);
            return;
        }
        for(int i=ind; i<n;i++){
            if(isPalindrome(s, ind, i)){
                
                temp.push_back(s.substr(ind, i-ind+1));
                f(i+1, s, temp, ans, n);
                temp.pop_back();
            }}}
vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        int n  = s.length();
        f(0, s, temp, ans, n);
        return ans;
    }
};