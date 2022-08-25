class Solution {
public:
     bool checkValidString(string s) {
        stack<int> countStack;
        stack<int> astStack;
         for(int i=0;i<s.size();i++)
         {
             if(s[i]=='(') countStack.push(i);
             else if(s[i]=='*') astStack.push(i);
             else if(s[i]==')'){
                 if(!countStack.empty()){
                     countStack.pop();
                 }
                 else if(!astStack.empty()){
                     astStack.pop();
                 }
                 else return false;
             }
         }
         
         while(!countStack.empty() && !astStack.empty()){
             if(countStack.top() > astStack.top()) return false;
             
             countStack.pop();
             astStack.pop();
         }
         
         return countStack.empty();
         
     }
    
    
    
//     bool helper(int index,string s,map<pair<int,string>,bool> &mp)
//     {
//         if(index>=s.size()) return validate(s);
//         if(mp.find({index,s})!=mp.end()) return mp[{index,s}];
//         if(s[index]=='*'){
//             s[index]=')'; 
//             if(helper(index+1,s,mp)) return mp[{index,s}]=true;
//             s[index]='('; 
//             if(helper(index+1,s,mp)) return mp[{index,s}]=true;
//             string g=s.substr(0,index);
//             g+=s.substr(index+1);
//             return mp[{index,s}]=helper(index,g,mp) ? true : false;
//         }
//         return mp[{index,s}]=helper(index+1,s,mp);
//     }
    
    
//     bool checkValidString(string s) {
//         map<pair<int,string>,bool> mp;
//         return helper(0,s,mp);
//     }
//     bool validate(string s)
//     {
//         int sum=0;
//         for(int i=0;i<s.size();i++)
//         {
//             if(s[i]=='(') sum++;
//             else sum--;
//             if(sum<0) return false;
//         }
//         return sum==0;
//     }
 };