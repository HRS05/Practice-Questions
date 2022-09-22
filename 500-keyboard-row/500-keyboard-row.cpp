class Solution {
public:
    
    
    
    vector<string> findWords(vector<string>& words) {
        string s1="qwertyuiop";
        string s2="asdfghjkl";
        string s3="zxcvbnm";
       
        vector<string> ans;
        char last;
        for(string word : words)
        { 
            string w=word;
            int n=word.size();
            if(n==1) {
                ans.push_back(word);
                continue;
            }
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            if(s1.find(word[0])!=string::npos) {
                last=s1[0];
            }
            else if(s2.find(word[0])!=string::npos) last=s2[0];
            else if(s3.find(word[0])!=string::npos) last=s3[0];
                           
            
            
            for(int i=1;i<n;i++)
            {
                if(last=='q')
                {
                    if(s1.find(word[i]) == string::npos) break;
                    if(i==n-1) ans.push_back(w);
                }
                else if(last=='a')
                {
                    if(s2.find(word[i]) == string::npos) break;
                    if(i==n-1) ans.push_back(w);
                }
                else if(last=='z')
                {
                    if(s3.find(word[i]) == string::npos) break;
                    if(i==n-1) ans.push_back(w);
                }
 
            }
            
        }
        
        return ans;
    }
};