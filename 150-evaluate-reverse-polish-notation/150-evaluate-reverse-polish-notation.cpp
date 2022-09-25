class Solution {
public:
    bool isOperator(string s)
    {
        return s=="*" || s=="+" || s=="-" || s=="/";
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        for(string s : tokens)
        {
            if(isOperator(s))
            {
                long num2=st.top(); st.pop();
                long num1=st.top(); st.pop();
                if(s=="*")st.push(num1 * num2);
                else if(s=="+")st.push(num1 + num2);
                else if(s=="-")st.push(num1 - num2);
                else if(s=="/")st.push(num1 / num2);
            }
            else st.push(stoi(s));
                
        }
        return (int)st.top();
    }
};