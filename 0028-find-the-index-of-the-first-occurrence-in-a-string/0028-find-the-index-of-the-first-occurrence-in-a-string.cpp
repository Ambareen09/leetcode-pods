class Solution {
public:
     int strStr(string t, string s) {
        if(s.length()==0)return 0;
        int i=0;
        int j=0;
        string st="";
        int ans=-1;
         
        while(j<t.length()){             
            st.push_back(t[j]); 
            
            if(j<s.length()-1) j++;   
            
            else{
                if(st==s) return i;         
                st.erase(0,1);                 
                i++;
                j++;
            }
        }
        return -1;
    }
};