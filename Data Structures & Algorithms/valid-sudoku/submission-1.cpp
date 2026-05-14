class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Data Declarations
        int m = board.size();
        int n = board[0].size();
        set<string> st;

    // Algorithm
    // Row checking
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int num = board[i][j];
                if(board[i][j] != '.'){
                    if(st.count(to_string(num) + "in_row" + to_string(i))){
                        return false;
                    }
                    else{
                        st.insert(to_string(num) + "in_row" + to_string(i));
                    }
                } 
            }
        }
    //  Coloumn Checking
        for(int j=0; j<n; j++){
            for(int i=0; i<m; i++){
                int num = board[i][j];
                if(board[i][j] != '.'){
                    if(st.count(to_string(num)  + "in_coloumn" + to_string(j))){
                        return false;
                    }
                    else{
                        st.insert(to_string(num) + "in_coloumn" + to_string(j));
                    }
                }
            }
        }

        // Block Checking
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int num = board[i][j];
                if(board[i][j] != '.'){
                    if(st.count(to_string(num) + " in " + to_string(i/3) + "_" + to_string(j/3) + "in_block")){
                        return false;
                    }
                    else{
                        st.insert(to_string(num) + " in " + to_string(i/3) + "_" + to_string(j/3) + "in_block");
                    }
                }
            }
        }

        return true;

    }
};
