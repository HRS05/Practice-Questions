class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_map<int,vector<string> > mp;
        long long int num=1;
        for(int i=1;i<32;i++)
        {
            string s=to_string(num);
            sort(s.begin(),s.end());
            mp[s.size()].push_back(s);
            num=num*2;
        }
        string a=to_string(n);
        sort(a.begin(),a.end());
        for(string x : mp[a.size()]){
            if(x==a) return true;
        }
        return false;
    }
};