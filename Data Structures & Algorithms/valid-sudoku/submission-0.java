class Solution {
    public boolean isValidSudoku(char[][] board) {
        int m = board.length;
        int n = board[0].length;
        Set set = new HashSet();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                char num = board[i][j];

                if(num != '.'){
                    if(!set.add(num + " in row " + i) ||(!set.add(num + " in coloumn " + j) || (!set.add(num + " in block " + i/3 + "-" + j/3)))){
                        return false;
                    }
                }
            }
        }

        return true;
    }
}
