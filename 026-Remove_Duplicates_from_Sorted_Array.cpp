class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        auto prev = nums.begin();
        for (auto iter = nums.begin() + 1; iter != nums.end(); ++iter) {
            if (*iter != *prev) {
                ++prev;
                *prev = *iter;
            }
        }
        return prev - nums.begin() + 1;
    }
};
