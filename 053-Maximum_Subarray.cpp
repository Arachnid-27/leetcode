class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev = nums[0], ret = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            prev = prev > 0 ? prev + nums[i] : nums[i];
            ret = max(prev, ret);
        }
        return ret;
    }
};
