// https://leetcode.com/problems/length-of-last-word/

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int ans = 0;
        int i = s.length() - 1;
        while (s[i] == ' ')
            i--;
        for (; i >= 0; i--)
        {
            if (s[i] != ' ')
                ans++;
            else
                return ans;
        }
        return ans;
    }
};
