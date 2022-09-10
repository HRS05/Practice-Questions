class Solution {
public:
    
    int longestMountain(vector<int>& arr) 
    {
        int N = arr.size();
        int ans = 0, base = 0;
        while (base < N) {
            int end = base;
            //below condition is cheking for increasing slop of mountain
            if (end + 1 < N && arr[end] < arr[end + 1]) 
            {
                //now after checking that slop is increasing so,
                //now we are going to peak of mountain
                while (end + 1 < N && arr[end] < arr[end + 1]) 
                    end++;

                //now after reaching peak of mountain
                //below condition is for checking downward slop of mountain
                if (end + 1 < N && arr[end] > arr[end + 1]) 
                {
                    //now we have to reach at the bottom of that slop
                    while (end + 1 < N && arr[end] > arr[end + 1]) 
                        end++;
                    
                    //now putting updating ans 
                    //because now we have covered whole mountain 
                    //so we have to check is it larget or not
                    ans = max(ans, end - base + 1);
                }
            }

            base = max(end, base + 1);
        }

        return ans;
    }
    
    /*
    int longestMountain(vector<int>& arr) 
    {
        int n=arr.size();
        vector<int> dp1(n,1);
        vector<int> dp2(n,1);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(arr[prev] < arr[i] && 1 + dp1[prev] > dp1[i])
                {
                    dp1[i]=1+dp1[prev];
                }
            }
        }
        
        for(int i=n-1;i>=0;i--)
        {
            for(int prev=n-1;prev>i;prev--)
            {
                if(arr[prev] < arr[i] && 1 + dp2[prev] > dp2[i])
                {
                    dp2[i]=1+dp2[prev];
                }
            }
            if(dp1[i]!=1 && dp2[i]!=1){
                ans=max(ans,dp1[i]+dp2[i]-1);
            }
        }
        
        return ans;
    }
    */
};