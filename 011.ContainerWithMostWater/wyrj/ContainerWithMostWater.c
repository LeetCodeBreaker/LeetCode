/* 8ms */
int maxArea(int* height, int heightSize) {
    int i = 0, j = heightSize - 1;
    int ret = 0, c;
    while(i < j) {
        if (height[i] > height[j]) {
            c = height[j] * (j-i);
            j--;
        } else {
            c = height[i] * (j-i);
            i++;
        }
        if (c > ret) {
            ret = c;
        }
    }
    return ret;
}