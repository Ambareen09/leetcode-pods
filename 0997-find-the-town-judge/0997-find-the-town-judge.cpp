class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> t(n+1, 0);
        for(auto i : trust){
            t[i[0]]--;
            t[i[1]]++;
        }
        for(int i=1;i<=n;i++){
            if(t[i] == n-1) return i;
        }
        return -1;
    }
};