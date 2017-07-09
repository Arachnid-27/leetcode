class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        char c;
        bool hash[3][9][9];
        memset(hash, 0, 3 * 9 * 9 * sizeof(bool));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                c = board[i][j];
                if (c != '.') {
                    hash[0][i][c - '1'] = true;
                    hash[1][j][c - '1'] = true;
                    hash[2][3 * (i / 3) + (j / 3)][c - '1'] = true;
                }
            }
        }
        dfs(0, 0, board, hash);
    }
private:
    bool dfs(int i, int j, vector<vector<char>>& board, bool (&hash)[3][9][9]) {
        if (j == 9) {
            if (i == 8) {
                return true;
            }
            ++i;
            j = 0;
        }
        if (board[i][j] == '.') {
            for (int k = 0; k < 9; ++k) {
                int n = 3 * (i / 3) + (j / 3);
                if (!hash[0][i][k] && !hash[1][j][k] && !hash[2][n][k]) {
                    hash[0][i][k] = true;
                    hash[1][j][k] = true;
                    hash[2][n][k] = true;
                    board[i][j] = '0' + k + 1;
                    if (dfs(i, j + 1, board, hash)) {
                        return true;
                    }
                    board[i][j] = '.';
                    hash[0][i][k] = false;
                    hash[1][j][k] = false;
                    hash[2][n][k] = false;
                }
            }
            return false;
        } else {
            return dfs(i, j + 1, board, hash); 
        }
    }
};
