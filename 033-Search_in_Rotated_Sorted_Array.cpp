class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int l = 0, r = nums.size() - 1;
        bool flag = target >= nums[0];
        while (l <= r) {
            int m = (l + r) >> 1;
            if (nums[m] > target) {
                if (!flag && nums[m] > nums[r]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            } else if (nums[m] < target) {
                if (flag && nums[m] < nums[l]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else {
                return m;
            }
        }
        return -1;
    }
};
