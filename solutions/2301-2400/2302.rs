/*
 * 一个数组的 分数 定义为数组之和 乘以 数组的长度。
 *
 * 给你一个正整数数组 nums 和一个整数 k ，请你返回 nums 中分数 严格小于 k 的 非空整数子数组数目。
 *
 * 子数组是数组中的一个连续元素序列。
 *
 * 输入：nums = [2,1,4,3,5], k = 10
 * 输出：6
 *
 * 输入：nums = [1,1,1], k = 5
 * 输出：5
 */

impl Solution {
    pub fn count_subarrays(nums: Vec<i32>, k: i64) -> i64 {
        if nums.len() == 1 {
            if  (nums[0] as i64) < k {
                return 1;
            } else {
                return 0;
            }
        }
        let mut pre_sum = Vec::with_capacity(nums.len());
        pre_sum.push(0);
        for idx in 1..nums.len() {
            pre_sum.push(pre_sum[idx - 1] + nums[idx - 1] as i64);
        }
        let mut count = 0;
        let mut last_left = 0;
        if (nums[0] as i64) < k {
            count += 1;
        }
        for idx in 1..nums.len() {
            // [left, idx]
            let mut left = last_left;
            while left <= idx {
                let width = idx - left + 1;
                let sum = pre_sum[idx] - pre_sum[left] + nums[idx] as i64;
                if sum * (width as i64) < k {
                    // println!("{} -> {}", left, idx);
                    count += width;
                    break;
                }
                left += 1;
            }
            last_left = left;
        }
        count as i64
    }
}
