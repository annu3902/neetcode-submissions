class Solution {
public:
    string minWindow(string s, string t) {
        // Length of shortest substring such that every character in t is present in the substring
        // Data Declarations
        int n = s.size();
        int m = t.size();

        if(n < m) return "";
        unordered_map<char, int> mp;
        for(char ch : t){
            mp[ch]++;
        }

        int count = mp.size();

        // Algorithm
        int left = 0;
        int minLength = INT_MAX;
        string ans = "";
        for (int right = 0; right < n; right++) {
    // 1. Add s[right] to window (update map + count)
            char ch = s[right];
            if(mp.count(ch)){
                mp[ch]--;
                if(mp[ch] == 0){
                    count--;
                }
            }   
            while (count == 0) {
                int length = right - left + 1;
        // 2. Record answer if this window is smaller
                if(minLength > length){
                    minLength = length;
                    ans = s.substr(left, length);
                }
                char ch = s[left];
                if(mp.count(s[left])){
                    mp[s[left]]++;
                    if(mp[s[left]] == 1){
                        count++;
                    }
                }
        // 3. Remove s[left] from window (update map + count)
            left++;
            }
        }
        return ans;
    }
};
