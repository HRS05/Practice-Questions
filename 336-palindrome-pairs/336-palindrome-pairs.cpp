class Solution {
public:
    bool pal(string &s,map<string,bool> &checkPal)
    {
        if(checkPal.find(s) != checkPal.end()) return checkPal[s];
        if(s.size()==0) return checkPal[s]=true;
        int i=0;int j=s.size()-1;
        while(i<j)
        {
            if(s[i] != s[j]) return checkPal[s]=false;
            i++;
            j--;
        }
        return checkPal[s]=true;
    }
    
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int> > ans;
        unordered_map<string,int> mp;
        map<string,bool> checkPal;
        for(int i=0;i<words.size();i++)
        {
            string s=words[i];
            reverse(s.begin(),s.end());
            mp[s]=i;
        }
        
        if(mp.find("") != mp.end())
        {
            for(int i=0;i<words.size();i++)
            {
                if(words[i] == "") continue;
                if(pal(words[i],checkPal)) ans.push_back({i,mp[""]});
            }
        }
        
        for(int i=0;i<words.size();i++)
        {
            string r=words[i];
            string l="";
            
            for(int j=0;j<words[i].size();j++)
            {
                l+=words[i][j];
                r.erase(0,1);
                if(mp.find(l) != mp.end() && pal(r,checkPal) && mp[l] != i) ans.push_back({i,mp[l]});
                if(mp.find(r) != mp.end() && pal(l,checkPal) && mp[r] != i) ans.push_back({mp[r],i});
            }
        }
        
        return ans;
    }
};