class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }
        int l, r, m = 0;
        vector<int> vec{-1, -1};
        for (int i = 0; i < 2; ++i) {
            l = m;
            r = nums.size() - 1;
            while (l <= r) {
                m = (l + r) >> 1;
                if (nums[m] > target) {
                    r = m - 1;
                } else if (nums[m] < target) {
                    l = m + 1;
                } else {
                    if (i == 0) {
                        if (m == 0 || nums[m - 1] != nums[m]) {
                            vec[0] = m;
                            break;
                        }
                        r = m - 1;
                    } else {
                        if (m == nums.size() - 1 || nums[m + 1] != nums[m]) {
                            vec[1] = m;
                            break;
                        }
                        l = m + 1;
                    }
                }
            }
            if (vec[i] == -1) {
                break;
            }
        }
        return vec;
    }
};
