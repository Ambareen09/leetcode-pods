class Solution {
public:
    vector<int> findAnagrams(string s, string p)
    {
        int l = s.length();
        int k = p.length();
        if(k>l) return {};
       vector<int> pf(26,0), window(26,0);
        for(int i=0;i<k;i++)
        {
            pf[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        vector<int>ans;
        if(pf == window) ans.push_back(0);
        for(int i=k;i<l;i++)
        {
            window[s[i-k]-'a']--;
            window[s[i]-'a']++;
            if(pf == window) ans.push_back(i-k+1);
        }
        return ans;
        
    }
};