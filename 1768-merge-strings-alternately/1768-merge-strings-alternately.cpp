class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        string ans;

        while(i < word1.size() and i < word2.size()) {
            ans += word1[i];
            ans += word2[i];
            i++;
        }

        ans += word1.substr(i);
        ans += word2.substr(i);

        return ans;
    }
};