class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num=0;
        for(int i=0;i<32;i++)
        {
            int count=0;
            for(int j=0;j<nums.size();j++)
            {
                int x = (nums[j] >> i) & 1;
                if(x==1) count++;
            }
            if(count%3==1)
            {
                num = num | (1 << i) ; 
            }
        }
        return num;
    }
};