/* 48ms */
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
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
int *createElement(int a, int b, int c, int d) {
    int *el = (int *)malloc(sizeof(int) * 3);
    el[0] = a;
    el[1] = b;
    el[2] = c;
    el[3] = d;
    return el;
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    int **ret = (int **)malloc(sizeof(int *)*numsSize*numsSize);
    qsort(nums, numsSize, sizeof(int), cmp);
    int size = 0;
    int i, j, k, l;
    for (i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        for (j = i + 1; j < numsSize - 2; j++) {
            if (j != i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }
            l = numsSize - 1;
            for (k = j + 1; k < l; k++) {
                if (k != j + 1 && nums[k] == nums[k-1]) {
                    continue;
                }
                while((target < nums[i] + nums[j] + nums[k] + nums[l]) && l > k + 1) {
                    l--;
                }
                if (target == nums[i] + nums[j] + nums[k] + nums[l]) {
                    ret[size++] = createElement(nums[i], nums[j], nums[k], nums[l]);
                }
            }
        }
    }
    *returnSize = size;
    return ret;
}