class Solution {
  public:
    int mySqrt(int x) {
        if (x == 1) {
            return 1;
        }
        int l = 0;
        int r = x;
        long ptr = (l + r) / 2;
        while (l < r - 1) {
            if (ptr * ptr == x) {
                return ptr;
            }
            if (ptr * ptr > x) {
                r = ptr;
            } else {
                l = ptr;
            }
            ptr = (l + r) / 2;
        }
        return ptr;
    }
};