class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        char c;
        bool valid[9];
        for (int i = 0; i < 9; ++i) {
            memset(valid, 0, 9 * sizeof(bool));
            for (int j = 0; j < 9; ++j) {
                c = board[i][j];
                if (c != '.') {
                    if (valid[c - '1']) {
                        return false;
                    }
                    valid[c - '1'] = true;
                }
            }
        }
        for (int i = 0; i < 9; ++i) {
            memset(valid, 0, 9 * sizeof(bool));
            for (int j = 0; j < 9; ++j) {
                c = board[j][i];
                if (c != '.') {
                    if (valid[c - '1']) {
                        return false;
                    }
                    valid[c - '1'] = true;
                }
            }            
        }
        for (int m = 0; m < 3; ++m) {
            for (int n = 0; n < 3; ++n) {
                memset(valid, 0, 9 * sizeof(bool));
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        c = board[3 * m + i][3 * n + j];
                        if (c != '.') {
                            if (valid[c - '1']) {
                                return false;
                            }
                            valid[c - '1'] = true;
                        }
                    }
                }                
            }
        }
        return true;
    }
};
