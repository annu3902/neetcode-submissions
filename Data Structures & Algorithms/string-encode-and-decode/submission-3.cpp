class Solution {
public:

    string encode(vector<string>& st) {
        string ans = "";
        for(string s : st){
            int length = s.size();
            ans += to_string(length) + '#' + s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        int i = 0;
        while(i < s.size()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }

            int length = stoi(s.substr(i, j-i+1));
            // cout<<length<<" ";
            i = j + 1;
            string t = s.substr(i, length);
            // cout<<t<<" ";
            ans.push_back(t);
            i = i + length;
        }

        return ans;
    }
};
