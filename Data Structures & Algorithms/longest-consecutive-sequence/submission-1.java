class Solution {
    public int longestConsecutive(int[] nums) {
       Set<Integer> st = new HashSet<>();
        int maximumConsecutiveSequence = 0;

//        Algorithm
        for(int num : nums){
            st.add(num);
        }

        for(int num : st){
            if(!st.contains(num - 1)){
                int lengthOfConsecutiveSequence = 1;
                while(st.contains(num + 1)){
                    lengthOfConsecutiveSequence++;
                    num++;
                }
                maximumConsecutiveSequence = Math.max(maximumConsecutiveSequence, lengthOfConsecutiveSequence);
            }
        }

        return maximumConsecutiveSequence;
    }
            
};
