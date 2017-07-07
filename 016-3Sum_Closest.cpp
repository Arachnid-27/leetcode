class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int bias = nums[0] + nums[1] + nums[2] - target;
        auto size = nums.size();
        for (int i = 0; i < size; ++i) {
            int j = i + 1;
            int k = size - 1;
            int m = target - nums[i];
            while (j < k) {
                int s = nums[j] + nums[k] - m;
                if (s < 0) {
                    ++j;
                } else if (s > 0) {
                    --k;
                } else {
                    return target;
                }
                if (abs(bias) > abs(s)) {
                    bias = s;
                }
            }
            while (i + 1 < size && nums[i] == nums[i + 1]) {
                ++i;
            }
        }
        return target + bias;        
    }
};
