class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> v=arr;
        sort(v.begin(),v.end());
        int ans=0;
        long long int s1,s2;
        s1=s2=0;
        for(int i=0;i<arr.size();i++)
        {
            s1+=arr[i];
            s2+=v[i];
            if(s1==s2) ans++;
        }
        return ans;
    }
};