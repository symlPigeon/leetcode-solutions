#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 1) {
            return vector<int>({0, 1});
        }
        vector<int> ans;
        vector<int> sub_code = grayCode(n - 1);
        for (int i: sub_code) {
            ans.push_back(i);
        }
        reverse(sub_code.begin(), sub_code.end());
        for (int i: sub_code) {
            ans.push_back(i | (1 << (n - 1)));
        }
        return ans;
    }
};
