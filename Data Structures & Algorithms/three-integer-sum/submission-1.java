class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        //        Data Declarations
        List<List<Integer>> ans = new ArrayList<>();
        Set<Integer> st = new HashSet<>();

//        Algorithm
        for(int i=0; i<nums.length; i++){
            int sum = - nums[i];
            for(int j=i+1; j<nums.length; j++){
                if(st.contains(-nums[i] - nums[j])){
                    List<Integer> ls = new ArrayList<>();
                    ls.add(nums[i]);
                    ls.add(nums[j]);
                    ls.add(-nums[i]- nums[j]);
                    Collections.sort(ls);
                    if(!ans.contains(ls))
                    ans.add(ls);
                }
                // st.add(nums[j]); - Wrong step add only when you process a single element completely 
            }
            st.add(nums[i]);
        }

        return ans;
    }
};
