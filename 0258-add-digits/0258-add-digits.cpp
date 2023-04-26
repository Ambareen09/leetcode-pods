class Solution {
public:
    int sumOfdig(int &num){
        int ans = 0;
        
        while(num){
            int rem = num%10;
            ans = ans + rem;
            num = num/10;
        }
        return ans;
    }
    
    
    int addDigits(int num) {
        if(num <= 9) return num;
        
        while(num > 9){
            num = sumOfdig(num);
        }
        return num;
    }
};