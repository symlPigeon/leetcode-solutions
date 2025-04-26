impl Solution {
    const ans: [bool; 100] = [
        false, true, false, false, false, false, false, true, false, false, true, false, false,
        true, false, false, false, false, false, true, false, false, false, true, false, false,
        false, false, true, false, false, true, true, false, false, false, false, false, false,
        false, false, false, false, false, true, false, false, false, false, true, false, false,
        false, false, false, false, false, false, false, false, false, false, false, false, false,
        false, false, false, true, false, true, false, false, false, false, false, false, false,
        false, true, false, false, true, false, false, false, true, false, false, false, false,
        true, false, false, true, false, false, true, false, false,
    ];
    pub fn is_happy(n: i32) -> bool {
        let mut m = n;
        while m >= 100 {
            let mut sum = 0;
            while m > 0 {
                sum += (m % 10) * (m % 10);
                m /= 10;
            }
            m = sum;
        }
        Solution::ans[m as usize]
    }
}

// ans = ["false"]

// def check_is_happy(n):
//     track = []
//     print(n)
//     while True:
//         if n in track:
//             return False
//         track.append(n)
//         if n == 1:
//             return True
//         if n < len(ans):
//             if ans[n] == "true":
//                 return True
//             else:
//                 return False
//         s = 0
//         while n != 0:
//             s += (n % 10) ** 2
//             n //= 10
//         n = s

// for i in range(1, 100):
//     if check_is_happy(i):
//         ans.append("true")
//     else:
//         ans.append("false")

// print("[", ", ".join(ans), "]")
