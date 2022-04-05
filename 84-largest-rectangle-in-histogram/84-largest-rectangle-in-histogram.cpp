class Solution {
public:
    
    int largestRectangleArea(vector<int>& height) {
        int n=height.size();
        vector<int> leftSmall(n,0);
        vector<int> rightSmall(n,0);
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && height[i]<=height[st.top()])
            {
                st.pop();
            }
            if(st.empty()) leftSmall[i]=0;
            else leftSmall[i]=st.top()+1;
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && height[i]<=height[st.top()])
            {
                st.pop();
            }
            if(st.empty()) rightSmall[i]=n-1;
            else rightSmall[i]=st.top()-1;
            st.push(i);
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,(height[i]*(rightSmall[i]-leftSmall[i]+1)));
        }
        return ans;
    }
    
    
    /*
    //brute force TLE solution
    //TC : O(n^2)
    int getLeftLastHightCount(int index,vector<int> &height)
    {
        int i=index-1;
        int count=0;
        while(i>=0 && height[i]>=height[index])
        {
            i--;
            count++;
        }
        return count;
    }
    
    int getRightLastHightCount(int index,vector<int> &height)
    {
        int i=index+1;
        int count=0;
        while(i<height.size() && height[i]>=height[index])
        {
            i++;
            count++;
        }
        return count;
    }
    
    int largestRectangleArea(vector<int>& height) {
        int ans=0;
        int n=height.size();
        for(int i=0;i<n;i++)
        {
            int l=getLeftLastHightCount(i,height);
            int r=getRightLastHightCount(i,height);
            int area=(l+r+1)*height[i];
            ans=max(ans,area);
        }
        return ans;
    }
    */
};