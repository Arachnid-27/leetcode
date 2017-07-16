class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        dfs(0, nums, result);
        return result;
    }
private:
    void dfs(int n, vector<int>& nums, vector<vector<int>> &result) {
        if (n == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (size_t i = n; i < nums.size(); ++i) {
            swap(nums[i], nums[n]);
            dfs(n + 1, nums, result);
            swap(nums[i], nums[n]);
        }
    }
};
