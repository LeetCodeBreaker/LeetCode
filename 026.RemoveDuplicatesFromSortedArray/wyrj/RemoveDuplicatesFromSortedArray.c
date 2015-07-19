/* 12ms */
int removeDuplicates(int* nums, int numsSize) {
    if (0 == numsSize) {
        return 0;
    }
    int index = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[index] != nums[i]) {
            index ++;
            nums[index] = nums[i];
        }
    }
    return index + 1;
}