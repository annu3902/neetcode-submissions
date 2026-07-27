class Solution {
    public int[] getConcatenation(int[] nums) {
        List<Integer> ans = new ArrayList<>();

        for(int num : nums){
            ans.add(num);
        }

        for(int num : nums){
            ans.add(num);
        }
        int[] result = new int[2* nums.length];

        for(int i=0; i<ans.size(); i++){
            result[i] = ans.get(i);
        }

        return result;
    }
}