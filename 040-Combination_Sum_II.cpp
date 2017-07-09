class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> vec;
        sort(candidates.begin(), candidates.end());
        dfs(target, 0, candidates, vec, result);
        return result;
    }
private:
    void dfs(int remain, int start, vector<int>& nums, vector<int>& vec, vector<vector<int>>& result) {
        if (remain == 0) {
            result.push_back(vec);
            return;
        }
        for (int i = start; i < nums.size() && nums[i] <= remain; ++i) {
            if (i == start || nums[i] != nums[i - 1]) {
                vec.push_back(nums[i]);
                dfs(remain - nums[i], i + 1, nums, vec, result);
                vec.pop_back();
            }
        }
    }
};
