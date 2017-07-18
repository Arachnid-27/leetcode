class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0, k = nums[0];
        for (int s = nums.size() - 1; i <= k && k < s; ++i) {
            k = max(k, i + nums[i]);
        }
        return i <= k;
    }
};
