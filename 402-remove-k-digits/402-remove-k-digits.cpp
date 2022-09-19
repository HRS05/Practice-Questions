class Solution {
public:
    
        string removeKdigits(string num, int k) 
        {
            string ans;
            int n=num.size();
            if(k>=num.size()) return "0";
            if(k==0) return num;
            stack<char> st;
            st.push(num[0]);
            
            for(int i=1;i<num.size();i++)
            {
                while(k>0 && !st.empty() && num[i] < st.top())
                {
                    k--;
                    st.pop();
                }
                st.push(num[i]);
                if(st.size() == 1 && num[i]=='0') st.pop();
            }
            
            while(k && !st.empty())
            {
                --k;
                st.pop();
            }

            while(!st.empty())
            {
                ans.push_back(st.top()); 
                st.pop(); 
            }

            reverse(ans.begin(),ans.end());

            if(ans.length() == 0)
                return "0";

            
            return ans;
        }
    
//     string helper(int i,string num,int k,vector<vector<vector<string> > > &dp)
//     {
//         if(k==0) return num;
//         if(i>=num.size()) return "a";
//         if(dp[i][k][num[i]]!="-1") return dp[i][k][num[i]];
//         string left=num.substr(0,i);
//         string right= num.substr(i+1);
        
//         string check1=helper(i,left+right,k-1,dp);
//         string check2=helper(i+1,num,k,dp);
//         return dp[i][k][num[i]]=check1 > check2 ? check2 : check1;
//     }
    
//     string removeKdigits(string num, int k) {
//         string ans;
//         vector<vector<vector<string> >  > dp(num.size(),vector<vector<string>>(k+1,vector<string>(100,"-1")));
//         ans=helper(0,num,k,dp);
//         int i=0;
//         while(ans[i]=='0') i++;
//         if(ans.size()==0 || i==ans.size()) return "0";
//         return ans.substr(i);;
//     }
};