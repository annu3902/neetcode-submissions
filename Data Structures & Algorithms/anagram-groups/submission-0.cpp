class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<string> t = strs;
        unordered_map<string, vector<string>> mp;
        for(int i=0; i<strs.size(); i++){
            sort(begin(t[i]), end(t[i]));
            mp[t[i]].push_back(strs[i]);
        }

        for(auto s : mp){
            ans.push_back(s.second);
        }

        return ans;
    }
};
