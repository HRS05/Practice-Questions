class Solution {
public:
    
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<long (int, int) > > map = {
            { "+" , [] (int a, int b) { return a + b; } },
            { "-" , [] (int a, int b) { return a - b; } },
            { "*" , [] (int a, int b) { return (long)a * b; } },
            { "/" , [] (int a, int b) { return a / b; } }
        };
        std::stack<int> stack;
        for (string& s : tokens) {
            if (!map.count(s)) {
                stack.push(stoi(s));
            } else {
                int op1 = stack.top();
                stack.pop();
                int op2 = stack.top();
                stack.pop();
                stack.push(map[s](op2, op1));
            }
        }
        return stack.top();
    }

    
    
    /*
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
    */
};