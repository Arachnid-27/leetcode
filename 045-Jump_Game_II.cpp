class Solution {
public:
    int jump(vector<int>& nums) {
        size_t count = 0;
        size_t i = 0, k = 0;
        while (k < nums.size() - 1) {
            ++count;
            for (size_t j = k; i <= j; ++i) {
                k = max(k, i + nums[i]);
            }
        }
        return count;
    }
};
