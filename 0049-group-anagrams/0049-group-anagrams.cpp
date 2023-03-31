class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

		map<string,vector<string>> m;

		int n = strs.size();

		for(int i = 0; i < n; i++){
			string temp = strs[i];

			sort(temp.begin(),temp.end());

			m[temp].push_back(strs[i]);
		}

		for(auto i : m){
			ans.push_back(i.second);
		}

		return ans;
    }
};