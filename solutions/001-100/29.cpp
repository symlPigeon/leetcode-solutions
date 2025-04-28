/* 给你两个整数，被除数 dividend 和除数 divisor。将两数相除，要求 不使用 乘法、除法和取余运算。

整数除法应该向零截断，也就是截去（truncate）其小数部分。例如，8.345 将被截断为 8 ，-2.7335 将被截断至 -2 。

返回被除数 dividend 除以除数 divisor 得到的 商 。

注意：假设我们的环境只能存储 32 位 有符号整数，其数值范围是 [−231,  231 − 1] 。本题中，如果商 严格大于 231 − 1 ，则返回 231 − 1 ；如果商 严格小于 -231 ，则返回 -231 。
*/

#include <iostream>
#include <climits>

using namespace std;

class Solution {
  public:
    int divide(int dividend, int divisor) {
        int sign = 0;
        long long result = 0;
        long long factor = 1;
        long long dividend_ = dividend;
        long long divisor_ = divisor;
        if (dividend_ < 0) {
            sign ^= 1;
            dividend_ = -dividend_;
        }
        if (divisor_ < 0) {
            sign ^= 1;
            divisor_ = -divisor_;
        }
        if (dividend_ < divisor_) {
            return 0;
        }
        while (dividend_ >= divisor_) {
            divisor_ <<= 1;
            factor <<= 1;
        }
        while (factor > 0) {
            while (divisor_ <= dividend_) {
                dividend_ -= divisor_;
                result += factor;
            }  
            divisor_ >>= 1;
            factor >>= 1;
        }
        if (sign) {
            result = -result;
        }
        if (result > INT_MAX) {
            return INT_MAX;
        }
        if (result < INT_MIN) {
            return INT_MIN;
        }
        return result;
    }
};

int main() {
  Solution s;
  cout << s.divide(-2147483648, -1) << endl;
}
