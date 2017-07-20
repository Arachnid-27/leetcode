class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> vec(m, vector<int>(n, 0));
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; ++i) {
            vec[i][0] = 1;
        }
        for (int i = 0; i < n && obstacleGrid[0][i] == 0; ++i) {
            vec[0][i] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    vec[i][j] = vec[i][j - 1] + vec[i - 1][j];
                }
            }
        }
        return vec[m - 1][n - 1];        
    }
};
