/* 7ms */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b) {
    int* aa = (int*)a;
    int* bb = (int*)b;
    if (*aa > *bb) {
        return 1;
    } else if (*aa < *bb) {
        return -1;
    } else {
        return 0;
    }
}

int findIndex(int* array, int target, int start, int delta) {
    int i = start;
    while(array[i] != target) {
        i += delta;
    }
    return i;
}

int* twoSum(int* nums, int numsSize, int target) {
    int* cloned = (int*)malloc(sizeof(int)*numsSize);
    memcpy(cloned, nums, sizeof(int)*numsSize);
    qsort(cloned, numsSize, sizeof(int), cmp);
    int i = 0, j = numsSize - 1;
    while (i < j) {
        if (cloned[i] + cloned[j] < target) {
            i++;
        } else if (cloned[i] + cloned[j] > target) {
            j--;
        } else {
            break;
        }
    }
    int* ans = (int*)malloc(sizeof(int)*2);
    ans[0] = findIndex(nums, cloned[i], 0, 1) + 1;
    ans[1] = findIndex(nums, cloned[j], numsSize-1, -1) + 1;
    qsort(ans, 2, sizeof(int), cmp);
    return ans;
}