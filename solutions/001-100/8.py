class Solution:
    def myAtoi(self, s: str) -> int:
        ans = 0
        sgn = 1
        idx = 0
        while idx < len(s) and s[idx] == " ":
            idx += 1
        if idx == len(s):
            return 0
        s = s[idx:]
        if s[0] == "-":
            sgn = -1
            s = s[1:]
        elif s[0] == "+":
            s = s[1:]
        for c in s:
            if c < "0" or c > "9":
                ans *= sgn
                if ans > 2**31 - 1:
                    return 2**31 - 1
                elif ans < -(2**31):
                    return -(2**31)
                return ans
            ans *= 10
            ans += ord(c) - ord("0")
        ans *= sgn
        if ans > 2**31 - 1:
            return 2**31 - 1
        elif ans < -(2**31):
            return -(2**31)
        return ans
