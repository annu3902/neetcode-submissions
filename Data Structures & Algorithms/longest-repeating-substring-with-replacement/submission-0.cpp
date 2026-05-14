class Solution {
public:
    int characterReplacement(string s, int k) {
        // Data Declarations
        int i = 0;
        int j = 0;
        int n = s.size();
        int maxFrequency = 0;
        unordered_map<char, int> mp;
        int maxLength = 0;

        // Code Logic
        while(j < n){
            mp[s[j]]++;
            maxFrequency = max(maxFrequency, mp[s[j]]);
            int currLength = j - i + 1;
            if(currLength - maxFrequency <= k){
                maxLength = max(maxLength, currLength);
            }
            
            while(i < n && currLength - maxFrequency > k){
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                currLength--;
                i++;
            }
            j++;

        }
        return maxLength;
    }
};
