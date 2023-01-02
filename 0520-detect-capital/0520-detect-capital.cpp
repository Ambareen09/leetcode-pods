class Solution {
public:
    bool detectCapitalUse(string word) {
        int l = 0, r=0;
        if(word[0] >= 'A' and word[0] <= 'Z') r++;
        for(int i = 1; i<word.size(); i++){
            if(word[i] >= 'A' and word[i] <= 'Z') l++;
            
        }
        if(r==1 and l==0) return true;
        if(l+r==word.size()) return true;
        if(l==0) return true;
        return false;
        
        
    }
};