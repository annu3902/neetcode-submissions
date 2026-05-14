class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp;

        int i=0; int j=0; int maxLength = 0;

        while(j < s.size()){

            mpp[s[j]]++;

            while(mpp[s[j]] > 1){

                mpp[s[i]]--;
                if(mpp[s[i]] == 0) mpp.erase(s[i]);

                i++;

            }

            maxLength = max(maxLength , j-i+1);

            j++;

        }

        return maxLength;

    }
};
