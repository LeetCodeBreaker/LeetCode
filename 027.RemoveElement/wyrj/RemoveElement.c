/* 0ms */
int removeElement(int* nums, int numsSize, int val) {
    int index = 0;
    while(index < numsSize) {
        if (nums[index] == val) {
            nums[index] = nums[numsSize - 1];
            numsSize--;
        } else {
            index++;
        }
    }
    return numsSize;
}