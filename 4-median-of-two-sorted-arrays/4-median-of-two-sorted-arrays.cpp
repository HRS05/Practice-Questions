class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i1,i2,i3;
        i1=0;i2=0;
        double median;
        vector<int> v;
        while(i1<nums1.size() && i2<nums2.size())
        {
            if(nums1[i1] < nums2[i2]) 
            {    
                v.push_back(nums1[i1]);
                i1++;
            }
            else
            {
                v.push_back(nums2[i2]);
                i2++;
            }
        }
        while(i1 < nums1.size())
        {
            v.push_back(nums1[i1]);
            i1++;
        }
        while(i2 < nums2.size())
        {
            v.push_back(nums2[i2]);
            i2++;
        }
        
        
        
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        
        
        
        
        
        
        if(v.size()==1)
        {
            median=v[0];
        }
        else if(v.size() % 2==0)
        {
            double a,b;
            a=v[(v.size()-1)/2];
            b=v[(v.size()+1)/2];
            median=(a+b)/2;
        }
        else
        {
            median=v[(v.size())/2];
        }
        return median;
    }
};