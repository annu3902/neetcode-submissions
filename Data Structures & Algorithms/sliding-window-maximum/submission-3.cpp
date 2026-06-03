class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // deque of index
        int left = 0;
        vector<int> ans;

        for(int right = 0; right < nums.size(); right++){
            while(!dq.empty() &&( nums[dq.back()] < nums[right])){
                dq.pop_back();
                left++;
            }

            if(!dq.empty() && dq.front() < right - k + 1){
                dq.pop_front();
            }

            dq.push_back(right);
            if(right >= k-1){
                ans.push_back(nums[dq.front()]);
            }

        }

        return ans;
    }
};
