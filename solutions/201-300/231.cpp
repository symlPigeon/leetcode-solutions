class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) {
            return false;
        }
        return (n & ((long long)n - 1)) == 0;
    }
};

// 给你一个整数 n，请你判断该整数是否是 2 的幂次方。
