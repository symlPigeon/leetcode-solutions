class Solution {
  public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int head = 0;
        int last = numbers.size() - 1;
        while (head < last) {
            if (numbers[head] + numbers[last] == target) {
                vector<int> ans;
                ans.push_back(head + 1);
                ans.push_back(last + 1);
                return ans;
            }
            if (numbers[head] + numbers[last] > target) {
                last--;
            } else {
                head++;
            }
        }
        std::unreachable();
    }
};