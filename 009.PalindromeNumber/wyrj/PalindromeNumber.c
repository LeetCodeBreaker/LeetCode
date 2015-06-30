/* 56ms */
bool isPalindrome(int x) {
    if (0 > x) {
        return false;
    }
    int arr[100], len = 0;
    while(0 < x) {
        arr[len++] = x % 10;
        x = x / 10;
    }
    int start = 0, end = len - 1;
    while(start < end) {
        if (arr[start] != arr[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}