class Solution {
public:
    bool checkPalin(string ns){
        int n = ns.size();
        for(int i=0;i<n/2;i++) {
            if(ns[i] != ns[n-i-1]) return false;
        }
        return true;
    }
    
    bool isPalindrome(string s) {
        string ns="";
        if(s.size() == 1) return true;
        for(int i=0;i<s.size();i++){
            if(s[i] >= 'A' and s[i] <= 'Z') ns += s[i] + 32;
            else if(s[i] >= 'a' and s[i] <= 'z') ns += s[i];
            else if(s[i] >= '0' and s[i] <= '9') ns += s[i]; 
        }
        
        cout<<ns;
        
        return checkPalin(ns);    
    }
};