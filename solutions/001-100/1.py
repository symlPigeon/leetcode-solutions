from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        i = 0
        while nums != []:
            if target - nums[0] in nums[1:]:
                return [i, nums[1:].index(target - nums[0]) + 1 + i]
            i += 1
            nums = nums[1:]
