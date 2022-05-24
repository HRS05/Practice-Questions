class Solution {
public:
    
    int longestValidParentheses(string s) {
        int ans=0;
        stack<int> st;
        st.push(-1);
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(') st.push(i);
            else
            {
                st.pop();
                if(st.empty()) 
                {
                    st.push(i);
                }
                else
                {
                    ans=max(ans,i-st.top());
                }
            }
        }
        return ans;
    }
    
    
    /*
    TC : O(n^2)
    SC : O(n)   
       
    int longestValidParentheses(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==')') continue;
            else
            {
                stack<char> st;
                int count=1;
                st.push(s[i]);
                for(int j=i+1;j<s.size();j++)
                {
                    if(s[j] == '(') 
                    {
                        st.push(s[j]);
                        count++;
                    }
                    else
                    {
                        if(!st.empty())
                        {
                            st.pop();
                            count++;
                        }
                        else break;
                    }
                    if(st.empty()) ans=max(ans,count);
                }
                
            }
        }
        return ans;
    }
    */
};