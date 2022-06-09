class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int ub,lb,sum;
       int size=numbers.size();
       lb=0;
       ub=size-1;
          while(lb<ub)
          {
             sum=numbers[lb]+numbers[ub];
              if(sum==target) break;
              else if(sum>target) ub--;
              else lb++;
          }
        vector<int> v;
        v.push_back(lb+1);
        v.push_back(ub+1);
        return v;
    }
};