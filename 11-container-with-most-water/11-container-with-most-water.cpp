class Solution {
public:
    
    int maxArea(vector<int>& height) {
        int n=height.size();
        int ans=0;
        int l=0;
        int r=n-1;
        while(l<r)
        {
            if(height[l]<=height[r])
            {
                int x=(r-l);
                int y=height[l];
                ans=max(ans,(x*y));
                l++;
            }
            else
            {
                int x=(r-l);
                int y=height[r];
                ans=max(ans,(x*y));
                r--;
            }
        }
        return ans;
    }
    
    
    /*
    //TLE solution
    //TC : O(n^2)
    //SC : O(1)
    int maxArea(vector<int>& height) {
        int n=height.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int x=(j-i);
                int y=min(height[i],height[j]);
                ans=max(ans,(x*y));
            }
        }
        return ans;
    }
    */
};