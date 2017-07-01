class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto size = nums.size();
        unordered_map<int, int> map(size);
        for (int i = 0; i < size; ++i) {
            map[nums[i]] = i;
        }
        for (int i = 0; i < size; ++i) {
            auto iter = map.find(target - nums[i]);
            if (iter != map.end() && i != iter->second) {
                return { i, iter->second };
            }
        }
    }
};
