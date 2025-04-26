int reverse(int x) {
    char pos = (x > 0);
    if (x == -2147483648)
        return 0;
    x = x > 0 ? x : -x;
    int ans = 0;
    while (x) {
        if (ans > 0xccccccc)
            return 0;
        else
            ans *= 10;
        ans += x % 10;
        x /= 10;
    }
    if (!pos)
        return -ans;
    else
        return ans;
}