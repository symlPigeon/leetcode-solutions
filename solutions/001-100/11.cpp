class Solution {
  public:
    int maxArea(vector<int> &height) {
        int head = 0;
        int tail = height.size() - 1;
        int best_head = head;
        int best_tail = tail;
        auto get_ans = [](int head, int tail, vector<int> &height) {
            return (tail - head) *
                   (height[tail] < height[head] ? height[tail] : height[head]);
        };
        int best_ans = get_ans(best_head, best_tail, height);
        while (head < tail) {
            if (get_ans(head, tail, height) > best_ans) {
                best_head = head;
                best_tail = tail;
                best_ans = get_ans(best_head, best_tail, height);
            }
            if (height[head] > height[tail]) {
                tail--;
            } else {
                head++;
            }
        }
        return best_ans;
    }
};