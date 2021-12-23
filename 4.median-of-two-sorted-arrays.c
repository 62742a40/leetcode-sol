/*
 * @lc app=leetcode id=4 lang=c
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{

#define get_cn(s, n)                                \
    do                                              \
    {                                               \
        if (n % 2 == 0)                             \
        {                                           \
            return (s[n / 2] + s[n / 2 - 1]) / 2.0; \
        }                                           \
        else                                        \
        {                                           \
            return s[n / 2];                        \
        }                                           \
    } while (0);

    while (nums1Size >= 1 && nums2Size >= 1 && nums1Size + nums2Size > 2)
    {
        if (nums1[0] >= nums2[0])
        {
            nums2++;
            nums2Size--;
        }
        else
        {
            nums1++;
            nums1Size--;
        }
        if (nums1[nums1Size - 1] >= nums2[nums2Size - 1])
        {
            nums1Size--;
        }
        else
        {
            nums2Size--;
        }
    }

    if (nums1Size == 0)
    {
        get_cn(nums2, nums2Size);
    }
    else if (nums2Size == 0)
    {
        get_cn(nums1, nums1Size);
    }
    else
    {
        return (nums1[0] + nums2[0]) / 2.0;
    }
}
// @lc code=end
