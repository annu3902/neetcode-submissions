class Solution {
    public boolean validWordAbbreviation(String word, String abbr) {
        int i = 0;
        int j = 0;
        int n = word.length();
        int m = abbr.length();

        while(i < n && j < m){
            if(word.charAt(i) == abbr.charAt(j)){
                i++;
                j++;
            }else if(abbr.charAt(j) >= 48 && abbr.charAt(j) <= 57){
                if(abbr.charAt(j) == 48) return false; // leading 0 case

                int length = 0;
                while(j < m && abbr.charAt(j) >= 48 && abbr.charAt(j) <= 57){
                    length = length*10 + abbr.charAt(j) - '0';
                    j++;
                }

                if(length > n-i) return false;
                i += length;

                // while(i < n && length > 0){
                //     length--;
                //     i++;
                // }
            }else{
                return false;
            }
        }

        while(j < m || i < n) return false;
        return true;
    }
}