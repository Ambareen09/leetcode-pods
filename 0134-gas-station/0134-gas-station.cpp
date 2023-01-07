class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum=0,s=0;
        for (int i=0;i<gas.size();i++) {
            gas[i]-=cost[i];
            sum+=gas[i];
        }
        if (sum<0) return -1;
        sum=0;
        for (int i=0;i<gas.size();i++) {
            sum+=gas[i];
            if (sum<0) {
                sum=0;
                s=i+1;
            }
        }
        return s;
    }
};