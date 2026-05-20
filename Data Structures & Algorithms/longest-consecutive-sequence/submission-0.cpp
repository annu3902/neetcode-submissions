class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Data Declarations
        int n = nums.size();
        unordered_set<int> st;
        int ans = 0;

        // Algorithm
        for(int i=0; i<n; i++){
            int num = nums[i];
            int cnt = 1;
            while(st.count(num - 1)){
                cnt++;
                num--;
            }
            num = nums[i];
            while(st.count(num + 1)){
                cnt++;
                num++;
            }
            ans = max(ans, cnt);
            st.insert(nums[i]);

        }
        return ans;
    }
};
