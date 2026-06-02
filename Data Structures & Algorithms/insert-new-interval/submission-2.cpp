class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        bool flag = false;
        int i=0;

        for(; i<n; i++){
            // Merge case
            if((newInterval[0] <= intervals[i][1]) && (newInterval[1] >= intervals[i][0])){
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }

            // Not merge
            else if(newInterval[0] < intervals[i][0]){
                ans.push_back(newInterval);
                flag = true;
                // cout<<flag;;
                break;
            }
            else{
                ans.push_back(intervals[i]);
            }
        }

        for(; i<n; i++){
            ans.push_back(intervals[i]);
        }

        if(!flag) ans.push_back(newInterval);

        return ans;
    }
};
