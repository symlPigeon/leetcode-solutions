class Solution {
  public:
    int coinChange(vector<int> &coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        vector<int> dp(amount + 1, 0x7ffffffe);
        dp[0] = 0;
        for (int i = 0; i < amount + 1; i++) {
            for (auto &coin : coins) {
                if (i - coin >= 0 && dp[i - coin] + 1 < dp[i]) {
                    dp[i] = dp[i - coin] + 1;
                }
            }
        }
        // for (int i = 0; i < amount + 1; i++) {
        //     cout << dp[i] << endl;
        // }
        return dp[amount] == 0x7ffffffe ? -1 : dp[amount];
    }
};