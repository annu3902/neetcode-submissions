class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majorityElement = nums[0];
        int cnt = 0;

        for(int i=0; i<n; i++){
            if(nums[i] == majorityElement){
                cnt++;
            }else{
                cnt--;
                if(cnt <= 0){
                    majorityElement = nums[i];
                }
            }
        }

        int cntMajority = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == majorityElement){
                cntMajority++;
            }
        }

        if(cntMajority > floor(n/2)) return majorityElement;

        return -1;
    }
};