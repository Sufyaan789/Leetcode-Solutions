class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.')
                    continue; 

                // check row
                for (int col = 0; col < 9; col++) {
                    if (col != j && board[i][col] == c)
                        return false;
                }

                // check column
                for (int row = 0; row < 9; row++) {
                    if (row != i && board[row][j] == c)
                        return false;
                }

                // check 3x3 box
                int startRow = (i / 3) * 3;
                int startCol = (j / 3) * 3;
                for (int r = startRow; r < startRow + 3; r++) 
                    for (int c2 = startCol; c2 < startCol + 3; c2++) 
                        if ((r != i || c2 != j) && board[r][c2] == c) 
                            return false;
                        
            }
        }
        return true;
    }
};