/* 24ms */
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
int *createElement(int a, int b, int c) {
    int *el = (int *)malloc(sizeof(int) * 3);
    el[0] = a;
    el[1] = b;
    el[2] = c;
    return el;
}
int** threeSum(int* nums, int numsSize, int* returnSize) {
    int **ret = (int **)malloc(sizeof(int *)*numsSize*numsSize);
    qsort(nums, numsSize, sizeof(int), cmp);
    int size = 0;
    int i, j, k;
    for (i = 0; i < numsSize - 2; i++) {
        if (0 < nums[i]) {
            break;
        }
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        k = numsSize - 1;
        for (j = i + 1; j < k; j++) {
            if (j != i + 1 && nums[j] == nums[j-1]) {
                continue;
            }
            while((0 < nums[i] + nums[j] + nums[k]) && k > j + 1) {
                k--;
            }
            if (0 == nums[i] + nums[j] + nums[k]) {
                ret[size++] = createElement(nums[i], nums[j], nums[k]);
            }
        }
    }
    *returnSize = size;
    return ret;
}