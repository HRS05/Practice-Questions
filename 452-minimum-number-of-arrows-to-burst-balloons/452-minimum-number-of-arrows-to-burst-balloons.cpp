class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end());
        vector<int> prev=points[0];
        int ans=n;
        for(int i=1;i<n;i++)
        {
            if(points[i][0]<=prev[1])
            {
                prev[1]=min(prev[1],points[i][1]);
                ans--;
            }
            else
            {
                prev=points[i];
            }
        }
        return ans;
    }
};