class Solution {
  public:
    int rob(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> stole;
        vector<int> skip;
        stole.push_back(nums[0]);
        skip.push_back(0);
        for (int i = 1; i < nums.size(); i++) {
            stole.push_back(nums[i] + skip[i - 1]);
            skip.push_back(stole[i - 1] > skip[i - 1] ? stole[i - 1] :
                                                        skip[i - 1]);
        }
        return stole[nums.size() - 1] > skip[nums.size() - 1] ?
                   stole[nums.size() - 1] :
                   skip[nums.size() - 1];
    }
};