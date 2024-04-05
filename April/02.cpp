// https://leetcode.com/problems/isomorphic-strings/

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int n = s.length();
        map<char, char> m1, m2;
        int i = 0, j = 0;
        while (i < n && j < n)
        {
            if (m1[s[i]] > 0 && m1[s[i]] != t[j])
                return false;
            if (m2[t[j]] > 0 && m2[t[j]] != s[i])
                return false;
            m1[s[i]] = t[j];
            m2[t[j]] = s[i];
            i++;
            j++;
        }
        return true;
    }
};