class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    // Data Declarations
        long int product = 1;
        // long int productWithoutZero = 1;
        int cnt0 = 0;
        int n = nums.size();
        vector<int> ans;

    // Code Logic
        for(int i=0; i < n; i++){
            if(nums[i] != 0){
                product *= nums[i];
            }else{
                cnt0++;
            }
        }

        if(cnt0 > 1) product = 0;

        for(int i=0; i<n; i++){
            if(cnt0 == 0 && nums[i] != 0){
                ans.push_back(product/nums[i]);
            }
           else if(cnt0 != 0 && nums[i] != 0){
                ans.push_back(0);
            }else{
                if(cnt0 > 1){
                    ans.push_back(0);
                }else{
                    ans.push_back(product);
                }
            }
        }

        return ans;
    }
};
