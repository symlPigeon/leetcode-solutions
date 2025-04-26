class Solution {
  private:
    vector<vector<int>> ans;

  public:
    void dfs(vector<int> current, int n, int k, int l) {
        if (k == 0) {
            this->ans.push_back(current);
            return;
        }
        for (int i = l; i <= n - k + 1; i++) {
            current.push_back(i);
            dfs(current, n, k - 1, i + 1);
            current.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        if (k > n) {
            return vector<vector<int>>();
        }
        dfs(vector<int>(), n, k, 1);
        return this->ans;
    }
};