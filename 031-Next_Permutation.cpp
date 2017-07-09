class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) {
            return;
        }
        size_t i = nums.size() - 2;
        while (i >= 0) {
            if (nums[i] < nums[i + 1]) {
                for (int j = nums.size() - 1; j > i; --j) {
                    if (nums[j] > nums[i]) {
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
                ++i;
                break;
            }
            --i;
        }
        size_t j = nums.size() - 1;
        for (size_t j = nums.size() - 1; i < j; ++i, --k) {
            swap(nums[i], nums[j]);
            --j;
        }
    }
};
