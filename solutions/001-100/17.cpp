const string number_string[] = { "abc", "def",  "ghi", "jkl",
                                 "mno", "pqrs", "tuv", "wxyz" };

class Solution {
  private:
    vector<string> ans;

  public:
    void dfs(string num, string seq) {
        if (num == "") {
            ans.push_back(seq);
            return;
        }
        for (auto &ch : number_string[num[0] - '2']) {
            dfs(num.substr(1), seq + ch);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits == "") {
            return vector<string>();
        }
        dfs(digits, "");
        return this->ans;
    }
};