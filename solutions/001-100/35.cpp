class Solution {
  public:
    int searchInsert(vector<int> &nums, int target) {
        if (target < nums[0]) {
            return 0;
        }
        int l = 0;
        int r = nums.size();
        while (l < r) {
            int ptr = (l + r) / 2;
            if (nums[ptr] == target) {
                return ptr;
            }
            if (nums[ptr] > target) {
                r = ptr;
            } else {
                l = ptr + 1;
            }
            ptr = (l + r) / 2;
        }
        return r;
    }
};