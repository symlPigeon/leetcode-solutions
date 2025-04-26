class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if strs == []:
            return ""
        suf = ""
        min_len = 200
        for i in strs:
            if len(i) < min_len:
                min_len = len(i)
        for i in range(min_len):
            suf += strs[0][i]
            for j in strs:
                if j[i] != strs[0][i]:
                    return suf[:-1]
        return suf
