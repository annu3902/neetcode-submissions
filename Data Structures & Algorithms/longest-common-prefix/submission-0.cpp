class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int smallestIndex = -1;
        int size = INT_MAX;
        
        for(int i = 0; i<strs.size(); i++){
            if(size > strs[i].size()){
                size = strs[i].size();
                smallestIndex = i;
            }
        }
        
        int j = 0;
        int i = 1;
        while(j < strs[smallestIndex].size()){
            while(i < strs.size()){
                if(strs[i][j] == strs[i-1][j]){
                    i++;
                }
                else{
                    return ans;
                }
            }
            ans += strs[0][j];
            i = 1;
            j++;
        }

        return ans;
    }
};