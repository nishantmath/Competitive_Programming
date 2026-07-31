class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> preMax(n);
        preMax[0] = nums[0];

        // Prefix maximum
        for (int i = 1; i < n; i++) {
            preMax[i] = max(preMax[i - 1], nums[i]);
        }

        vector<int> ans(n);
        int sufMin = INT_MAX;

        // Process from right to left
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1 || preMax[i] <= sufMin)
                ans[i] = preMax[i];
            else
                ans[i] = ans[i + 1];

            sufMin = min(sufMin, nums[i]);
        }

        return ans;
    }
};