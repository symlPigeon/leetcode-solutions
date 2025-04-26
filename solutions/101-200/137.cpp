class Solution {
  public:
    int singleNumber(vector<int> &nums) {
        vector<uint8_t> bitcnt(32, 0);
        for (int &num : nums) {
            uint32_t n = num;
            int bitidx = 0;
            while (n > 0) {
                bitcnt[bitidx] += n & 1;
                bitcnt[bitidx++] %= 3;
                n >>= 1;
            }
        }
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++) {
            ans += (bitcnt[i] & 1) << i;
        }
        return (int)ans;
    }
};