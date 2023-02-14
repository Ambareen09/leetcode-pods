class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length()-1;
        int m = b.length()-1;
        string s="";
       
        int carry=0;
        while(n>=0 || m>=0){
            int sum= 0;
            if(n>=0){
                sum+=a[n]-'0';
                n--;
            }
            if(m>=0){
                sum+=b[m]-'0';
                m--;
            }
            sum+=carry;
            if(sum==2){
                carry=1;
                s.push_back('0');
            }else if(sum==3){
                carry=1;
                s.push_back('1');
            }else{
                s.push_back(sum+48);
                carry=0;
            }
        }
        if(carry==1){
            s.push_back('1');
        }
        reverse(s.begin(),s.end());
        return s;
    }
};