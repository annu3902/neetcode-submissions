class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mpp;

        for(int x : nums){
            mpp[x]++;
        }


        multimap<int, int> mulMap;

        for(auto it : mpp){
            int num =  it.first;
            int freq = it.second;
            mulMap.insert({freq, num});
        }

        vector<int> ans;
        int cnt = 0;
        for(auto it = mulMap.rbegin(); it != mulMap.rend() && cnt < k; it++){
            int num = (it)->second;
            ans.push_back(num);
            cnt++;
        }

        return ans;
    }
};
