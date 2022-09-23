class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==1){
            return vector<int>({0,1});
        }
        vector<int> support=grayCode(n-1);
        vector<int> ans(support.begin(),support.end());
        int x=0;
        int y=1;
        y=y<<(n-1);
        //cout<<y<<endl;
        for(int i=support.size()-1;i>=0;i--)
        {
            ans.push_back(y+support[i]);
        }
        return ans;
    }
};