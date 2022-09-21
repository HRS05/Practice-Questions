class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum=0;
        int n=queries.size();
        for(int num  : nums)
        {
            if(num%2 == 0) sum+=num;
        } 
        vector<int> ans;
        for(vector<int> v : queries)
        {
            if(nums[v[1]] % 2 == 0)
            {
                int x=nums[v[1]];
                x=nums[v[1]] + v[0];
                if(x % 2 ==0){
                    sum-=nums[v[1]];
                    nums[v[1]]=x;
                    sum+=nums[v[1]];
                }
                else{
                    sum-=nums[v[1]];
                    nums[v[1]]=x;
                }
            }
            else
            {
                int x=nums[v[1]];
                x=nums[v[1]] + v[0];
                if(x % 2 ==0){
                    //sum-=nums[v[1]];
                    nums[v[1]]=x;
                    sum+=nums[v[1]];
                }
                else{
                    //sum-=nums[v[1]];
                    nums[v[1]]=x;
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};