/*
 * @lc app=leetcode id=5 lang=c
 * @lcpr version=21901
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start

#include <string.h>

char *longestPalindrome(char *s)
{

    int length = strlen(s);
    if (length <= 1)
        return s;
    if (length == 2)
        return s[0] == s[1] ? s : s + 1;
    int mlidx = 0, mridx = 0, lidx = 0, ridx = 0;
    for (int i = 1; i < length - 1; i++)
    {
        lidx = ridx = i;
        while (lidx > 0 && ridx < length - 1 && s[lidx - 1] == s[ridx + 1])
        {
            lidx--;
            ridx++;
        }
        if (ridx - lidx > mridx - mlidx)
        {
            mridx = ridx;
            mlidx = lidx;
        }
    }
    if (mlidx == mridx)
    {
        if (s[0] == s[1])
        {
            mlidx = 0;
            mridx = 1;
        }
        else if (s[length - 2] == s[length - 1])
        {
            mlidx = length - 2;
            mridx = length - 1;
        }
    }
    if (length > 3)
    {
        for (int i = 1; i < length - 2; i++)
        {
            if (s[i] == s[i + 1])
            {
                lidx = i;
                ridx = i + 1;
                while (lidx > 0 && ridx < length - 1 && s[lidx - 1] == s[ridx + 1])
                {
                    lidx--;
                    ridx++;
                }
            }
            if (ridx - lidx > mridx - mlidx)
            {
                mridx = ridx;
                mlidx = lidx;
            }
        }
    }

    s[mridx + 1] = '\0';
    return s + mlidx;
}
// @lc code=end

/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */
