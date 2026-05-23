class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Data Declarations and Requirement Analysis
        int length = s1.size();
        int n = s2.size();
        unordered_map<char, int> mp;

        for(char ch : s1){
            mp[ch]++;
        }

        // Algorithms
        int start = 0;
        int end = 0;
        int cnt = mp.size();

        while(end < n){

            char ch = s2[end];
            if(mp.count(ch)){
                mp[ch]--;
                if(mp[ch] == 0){
                    cnt--;
                }
                if(cnt == 0) return true;
            }

            if(end - start + 1 == length)
            {
                char ch = s2[start];
                if(mp.count(ch)){
                    mp[ch]++;
                    if(mp[ch] == 1)
                        cnt++;
                }
                start++;
            }
            end++;
        }
        return false;
    }
};
