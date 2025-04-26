class Solution {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        vector<bool> can_spell(s.length());
        int min_len = s.length() + 1;
        for (auto &word : wordDict) {
            if (word.length() > s.length()) {
                continue;
            }
            if (s.substr(0, word.length()) == word) {
                can_spell[word.length() - 1] = true;
            }
        }
        for (int idx = 0; idx < s.length(); idx++) {
            if (!can_spell[idx]) {
                continue;
            }
            for (auto &word : wordDict) {
                if (idx + word.length() < s.length()) {
                    if (s.substr(idx + 1, word.length()) == word) {
                        can_spell[idx + word.length()] = true;
                    }
                }
            }
        }
        return can_spell[s.length() - 1];
    }
};