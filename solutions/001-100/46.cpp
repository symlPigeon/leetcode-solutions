class Solution {
  private:
    vector<vector<int>> ans;

  public:
    void dfs(vector<int> &nums, vector<int> current, int used, int cnt) {
        if (cnt == nums.size()) {
            ans.push_back(current);
            return;
        }
        for (int idx = 0; idx < nums.size(); idx++) {
            if ((used & (1 << idx)) == 0) {
                current.push_back(nums[idx]);
                dfs(nums, current, used | (1 << idx), cnt + 1);
                current.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums) {
        dfs(nums, vector<int>(), 0, 0);
        return ans;
    }
};