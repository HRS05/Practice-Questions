class Solution {
public:

    pair<int, int> countOneAndZero(string s)
    {
        int one = 0, zero = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '1')  one++;
            else zero++;
        }
        return {one, zero};
    }
    
    int solve(int i, int one, int zero, int& maxZero, int& maxOne, 
             vector<string>& arr,vector<vector<vector<int> > > &dp)
    {
        if(i >= arr.size()) return 0;
        if(one > maxOne || zero > maxZero) return 0;
        if(dp[i][zero][one]!=-1)
        {
            return dp[i][zero][one];
        }
        pair<int, int> p = countOneAndZero(arr[i]);
        
        int ans1 = 0, ans2 = 0, ansWithout = 0;
        
        if(one + p.first <= maxOne && zero + p.second <= maxZero)
        {
            ans1 = 1 + solve(i + 1, one + p.first, zero + p.second, 
                           maxZero, maxOne, arr,dp);
            ans2 = solve(i + 1, one, zero, maxZero, maxOne, arr,dp);
        }
        else 
        {
            ansWithout = solve(i + 1, one, zero, maxZero, maxOne, arr,dp);
        }
        
        return dp[i][zero][one]=max({ans1, ans2, ansWithout});
        
        
    }
    int findMaxForm(vector<string>& arr, int m, int n) {
        int maxZero = m; 
        int maxOne = n;
        vector<vector<vector<int> > > dp(arr.size()+1,vector<vector<int> >(m+1,vector<int>(n+1,-1)));
        return solve(0, 0, 0, maxZero, maxOne, arr,dp);
    }
};

/*class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        for(auto& s : strs) { 
            
            int zeros = count(s.begin(), s.end(), '0');
            int ones = s.size();
            
            for(int i = m; i >= zeros; i--) 
                for(int j = n; j >= (ones - zeros); j--) 
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones + zeros]);
        }
        
        return dp[m][n];
    }
};
*/