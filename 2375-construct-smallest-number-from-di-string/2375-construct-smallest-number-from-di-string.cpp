class Solution {
public:
    string smallestNumber(string pattern) {
       stack<string> st;
        int num=1;
        string ans="";
        for(char c : pattern)
        {
            if(c=='D')
            {
                st.push(to_string(num));
                num++;
            }
            else
            {
                st.push(to_string(num));
                num++;
                while(!st.empty())
                {
                    ans+=st.top();
                    st.pop();
                }
            }
        }
        st.push(to_string(num));
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};