class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int> mp;
        int ans=0;
        for(int num : answers)
        {
            mp[num]++;
        }
        for(pair<int,int> p : mp)
        {
            int num=p.first;
            int feq=p.second;
            if(num+1 >= feq) ans+=num+1;
            else{
                int x=feq / (num+1);
                if(feq % (num+1) !=0) x++;
                ans+= (x*(num+1));
            }
        }
        
        return ans;
    }
};