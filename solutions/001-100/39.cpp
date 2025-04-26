class Solution {
  public:
    vector<vector<int>> dfs(vector<int> candiates, int target, int start_idx) {
        vector<vector<int>> result;
        if (target == 0) {
            // the prev path is the answer
            result.push_back(vector<int>());
            return result;
        }
        for (auto i = start_idx; i < candiates.size(); i++) {
            if (candiates[i] > target) {
                break;
            }
            auto ans = dfs(candiates, target - candiates[i], i);
            for (auto &v : ans) {
                v.push_back(candiates[i]);
                result.push_back(v);
            }
        }
        return result;
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        return dfs(candidates, target, 0);
    }
};