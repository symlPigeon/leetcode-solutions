class Solution {
  public:
    bool isPalindrome(string s) {
        int ptr_head = 0;
        int ptr_tail = s.length() - 1;
        while (ptr_head < ptr_tail) {
            while ((ptr_head < ptr_tail) && (!std::isalnum(s[ptr_head]))) {
                ptr_head++;
            }
            while ((ptr_head < ptr_tail) && (!std::isalnum(s[ptr_tail]))) {
                ptr_tail--;
            }
            if (std::tolower(s[ptr_head]) != std::tolower(s[ptr_tail])) {
                return false;
            }
            ptr_head++;
            ptr_tail--;
        }
        return true;
    }
};