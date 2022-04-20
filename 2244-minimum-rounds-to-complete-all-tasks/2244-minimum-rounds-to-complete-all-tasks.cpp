class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> mp;
        for(int num : tasks) mp[num]++;
        int ans=0;
        for(auto x : mp)
        {
            if(x.second==1) return -1;
            else if(x.second%3==0) ans+=x.second/3;
            else if(x.second%3==1) ans+=(x.second/3)-1+2;
            else if(x.second%3==2) ans+=(x.second/3)+1;
        }
        return ans;
    }
};