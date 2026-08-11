class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachableIndex = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(maxReachableIndex < i){
                return false;
            }
            maxReachableIndex = max(maxReachableIndex, i + nums[i]);
        }

        return true;
    }
};
