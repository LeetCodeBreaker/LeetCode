/* 4ms */
int reverse(int x) {
    if (x == 1 << 31) {
        return 0;
    }
    if (x < 0) {
        return -reverse(-x);
    }
    int INTMAX = (1 << 31) - 1;
    int ret = 0, delta, n;
    while(x > 0) {
        n = x % 10;
        if ((INTMAX - n) / 10 < ret) {
            return 0;
        }
        ret = (ret * 10) + n;
        x = x / 10;
    }
    return ret;
}