class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        int sum, top = 0;
        for (int i = 1; i < height.size(); ++i) {
            sum = 0;
            while (i < height.size() && height[i] < height[top]) {
                sum += (height[top] - height[i]);
                ++i;
            }
            if (i < height.size()) {
                result = result + sum;
                top = i;
            }
        }
        int k = top - 1;
        top = height.size() - 1;
        for (int i = height.size() - 2; i > k; --i) {
            sum = 0;
            while (i > k && height[i] < height[top]) {
                sum += (height[top] - height[i]);
                --i;
            }
            if (i > k) {
                result = result + sum;
                top = i;
            }
        }
        return result;
    }
};
