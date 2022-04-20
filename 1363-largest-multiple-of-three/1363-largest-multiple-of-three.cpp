class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        vector<int>vec(10,0);
        int a[]={1, 4, 7, 2, 5, 8},b[]={2, 5, 8, 1, 4, 7};
        int sum=0;
        
        for(auto it : digits){
            vec[it]++;
            sum+=it;
        }
        
        while(sum%3!=0){
            for(int i=0;i<6;i++){
                if(sum%3==1 and vec[a[i]]){
                    sum-=a[i];
                    vec[a[i]]--;
                    break;
                }
                else if(sum%3==2 and vec[b[i]]){
                    sum-=b[i];
                    vec[b[i]]--;
                    break;
                }
            }
        }
        
        string ans;
        
        for(int i=9; i>=0; i--) {
            for(int j=1; j<=vec[i]; j++)
                ans+=(to_string(i));
        }
        if(ans[0]=='0')
            return "0";
        
        return ans;
    }
};