class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int,int>> stk; // int pair, they are previous and Minimum respectively
        int Min = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            // find the minimum value in this array
            if(!stk.empty()){
                Min = min(Min, stk.top().first); 
                cout << Min << endl;
            }
            // we need to maintain the largest one value at the stack
            while(!stk.empty() && nums[i] > stk.top().first) stk.pop(); 
            
            // if the current integer is smaller than the previous num and larger than the Min
            if(!stk.empty() && nums[i] < stk.top().first && nums[i] > stk.top().second){
                return true;
            }
            // for each time, just push back the number and the minimum to the stack.
            stk.push({nums[i], Min});
        }
        return false;
    }
};