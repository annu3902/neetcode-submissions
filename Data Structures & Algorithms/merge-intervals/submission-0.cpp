class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for(int i=1; i<intervals.size(); i++){
            int s1 = ans.back()[0];
            int e1 = ans.back()[1];
            int s2 = intervals[i][0];
            int e2 = intervals[i][1];

            // Overlapping case
            if(s2 <= e1){
                ans.back()[0] = min(s1, s2);
                ans.back()[1] = max(e1, e2);
            }

            // Non-overlapping case
            else{
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};
