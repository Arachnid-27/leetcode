class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> vec;
        int m = matrix.size();
        int n = matrix.empty() ? 0 : matrix[0].size();
        int s = (min(m, n) + 1) / 2;
        for (int k = 0; k < s; ++k) {
            for (int i = k; i < n; ++i) {
                vec.push_back(matrix[k][i]);
            }
            for (int i = k + 1; i < m - 1; ++i) {
                vec.push_back(matrix[i][n - 1]);
            }
            if (k != m - 1) {
                for (int i = n - 1; i >= k; --i) {
                    vec.push_back(matrix[m - 1][i]);
                }
            }
            if (k != n - 1) {
                for (int i = m - 2; i > k; --i) {
                    vec.push_back(matrix[i][k]);
                }
            }
            --n, --m;
        }
        return vec;
    }
};
