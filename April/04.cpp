// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/submissions/
class Solution
{
public:
    // just have track of open and close brackets
    int maxDepth(string s)
    {

        int length = s.length();
        int open = 0, close = 0, ans = 0;

        for (int i = 0; i < length; i++)
        {
            if (s[i] == '(')
                ans = max(ans, ++open);
            else if (s[i] == ')')
                open--;
        }
        return ans;
    }
};