class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        def fac(n: int) -> int:
            if n == 0:
                return 1
            if n == 1:
                return 1
            return n * fac(n - 1)

        k -= 1

        nums = [i for i in range(1, n + 1)]
        ans = 0
        for _ in range(n - 1):
            f = fac(n - 1)
            ans += nums[k // f]
            ans *= 10
            nums.remove(nums[k // f])
            k %= f
            n -= 1
        return str(ans + nums[0])
