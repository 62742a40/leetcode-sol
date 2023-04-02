/*
 * @lc app=leetcode id=32 lang=c
 * @lcpr version=21901
 *
 * [32] Longest Valid Parentheses
 */

// #include <stdio.h>

#include <string.h>

// @lc code=start
int longestValidParentheses(char *s)
{

    unsigned short length = strlen(s);
    // 动态规划 is too much memory cost

    // cutoff left right bound
    while (length > 0 && s[0] != '(')
    {
        s++;
        length--;
    }
    while (length > 0 && s[length - 1] != ')')
    {
        length--;
    }

    s[length] = 0;

    if (length <= 2)
        return length == 2 ? 2 : 0;

    int ret = 0;
    unsigned short lnum = 1, rnum = 0, delta = 0;
    for (int i = 1; i < length; i++)
    {
        if (s[i] == '(')
            lnum += 1;
        else
            rnum += 1;
        if (rnum > lnum)
        {
            if (lnum << 1 > ret)
                ret = lnum << 1;

            lnum = 0;
            rnum = 0;
            delta = i + 1;
        }
    }

    if (lnum == rnum)
        return rnum << 1 < ret ? ret : rnum << 1;
    if (rnum << 1 <= ret)
        return ret;

    s = s + delta;
    length -= delta;
    lnum = 0, rnum = 1;
    for (int i = length - 2; i >= 0; i--)
    {
        if (s[i] == ')')
            rnum += 1;
        else
            lnum += 1;
        if (lnum > rnum)
        {
            if (rnum << 1 > ret)
                ret = rnum << 1;
            lnum = 0;
            rnum = 0;
        }
    }

    return lnum << 1 < ret ? ret : lnum << 1;
}
// @lc code=end

/*
// @lcpr case=start
// "(()"\n
// @lcpr case=end

// @lcpr case=start
// ")()())"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

 */

// int main()
// {
//     char s[] = "(())()(()((";
//     int ret = longestValidParentheses(s);
//     printf("%d \n", ret);
// }