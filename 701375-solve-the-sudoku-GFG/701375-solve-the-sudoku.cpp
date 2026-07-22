#include <vector>

using namespace std;

class Solution {
private:
    int row[9] = {0};
    int col[9] = {0};
    int box[9] = {0};

    bool solve(vector<vector<int>>& mat, int r, int c) {
        // Reached end of grid: Sudoku solved
        if (r == 9) return true;
        
        // Move to the next row when reaching end of current row
        if (c == 9) return solve(mat, r + 1, 0);
        
        // Skip already filled cells
        if (mat[r][c] != 0) return solve(mat, r, c + 1);

        int boxIdx = (r / 3) * 3 + (c / 3);

        for (int num = 1; num <= 9; ++num) {
            int mask = 1 << num;

            // Check if 'num' is already used in row, column, or 3x3 box
            if (!(row[r] & mask) && !(col[c] & mask) && !(box[boxIdx] & mask)) {
                // Place number and set bit flags
                mat[r][c] = num;
                row[r] |= mask;
                col[c] |= mask;
                box[boxIdx] |= mask;

                // Recurse to next cell
                if (solve(mat, r, c + 1)) return true;

                // Backtrack: Reset bit flags and cell value
                mat[r][c] = 0;
                row[r] &= ~mask;
                col[c] &= ~mask;
                box[boxIdx] &= ~mask;
            }
        }

        return false;
    }

public:
    void solveSudoku(vector<vector<int>>& mat) {
        // Initialize bitmasks with initial grid state
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (mat[i][j] != 0) {
                    int num = mat[i][j];
                    int mask = 1 << num;
                    int boxIdx = (i / 3) * 3 + (j / 3);

                    row[i] |= mask;
                    col[j] |= mask;
                    box[boxIdx] |= mask;
                }
            }
        }

        solve(mat, 0, 0);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna