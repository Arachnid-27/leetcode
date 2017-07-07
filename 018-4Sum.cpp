class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        auto size = nums.size();
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                int l = j + 1;
                int r = size - 1;
                int m = target - nums[i] - nums[j];
                while (l < r) {
                    int s = nums[l] + nums[r];
                    if (s < m) {
                        ++l;
                    } else if (s > m) {
                        --r;
                    } else {
                        result.push_back({nums[i], nums[j], nums[l], nums[r]});
                        ++l;
                        --r;
                        while (l < r && nums[l] == nums[l - 1]) {
                            ++l;
                        }
                        while (l < r && nums[r] == nums[r + 1]) {
                            --r;
                        }
                    }
                }
                while (j + 1 < size && nums[j] == nums[j + 1]) {
                    ++j;
                }
            }
            while (i + 1 < size && nums[i] == nums[i + 1]) {
                ++i;
            }
        }
        return result;        
    }
};
