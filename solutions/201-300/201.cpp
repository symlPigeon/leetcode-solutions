class Solution {
  public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            if ((left & (1 << i)) == (right & (1 << i))) {
                ans |= right & (1 << i);
            } else {
                break;
            }
        }
        return ans;
    }
};