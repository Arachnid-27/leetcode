class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        size_t n = matrix.size();
        for (size_t i = 0; i < n / 2; ++i) {
            size_t m = n - 1 - i;
            for (size_t j = i; j < m; ++j) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[m - j + i][i];
                matrix[m - j + i][i] = matrix[m][m - j + i];
                matrix[m][m - j + i] = matrix[j][m];
                matrix[j][m] = t;
            }
        }
    }
};
