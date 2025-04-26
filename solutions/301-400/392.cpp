class Solution {
  public:
    bool isSubsequence(string s, string t) {
        int ptrs = 0;
        int ptrt = 0;
        if (s.length() > t.length()) {
            return false;
        }
        while (ptrt < t.length()) {
            if (s[ptrs] != t[ptrt]) {
                ptrt++;
            } else {
                ptrs++;
                ptrt++;
            }
        }
        return ptrs == s.length();
    }
};