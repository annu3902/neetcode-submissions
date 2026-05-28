class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0;
        int j = 0;
        int n = word.size();
        int m = abbr.size();

        while(i < n && j < m){
            if(word[i] == abbr[j]){
                i++;
                j++;
            }

            else if(abbr[j] >= 48 && abbr[j] <= 57){
                if(abbr[j] == 48) return false;
                int length = 0;
                while(j < m && abbr[j] >= 48 && abbr[j] <= 57){
                    length = length*10 + (abbr[j] - '0');
                    j++;
                }
                // cout<<length<<" ";

                if(length == 0 || n-i < length) { return false;}

                while(i < n && length > 0){
                    length--;
                    i++;
                }                
            }

            else return false;
        }

        if(i < n || j < m) return false;
        return true;
    }
};