class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size() - 2; i++) {
            int target = -nums[i];
            int head = i + 1;
            int last = nums.size() - 1;
            while (head < last) {
                if (nums[head] + nums[last] == target) {
                    ans.push_back({ nums[i], nums[head], nums[last] });
                    while ((head < last) && (nums[head + 1] == nums[head]))
                        head++;
                    while ((head < last) && (nums[last - 1] == nums[last]))
                        last--;
                }
                if (nums[head] + nums[last] > target) {
                    while ((head < last) && (nums[last - 1] == nums[last]))
                        last--;
                    last--;
                } else {
                    while ((head < last) && (nums[head + 1] == nums[head]))
                        head++;
                    head++;
                }
            }
            while (i < nums.size() - 2 && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        return ans;
    }
};