class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        auto size = nums.size();
        for (int i = 0; i < size; ++i) {
            int j = i + 1;
            int k = size - 1;
            int m = -nums[i];
            while (j < k) {
                int s = nums[j] + nums[k];
                if (s < m) {
                    ++j;
                } else if (s > m) {
                    --k;
                } else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    --k;
                    while (j < k && nums[j] == nums[j - 1]) {
                        ++j;
                    }
                    while (j < k && nums[k] == nums[k + 1]) {
                        --k;
                    }
                }
            }
            while (i + 1 < size && nums[i] == nums[i + 1]) {
                ++i;
            }
        }
        return result;
    }
};
