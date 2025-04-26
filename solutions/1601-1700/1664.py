class Solution:
    def waysToMakeFair(self, nums: List[int]) -> int:
        # 前缀和, sum_i mean \sum_{j=0}^{i-1} nums[j], i=0,1,2,...,n
        sum = [0]
        # 奇数位和, the same as sum but only odd index
        odd_sum = [0]
        # total length
        n = len(nums)
        # 计算前缀和，不包含当前位
        for i in range(n):
            sum += [sum[-1] + nums[i]]
            odd_sum += [odd_sum[-1] + nums[i] if i % 2 == 1 else odd_sum[-1]]

        ans = 0
        for i in range(0, n):
            # 元素i之前的偶数位之和
            prev_even_sum = sum[i] - odd_sum[i]
            # 元素i之后的奇数位之和
            after_odd_sum = odd_sum[n] - odd_sum[i + 1]
            # 删去当前位之后奇偶反转
            if sum[n] - nums[i] == 2 * (prev_even_sum + after_odd_sum):
                ans += 1
        return ans
