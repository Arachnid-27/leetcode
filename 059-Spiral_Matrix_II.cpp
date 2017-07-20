class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vec(n, vector<int>(n));
        int count = 0, s = (n + 1) / 2;
        for (int k = 0; k < s; ++k) {
            for (int i = k; i < n; ++i) {
                vec[k][i] = ++count;
            }
            for (int i = k + 1; i < n - 1; ++i) {
                vec[i][n - 1] = ++count;
            }
            if (k != n - 1) {
                for (int i = n - 1; i >= k; --i) {
                    vec[n - 1][i] = ++count;
                }
                for (int i = n - 2; i > k; --i) {
                    vec[i][k] = ++count;
                }
            }
            --n;
        }
        return vec;        
    }
};
