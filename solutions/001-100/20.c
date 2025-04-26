bool isValid(char *s) {
#define SMALL_BRACE 0x1
#define MIDDLE_BRACE 0x2
#define BIG_BRACE 0x3
    unsigned len = strlen(s);
    char *stk = (char *)malloc(len);
    int idx = 0;
    memset(stk, 0, len);
    for (unsigned i = 0; i < len; i++) {
        switch (s[i]) {
        case '(':
            stk[idx / 4] |= SMALL_BRACE << (2 * (3 - idx % 4));
            idx += 1;
            break;
        case '[':
            stk[idx / 4] |= MIDDLE_BRACE << (2 * (3 - idx % 4));
            idx += 1;
            break;
        case '{':
            stk[idx / 4] |= BIG_BRACE << (2 * (3 - idx % 4));
            idx += 1;
            break;
        case ')':
            if (idx == 0) {
                free(stk);
                return false;
            }
            idx -= 1;
            if ((((stk[idx / 4] & (0b11 << (2 * (3 - idx % 4)))) >>
                  (2 * (3 - idx % 4))) &
                 0b11) != SMALL_BRACE) {
                free(stk);
                return false;
            }
            stk[idx / 4] &= ~(0b11 << (2 * (3 - idx % 4)));
            break;
        case ']':
            if (idx == 0) {
                free(stk);
                return false;
            }
            idx -= 1;
            if ((((stk[idx / 4] & (0b11 << (2 * (3 - idx % 4)))) >>
                  (2 * (3 - idx % 4))) &
                 0b11) != MIDDLE_BRACE) {
                free(stk);
                return false;
            }
            stk[idx / 4] &= ~(0b11 << (2 * (3 - idx % 4)));
            break;
        case '}':
            if (idx == 0) {
                free(stk);
                return false;
            }
            idx -= 1;
            if ((((stk[idx / 4] & (0b11 << (2 * (3 - idx % 4)))) >>
                  (2 * (3 - idx % 4))) &
                 0b11) != BIG_BRACE) {
                free(stk);
                return false;
            }
            stk[idx / 4] &= ~(0b11 << (2 * (3 - idx % 4)));
            break;
        }
    }
    if (idx != 0) {
        free(stk);
        return false;
    }
    free(stk);
    return true;
}