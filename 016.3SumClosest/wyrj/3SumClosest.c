/* 4ms */
int cmp(const void *a, const void *b) {
    int *aa = (int *)a;
    int *bb = (int *)b;
    if (*aa > *bb) {
        return 1;
    } else if (*aa < *bb) {
        return -1;
    } else {
        return 0;
    }
}
int abs(n) {
    return (n > 0) ? n : -n;
}
int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int i, j, k, retDiff = (1 << 31) - 1, ret;
    for (i = 0; i < numsSize - 2; i++) {
        j = i + 1;
        k = numsSize - 1;
        while(j < k) {
            int diff = nums[i] + nums[j] + nums[k] - target;
            if (abs(diff) < retDiff) {
                retDiff = abs(diff);
                ret = nums[i] + nums[j] + nums[k];
            }
            if (0 < diff) {
                k--;
            } else if (0 > diff) {
                j++;
            } else {
                return target;
            }
        }
    }
    return ret;
}