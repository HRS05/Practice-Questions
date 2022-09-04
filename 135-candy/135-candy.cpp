class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int count=n;
        vector<int> l2r(n,1);
        vector<int> r2l(n,1);
        
        for(int i=1;i<n;i++)
        {
            if(ratings[i] > ratings[i-1])
            {
                l2r[i] = l2r[i-1] + 1;
            }
            if(ratings[n-i-1] > ratings[n-i])
            {
                r2l[n-i-1] = r2l[n-i] + 1;
            }
        }
        int sum=0;
        for(int i=0;i<n;i++) 
        {
            sum+=max(l2r[i],r2l[i]);
        }
        
        return sum;
    }
    
    
    /*
    //TLE solution
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int count=n;
        vector<int> ans(n,1);
        for(int i=1;i<n;i++)
        {
            if(ratings[i] < ratings[i-1] && ans[i] >= ans[i-1]){
                ans[i-1]+=ans[i]-ans[i-1]+1;
                if(i-2 >= 0){
                    int j=i-2;
                    while(j>=0){
                        if(ratings[j] > ratings[j+1] && ans[j] <= ans[j+1]) ans[j]+=ans[j+1]-ans[j]+1;
                        else break;
                        j--;
                    }
                }
            }
            if(ratings[i] > ratings[i-1] && ans[i] <= ans[i-1]){
                ans[i]+=ans[i-1]-ans[i]+1;
            }
        }
        int sum=0;
        for(int i=0;i<n;i++) {
            cout<<ans[i]<<"  ";
            sum+=ans[i];
        }
        
        return sum;
    }
    */
};