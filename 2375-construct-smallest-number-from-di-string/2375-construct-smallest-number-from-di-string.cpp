class Solution {
public:
    string smallestNumber(string pattern) {
       stack<char> st;
        char num='1';
        string ans="";
        for(char c : pattern)
        {
            if(c=='D')
            {
                st.push(num);
                num++;
            }
            else
            {
                st.push(num);
                num++;
                while(!st.empty())
                {
                    ans+=st.top();
                    st.pop();
                }
            }
        }
        st.push(num);
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};