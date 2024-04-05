// April 5
//  https://leetcode.com/problems/make-the-string-great/

class Solution
{
public:
    // stack solution -- having a track of current and prev char
    string makeGood(string s)
    {

        int n = s.length();
        stack<char> st;
        string temp = "";

        for (int i = 0; i < n; i++)
        {

            if (!st.empty() && (st.top() + 32 == s[i] || st.top() - 32 == s[i]))
                st.pop();
            else
                st.push(s[i]);
        }

        // take out letters from stack and push into the string

        while (!st.empty())
        {
            temp = st.top() + temp;
            st.pop();
        }
        return temp;
    }
};