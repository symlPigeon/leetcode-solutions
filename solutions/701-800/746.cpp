class Solution {
  public:
    int minCostClimbingStairs(vector<int> &cost) {
        vector<int> min_cost(cost.size() + 1);
        min_cost[0] = 0;
        min_cost[1] = 0;
        for (int idx = 2; idx <= cost.size(); idx++) {
            int min_cost_1 = min_cost[idx - 1] + cost[idx - 1];
            int min_cost_2 = min_cost[idx - 2] + cost[idx - 2];
            if (min_cost_1 > min_cost_2) {
                min_cost[idx] = min_cost_2;
            } else {
                min_cost[idx] = min_cost_1;
            }
        }
        return min_cost[cost.size()];
    }
};