class Solution {
  public:
    long long solution(vector<int> &nums, int minK, int maxK) {
        if (nums.size() == 0) {
            return 0;
        }
        vector<int> last_mink(nums.size(), -1);
        vector<int> last_maxk(nums.size(), -1);
        if (nums[0] == minK) {
            last_mink[0] = 0;
        }
        if (nums[0] == maxK) {
            last_maxk[0] = 0;
        }
        for (int i = 1; i < nums.size(); i++) {
            last_mink[i] = nums[i] == minK ? i : last_mink[i - 1];
            last_maxk[i] = nums[i] == maxK ? i : last_maxk[i - 1];
        }

        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (last_mink[i] == -1 || last_maxk[i] == -1) {
                continue;
            }
            int last_satisfy = min(last_mink[i], last_maxk[i]);
            ans += last_satisfy + 1;
        }
        return ans;
    }
    long long countSubarrays(vector<int> &nums, int minK, int maxK) {
        // 找到不合适的数，将子数组分解为若干个区间
        vector<vector<int>> sub_nums;
        int start = 0;
        while (start < nums.size()) {
            while (start < nums.size() &&
                   (nums[start] > maxK || nums[start] < minK)) {
                start++;
            }
            int end = start;
            while (end < nums.size() &&
                   (nums[end] <= maxK && nums[end] >= minK)) {
                end++;
            }
            sub_nums.push_back(
                vector<int>(nums.begin() + start, nums.begin() + end));
            start = end;
        }
        long long ans = 0;
        for (vector<int> &v : sub_nums) {
            ans += this->solution(v, minK, maxK);
        }
        return ans;
    }
};