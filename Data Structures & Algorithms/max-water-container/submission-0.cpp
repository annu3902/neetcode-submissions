class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int i=0;
        int j=heights.size() - 1;
        int maxArea = 0;
        int breadth = j;

        while(i < j){

            int length = min(heights[i], heights[j]);
            int area = length*breadth;

            maxArea = max(maxArea, area);

            if(heights[i] <= heights[j]){
                i++;
            }
            else{
                j--;
            }
            breadth--;
        }

        return maxArea;
    }
};
