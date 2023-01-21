class Solution {
public:
    void backtrack(string s, int i, int dots, string currIp, vector<string>& res) {
        if (dots == 4 && i == s.length()) {
            res.push_back(currIp.substr(0, currIp.length() - 1));
            return;
        }
        if (dots > 4) 
            return;

        for (int j = i; j < min(i+3, (int)s.length()); j++) {
            if (stoi(s.substr(i, j-i+1)) < 256 && (i == j || s[i] != '0')) {
                backtrack(s, j+1, dots+1, currIp + s.substr(i, j-i+1) + ".", res);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.length() > 12)
            return res;
        backtrack(s, 0, 0, "", res);
        return res;
    }
};