class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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
        unordered_set<int> hash;
        for (size_t i = n; i < nums.size(); ++i) {
            if (hash.insert(nums[i]).second) {
                swap(nums[i], nums[n]);
                dfs(n + 1, nums, result);
                swap(nums[i], nums[n]);
            }
        }
    }
};
