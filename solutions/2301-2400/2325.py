class Solution:
    def decodeMessage(self, key: str, message: str) -> str:
        s = set()
        m = {}
        val = 0
        for ch in key:
            if ch not in s and ch in "abcdefghijklmnopqrstuvwxyz":
                s.add(ch)
                m[ch] = chr(val + 97)
                val += 1
        ans = ""
        for ch in message:
            if ch in m:
                ans += m[ch]
            else:
                ans += ch
        return ans
