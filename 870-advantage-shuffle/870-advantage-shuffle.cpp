class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> ms(nums1.begin(),nums1.end());
        vector<int> ans;
        for(int i=0;i<nums1.size();i++)
        {
            auto p=ms.upper_bound(nums2[i]);
            if(p==ms.end()) p=ms.begin();
            ans.push_back(*p);
            ms.erase(p);
        }
        return ans;
    } 
    
    
//      vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
//          vector<int> ans;
//          sort(nums1.begin(),nums1.end());
//          for(int i=0;i<nums2.size();i++)
//          {
//              auto it= nums1.back() > nums2[i] ? upper_bound(nums1.begin(),nums1.end(),nums2[i]) : nums1.begin();
//              ans.push_back(*it);
//              nums1.erase(it);
//          }
//          return ans;
//      }

    
    
//     vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
//         int n=nums1.size();
//         vector<int> a=nums2;
//         vector<int> ans(n,-1);
//         sort(a.begin(),a.end());
//         sort(nums1.begin(),nums1.end());
//         vector<int> helper;
//         unordered_map<int,vector<int> > mp;
//         for(int i=0;i<n;i++) mp[nums2[i]].push_back(i);
//         int i=0;
//         int j=0;
        
//         while(i<n && j<n)
//         {
//             if(nums1[i] > a[j]){
//                 for(int x=0;x<mp[a[j]].size();x++){
//                     if(mp[a[j]][x]!=-1){
//                         ans[mp[a[j]][x]]=nums1[i];
//                         mp[a[j]][x]=-1;
//                     }
//                 }
                
                
                
//                 //ans[mp[a[j]]]=nums1[i];
//                 i++;
//                 j++;
//             }
//             else{
//                 helper.push_back(nums1[i]);
//                 i++;
//             }
//         }
//         j=0;
//         if(helper.size()){
//         for(i=0;i<n;i++)
//         {
//             if(ans[i]==-1){
//                 ans[i]=helper[j];
//                 j++;
//             }
//         }
//     }
        
        
//         return ans;
//     }
};