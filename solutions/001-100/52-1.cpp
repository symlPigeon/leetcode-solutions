class Solution {
  private:
    int ans = 0;

  public:
    void search(vector<uint8_t> a, int n) {
        if (a.size() == n) {
            ans++;
            return;
        }
        for (uint8_t i = 0; i < n; i++) {
            bool flag = false;
            // 判断每一列是否重复
            for (uint8_t j : a) {
                if (i == j) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                continue;
            }
            // 判断对角线重复
            // 先往左再往右
            for (int8_t j = i - 1, k = a.size() - 1; j >= 0 && k >= 0;
                 j--, k--) {
                if (a[k] == j) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                continue;
            }
            for (int8_t j = i + 1, k = a.size() - 1; j < n && k >= 0;
                 j++, k--) {
                if (a[k] == j) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                continue;
            }
            // 现在当前值是满足条件的
            a.push_back(i);
            search(a, n);
            a.pop_back();
        }
    }
    int totalNQueens(int n) {
        this->ans = 0;
        search(vector<uint8_t>(), n);
        return ans;
    }
};