class Solution {
public:
    string convert(string s, int n) {
        if(n==1) return s;
        vector<string> rows(min(n, int(s.size())));
        int curRow = 0;
        bool down = false;
        
        for (char c : s) {
            rows[curRow] += c;
            if(curRow == 0 or curRow == n-1) down = !down;
            curRow += down ? 1 : -1;
            
        }
        string ans;
        for(auto row : rows) ans += row;
        return ans;
    }
};