class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
            sum+=nums[i];
        }
        while(k)
        {
            int val=pq.top();
            if(val==0){
                k--;
                continue;
            }
            pq.pop();
            val*=-1;
            sum+=(2*val);
            k--;
            pq.push(val);
        }
        return sum;
        
    }
    
    
//     int largestSumAfterKNegations(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());
//         int sum=0;
//         for(int i=0;i<nums.size();i++)
//         {
//             if(k>0 && nums[i]<0){
//                 nums[i]*=-1;
//                 k--;
//             }
//             sum+=nums[i];
//         }
//         if(k==0 || k%2==0) return sum;
//         sort(nums.begin(),nums.end());
       
//         return sum-(2*nums[0]);
//     }
};