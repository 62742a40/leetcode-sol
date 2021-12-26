/*
 * @lc app=leetcode id=4 lang=c
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start

// kth , 1 ...,n

double findKthSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size, int kth)
{
    if (nums1Size == 0)
    {
        return nums2[kth - 1];
    }
    if (nums2Size == 0)
    {
        return nums1[kth - 1];
    }
    if (kth == 1)
    {
        return nums2[0] > nums1[0] ? nums1[0] : nums2[0];
    }
    int kth_left_half = kth / 2;
    int kth_right_half = kth / 2;

    if (nums1Size < kth_left_half)
    {
        kth_left_half = nums1Size;
    }
    if (nums2Size < kth_right_half)
    {
        kth_right_half = nums2Size;
    }

    if (nums1[kth_left_half - 1] <= nums2[kth_right_half - 1])
    {
        nums1 += kth_left_half;
        nums1Size -= kth_left_half;
        kth -= kth_left_half;
    }
    else if (nums1[kth_left_half - 1] > nums2[kth_right_half - 1])
    {
        nums2 += kth_right_half;
        nums2Size -= kth_right_half;
        kth -= kth_right_half;
    }
    return findKthSortedArrays(nums1, nums1Size, nums2, nums2Size, kth);
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    // find (nums1Size+nums2Size)/2 th num
    int left_kth = (nums1Size+nums2Size+1)/2;
    int right_kth = (nums1Size+nums2Size+2)/2;

    return (findKthSortedArrays(nums1,nums1Size,nums2,nums2Size,left_kth)+
    findKthSortedArrays(nums1,nums1Size,nums2,nums2Size,right_kth))/2.0;
}
// @lc code=end
