class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Data Declarations
        int n = nums.size();
        int length = k;

        int left = 0;
        vector<int> ans;

        // Algorithm to compare the element
        auto cmp = [&](int a, int b){
            return nums[a] < nums[b];
        };
        priority_queue<int, vector<int>, decltype(cmp)> maxHeap(cmp);

        // Algorithm
        for(int right = 0; right < n; right++){
            maxHeap.push(right);

            if(right - left + 1 == length){
                
                while(maxHeap.top() < left){
                    maxHeap.pop();
                }

                ans.push_back(nums[maxHeap.top()]);
                left++;

            }

        }
        return ans;
    }
};
