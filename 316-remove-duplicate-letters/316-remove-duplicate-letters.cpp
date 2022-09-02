class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans="";
        int n=s.size();
        unordered_map<char,int> M;
        unordered_map<char,bool> V;
        stack<int> st;
        
        for(int i=0;i<n;i++) M[s[i]]++;
        
        for(pair<char,int> p : M) V[p.first]=false;
        
        for(int i=0;i<n;i++)
        {
            M[s[i]]--;
            if(V[s[i]] == true) continue;
            
            while(!st.empty() && s[i] < s[st.top()] && M[s[st.top()]]){
                V[s[st.top()]]=false;
                st.pop();
            }
            
            st.push(i);
            
            V[s[i]]=true;
        }
        
        
        while(!st.empty())
        {
            ans = s[st.top()] + ans;
            st.pop();
        }
        
        
        return ans;
    }
};