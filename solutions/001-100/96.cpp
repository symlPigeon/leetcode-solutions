// #include <vector>
// #include <iostream>

// using namespace std;

class Solution {
public:
    int ans[20] = {1,1,2,5,14,42,132,429,1430,4862,16796,58786,208012,742900,2674440,9694845,35357670,129644790,477638700,1767263190};
    int numTrees(int n) {
        return ans[n];
    }
    // int numTrees(int n) {
    //     vector<int> solution;
    //     solution.push_back(1);
    //     solution.push_back(1);
    //     for (int i = 2; i < 20; i++) {
    //         int ans = 0;
    //         for (int j = 1; j <= i; j++) {
    //             ans += solution[j - 1] * solution[i - j];
    //         }
    //         solution.push_back(ans);
    //     }
    //     for (int i = 0; i < 20; i++) {
    //         cout << solution[i] << ",";
    //     }
    //     cout << endl;
    //     return solution[n];
    // }
};
