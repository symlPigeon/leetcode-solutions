class Solution {
  public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.size() == 1) {
            return 1;
        }

        // 开始递推
        vector<int> dp(nums.size(), 1);
        // dp[i]即选择i之后的最长上升子序列长度
        // dp[i] = 1 + dp[比i小的上一个数的下标]
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
        }

        int max = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (dp[i] > max) {
                max = dp[i];
            }
        }
        return max;
    }
};