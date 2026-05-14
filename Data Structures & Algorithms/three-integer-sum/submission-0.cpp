class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> st;

        // nums[i] + nums[j] = -nums[k];
        for(int k=0; k<nums.size(); k++){

            int target = -nums[k];
            unordered_map<int, int> mpp;

            for(int i=k+1; i<nums.size(); i++){

                if(mpp.find(target - nums[i]) != mpp.end()){
                    vector<int>ans = {nums[k], nums[i], target - nums[i]};
                    st.insert(ans);
                }

                mpp[nums[i]] = i;

            }
        }

        for(auto it : st){
            result.push_back(it);
        }
        return result;
    }
};
