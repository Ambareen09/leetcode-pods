class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        unordered_map<char, int> charVals;
        for (int i = 0; i < order.length(); ++i)
        {
            charVals[order[i]] = i;
        }
        
        for (int i = 1; i < words.size(); ++i)
        {
            string s1 = words[i - 1];
            string s2 = words[i];
            
            if (s1 == s2)
            {
                continue;
            }
            int len = min(s1.length(), s2.length());            
            int j = 0;
            for(; j < len && s1[j] == s2[j]; ++j);
            if (j == len && j != s1.length())
            {
                return false;
            }
            
            if (charVals[s1[j]] > charVals[s2[j]])
            {
                return false;
            }         
        }
        
        return true;
    }
};