// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

class Solution
{
public:
    // at any time if close>open ( then remove that close bracket )
    // if open > close then remove open ( but when shall i remove ) ( keep count and end mai remove ) -- may b

    // error i get is i cant remove any ( , need to remove non closing open brackets
    // FAIL

    // shall i need to have index of ( ?  //have a stack
    // FAIL

    // I need to have info about {bracket type and index} both
    // SUCCESS

    string minRemoveToMakeValid(string s)
    {
        int n = s.length();
        // string temp="";
        //         int open=0,close=0;

        //         for(int i=0;i<n;i++){

        //             if(s[i]=='(')open++;
        //             else if(s[i]==')')close++;

        //             if(close==open){
        //                 close=0,open=0;
        //             }
        //             if(close>open)close--; //dont add this
        //             else temp+=s[i];
        //         }

        //         if(open==close)return temp;

        //         string ans="";
        //         //we have more open than close now , so remove them

        //         int remove=open-close;

        //         for(int i=0;i<temp.length();i++){
        //             if(temp[i]=='('){
        //                 //got the open bracket  ,  now if remove>0 then remove open
        //                 if(--remove>=0){
        //                     //need to remove
        //                     continue;
        //                 }else{
        //                     ans+=temp[i]; //add this open bracket
        //                 }
        //             }else{
        //                 ans+=temp[i];
        //             }
        //         }
        //         return ans;

        //         int open=0,close=0;
        //         stack<char>st;
        //         for(int i=0;i<n;i++){
        //             if(s[i]=='('){
        //                 st.push(i);
        //             }else if(s[i]==')'){
        //                 //check for opening before and remove them both
        //                 if(st.size()>0){
        //                     st.pop();
        //                 }else{
        //                     st.push(i);
        //                 }
        //             }
        //         }
        //         string ans="";
        //         for(int i=0;i<n;i++){
        //             if(st.size()>0 && i==st.top()){
        //                 st.pop();
        //             }else{
        //                 ans+=s[i];
        //             }
        //         }return ans;

        stack<pair<char, int>> st;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                st.push({'(', i});
            }
            else if (s[i] == ')')
            {
                // if we have corresponding open bracket remove it
                if (!st.empty())
                {
                    if (st.top().first == '(')
                        st.pop();
                    else
                        st.push({')', i});
                }
                else
                {
                    // push this close bracket now
                    st.push({')', i});
                }
            }
        }
        // now i am sure that i dont have any () pairs left , in stack both ( and ) are there max possibility
        string ans = "";
        for (int i = n - 1; i >= 0; i--)
        {
            if (st.size() > 0 && i == st.top().second)
            {
                st.pop();
            }
            else
            {
                ans += s[i];
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};