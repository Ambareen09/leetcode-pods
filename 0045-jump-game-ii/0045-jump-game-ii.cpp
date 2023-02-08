class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(),jmp=1;
        if(n==1) return 0;
        int j = nums[0],temp = nums[0];
        for(int i=1;i<n;i++){
            if(j>=n-1) return jmp;
            if(i>j){
                j = temp;
                jmp++;
            }
            temp = max(temp,i+nums[i]);
        }
        return jmp;
    }
};