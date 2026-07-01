class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Boolean arrays to track seen numbers in rows, cols, and 3x3 boxes
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};
        
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {

                if (board[r][c] == '.') {
                    continue;
                }
                int val = board[r][c] - '1';
                
                int boxIdx = (r / 3) * 3 + (c / 3);
                
                // If the value has been seen in the current row, column, or box, it's invalid
                if (rows[r][val] || cols[c][val] || boxes[boxIdx][val]) {
                    return false;
                }
                
                // Mark the value as seen
                rows[r][val] = true;
                cols[c][val] = true;
                boxes[boxIdx][val] = true;
            }
        }
        
        return true;
    }
};