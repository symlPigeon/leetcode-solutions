class Solution {
  public:
    int minSubArrayLen(int target, vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0] >= target ? 1 : 0;
        }
        int window_start = 0;
        int window_end = 1;
        int sum = nums[0];
        int min_length =
            nums[0] > target ? window_end - window_start : 2147483647;
        while (window_end < nums.size()) {
            sum += nums[window_end++];
            while (sum - nums[window_start] >= target) {
                sum -= nums[window_start++];
            }
            // std::cout << "current: " << window_start << "->" << window_end <<
            // "=" << sum << std::endl;
            if (window_end - window_start < min_length && sum >= target) {
                // std::cout << "current best: " << window_start << "->" <<
                // window_end << "=" << sum << std::endl;
                min_length = window_end - window_start;
            }
        }
        return sum >= target ? min_length : 0;
    }
};