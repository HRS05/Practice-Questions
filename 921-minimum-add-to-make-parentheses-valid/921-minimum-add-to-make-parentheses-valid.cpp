class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int ans=0;
        for(char c : s)
        {
            if(c=='(')st.push(c);
            else if(c==')' && st.empty()) ans++;
            else if(c==')') st.pop();
        }
        ans+=st.size();
        return ans;
    }
};