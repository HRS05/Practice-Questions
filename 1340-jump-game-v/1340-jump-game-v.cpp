
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        int res = 0;
        vector<int> dp(n,-1);
        function<int (int)> solve;
        solve = [&] (int index) -> int {
            if(index >= n) return 0;
            if(dp[index] != -1) return dp[index];
            int ans = 0;
            for(int i=index+1; i<=min(n-1,index+d) && (arr[i] < arr[index]);i++){
                 ans = max(ans,solve(i));
            }
            for(int i=index-1; i>=max(0,index-d) && (arr[i] < arr[index]);i--){
                 ans = max(ans,solve(i));
            }
            ans++;
            return dp[index] = ans;
        };

        for(int i=0;i<n;i++){
            res = max(res,solve(i));
        }
        return res;
    }
};