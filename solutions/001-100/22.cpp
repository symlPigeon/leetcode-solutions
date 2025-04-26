class Solution {
  private:
    vector<string> ans;

  public:
    void solve(string a, int l, int r, int l_cnt) {
        if (l == 0 && r == 0) {
            ans.push_back(a);
            return;
        }
        if (l != 0) {
            solve(a + "(", l - 1, r, l_cnt + 1);
        }
        if (r != 0 && l_cnt != 0) {
            solve(a + ")", l, r - 1, l_cnt - 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        solve("", n, n, 0);
        return ans;
    }
};