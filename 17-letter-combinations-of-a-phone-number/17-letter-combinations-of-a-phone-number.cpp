class Solution {
public:
    void solve(string digits,vector<string> &ans,map<char,string> &data,string res,int index)
    {
        if(index==digits.size())
        {
            ans.push_back(res);
            return ;
        }
        string s=data[digits[index]];
        for(int i=0;i<s.size();i++)
        {
           solve(digits,ans,data,res+s[i],index+1);
        }
        return;
    }
    
    
    vector<string> letterCombinations(string digits) {
        map<char,string> data;
        data.insert({'2',"abc"});
        data.insert({'3',"def"});
        data.insert({'4',"ghi"});
        data.insert({'5',"jkl"});
        data.insert({'6',"mno"});
        data.insert({'7',"pqrs"});
        data.insert({'8',"tuv"});
        data.insert({'9',"wxyz"});
        vector<string> ans;
        if(digits.size()==0) return ans;
        solve(digits,ans,data,"",0);
        return ans;
    }
};