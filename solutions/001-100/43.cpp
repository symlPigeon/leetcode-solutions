#include <algorithm>
#include <utility>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int num1_len = num1.size();
        int num2_len = num2.size();
        if (num1_len < num2_len) {
            swap(num1, num2);
            swap(num1_len, num2_len);
        }
        vector<int> num1_vec(num1_len, 0);
        vector<int> num2_vec(num2_len, 0);
        vector<int> mul(num1_len + num2_len + 1, 0);
        for (int i = 0; i < num1_len; i++) {
            num1_vec[i] = num1[i] - '0';
        }
        for (int i = 0; i < num2_len; i++) {
            num2_vec[i] = num2[i] - '0';
        }
        reverse(num1_vec.begin(), num1_vec.end());
        reverse(num2_vec.begin(), num2_vec.end());
        for (int i = 0; i < num2_len; i++) {
            for (int j = 0; j < num1_len; j++) {
                mul[i + j] += num1_vec[j] * num2_vec[i];
            }
        }
        for (int i = 0; i < num1_len + num2_len; i++) {
            if (mul[i] >= 10) {
                mul[i + 1] = mul[i] / 10;
                mul[i] %= 10;
            }
        }
        int i;
        for (i = num1_len + num2_len; i >= 0 && mul[i] == 0; i--);
        if (i == -1) {
            return "0";
        }
        string ans = "";
        for (; i >= 0; i--) {
            ans += mul[i] + '0';
        }
        return ans;
    }
};

// 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
