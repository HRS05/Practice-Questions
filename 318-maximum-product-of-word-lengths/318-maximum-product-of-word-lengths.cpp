class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<map<char,int> > v(words.size());
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                v[i][words[i][j]]++;
            }
        }
        long long int ans=0;
        for(int i=0;i<words.size();i++)
        {
            long long int count=0;
            for(int j=i+1;j<words.size();j++)
            {
                bool check=true;
                for(auto it : v[i])
                {
                    if(v[j].find(it.first)!=v[j].end()) {
                        check=false;
                        break;
                    }
                }
                if(check) {
                    count=words[i].size() * words[j].size();
                    ans=max(ans,count);
                }
            }
        }
        
        return ans;
    }
};