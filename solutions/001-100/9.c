#include <stdbool.h>

bool isPalindrome(int x) {
    if (x < 0)
        return false;
    long ans = 0;
    int temp = x;
    while (temp) {
        ans *= 10;
        ans += temp % 10;
        temp /= 10;
    }
    return ans == x;
}