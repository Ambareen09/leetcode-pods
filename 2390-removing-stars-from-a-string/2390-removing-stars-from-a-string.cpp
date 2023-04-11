class Solution {
public:
    string removeStars(string s) {
        
        stack<char> st;
        string ans;
        for(int i=0;i<s.length();i++){
            st.push(s[i]);
            if(s[i]=='*'){
                st.pop();
                st.pop();
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};