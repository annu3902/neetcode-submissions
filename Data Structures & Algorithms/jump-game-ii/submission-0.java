class Solution {
    public int jump(int[] nums) {
       int n = nums.length;

       int[] dp = new int[n];
       Arrays.fill(dp, Integer.MAX_VALUE);

       dp[n-1] = 0;
       for(int i = n-2; i>=0; i--){
            if(i + nums[i] >= n-1){
                dp[i] = 1;
            }else if(nums[i] == 0){
                continue;
            }else{
                for(int j=1; j<=nums[i]; j++){
                    dp[i] = Math.min(dp[i], dp[j+i]);
                }
                dp[i] += 1;
            }
       } 

       return dp[0];
    }
}
