class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
        make_heap(s.begin(),s.end());
        
        while(s.size() > 1) {
            int a = s.front();
            pop_heap(s.begin(), s.end());
            s.pop_back();
            
            int b = s.front();
            pop_heap(s.begin(), s.end());
            s.pop_back();
            
            if(a-b == 0) continue;
            else{
                s.push_back(abs(a-b));
                push_heap(s.begin(),s.end());
            }
        }
        return s.size() ? s.front() : 0;
        
    }
};