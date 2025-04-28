impl Solution {
    pub fn largest_good_integer(num: String) -> String {
        let mut ans = "";
        let mut ans_num = -1;
        assert!(num.len() >= 3);
        let nums: Vec<char> = num.chars().collect();
        for i in 0..(nums.len() - 2) {
            if nums[i] == nums[i + 1] && nums[i] == nums[i + 2] {
                let n = (nums[i] as u8 - b'0') as i32;
                if n > ans_num {
                    ans_num = n;
                    ans = &num[i..i + 3];
                }
            }
        }
        ans.to_string()
    }
}

/*
 给你一个字符串 num ，表示一个大整数。如果一个整数满足下述所有条件，则认为该整数是一个 优质整数 ：

 该 整数是 num 的一个长度为 3 的 子字符串 。
 该整数由唯一一个数字重复 3 次组成。
 以字符串形式返回 最大的优质整数 。如果不存在满足要求的整数，则返回一个空字符串 "" 。
 */
