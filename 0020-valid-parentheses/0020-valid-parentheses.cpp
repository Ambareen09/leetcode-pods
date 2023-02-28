class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        if(n==0) return true;
        if(n==1) return false;
        
        for(int i=0;i<n;i++){
            if(s[i] == '(' or s[i] == '{' or s[i] == '[') st.push(s[i]);
            
            else if(!st.empty()){
                if(s[i] == ')' and st.top()=='(') st.pop();
                else if(s[i] == '}' and st.top()=='{') st.pop();
                else if(s[i] == ']' and st.top()=='[') st.pop();
                else return false;
            }
            
            else return false;
        }
        return st.empty();
    }
};