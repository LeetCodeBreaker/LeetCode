/* 24ms */
void findMedian(int* arr1, int len1, int start1, int* arr2, int len2, int start2, int target, int*ret) {
    if (start1 == len1) {
        ret[0] = start1;
        ret[1] = start2 + target;
        return ;
    } else if (start2 == len2) {
        ret[0] = start1 + target;
        ret[1] = start2;
        return ;
    }
    if (1 == target) {
        if (arr1[start1] >= arr2[start2]) {
            ret[0] = start1;
            ret[1] = start2 + 1;
            return ;
        } else {
            ret[0] = start1 + 1;
            ret[1] = start2;
            return ;
        }
    }
    int half = target / 2;
    int n1 = (half + start1 - 1 >= len1) ? len1 - 1 : half + start1 - 1;
    int n2 = (half + start2 - 1 >= len2) ? len2 - 1 : half + start2 - 1;
    if (arr1[n1] >= arr2[n2]) {
        return findMedian(arr1, len1, start1, arr2, len2, n2+1, target-(n2-start2+1), ret);
    } else {
        return findMedian(arr1, len1, n1+1, arr2, len2, start2, target-(n1-start1+1), ret);
    }
}
int min(int* arr1, int len1, int index1, int* arr2, int len2, int index2) {
    if (index1 < 0 || index1 >= len1) {
        return arr2[index2];
    } else if (index2 < 0 || index2 >= len2){
        return arr1[index1];
    } else {
        return (arr2[index2] >= arr1[index1]) ? arr1[index1] : arr2[index2];
    }
}
int max(int* arr1, int len1, int index1, int* arr2, int len2, int index2) {
    if (index1 < 0 || index1 >= len1) {
        return arr2[index2];
    } else if (index2 < 0 || index2 >= len2){
        return arr1[index1];
    } else {
        return (arr2[index2] <= arr1[index1]) ? arr1[index1] : arr2[index2];
    }
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int next[2];
    findMedian(nums1, nums1Size, 0, nums2, nums2Size, 0, (nums1Size+nums2Size)/2, next);
    if (0 == (nums1Size + nums2Size) % 2) {
        return ((double)(min(nums1, nums1Size, next[0], nums2, nums2Size, next[1])) + (double)(max(nums1, nums1Size, next[0]-1, nums2, nums2Size, next[1]-1))) / 2;
    } else {
        return (double)(min(nums1, nums1Size, next[0], nums2, nums2Size, next[1]));
    }
}