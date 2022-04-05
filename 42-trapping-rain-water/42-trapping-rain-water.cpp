class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int leftMax,rightMax;
        int water=0;
        leftMax=rightMax=water=0;
        int l=0;
        int r=n-1;
        while(l<r)
        {
            if(height[l]<=height[r])
            {
                if(height[l]>leftMax) leftMax=height[l];
                else water+=leftMax-height[l];
                l++;
            }
            else
            {
                if(height[r]>rightMax) rightMax=height[r];
                else water+=rightMax-height[r];
                r--;
            }
        }   
        return water;
    }
    
    
    
    /*
    //TC :O(n)
    //SC :O(n)
    int trap(vector<int>& height) {
        int n=height.size();
        long long water=0;
        long long max=0;
        vector<int> preSum(n);
        vector<int> sufSum(n);
        for(int i=0;i<n;i++)
        {
            if(max<height[i]) max=height[i];
            preSum[i]=max;
        }
        max=0;
        for(int i=n-1;i>=0;i--)
        {
            if(max<height[i]) max=height[i];
            sufSum[i]=max;
        }
        
        for(int i=1;i<n-1;i++)
        {
            water+=min(preSum[i],sufSum[i])-height[i];
        }
        
        return (int)water;
    }
    */
};