class Solution {
public:
    int maxVowels(string s, int k) {
        if (s.size() < k) return false;
        int curr_count = 0;
        int max_count = 0;
        for(int i=0; i<k; i++){
          if (isVowel(s[i]))  updateCount(curr_count, max_count);
        }
        for(int i=k; i<s.size(); i++){
          if (isVowel(s[i-k]))  curr_count--;
          if (isVowel(s[i])) {
            updateCount(curr_count, max_count);
          }
        }
        return max_count;
    }


private:
    bool isVowel(char c){
      string VOWELS = "aeiou";
      for(int i=0; i<VOWELS.size(); i++){
        if (VOWELS[i] == c) return true;
      }
      return false;
    }

    void updateCount(int &currCount, int &maxCount){
      currCount = currCount+1;
      maxCount = max(currCount, maxCount);
    }
};