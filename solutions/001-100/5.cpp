#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    string longestPalindrome(string s) {
        if (s.length() == 1) {
            return s;
        }
        int max_len = 0;
        int max_start = 0;
        for (int i = 0; i < s.length(); i++) {
            int j;
            for (j = 0;
                 i - j >= 0 && i + j < s.length() && s[i - j] == s[i + j]; j++)
                ;
            j -= 1;
            if (1 + 2 * j > max_len) {
                max_len = 1 + 2 * j;
                max_start = i - j;
            }
            for (j = 1; i - j + 1 >= 0 && i + j < s.length() &&
                        s[i - j + 1] == s[i + j];
                 j++)
                ;
            j -= 1;
            if (2 * j > max_len) {
                max_len = j * 2;
                max_start = i - j + 1;
            }
        }
        std::cout << max_start << "," << max_len << std::endl;
        return s.substr(max_start, max_len);
    }
};