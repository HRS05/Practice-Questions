class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int n=s.size();
        int a=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i] < s[j]){
                    if(a!=-1){
                        if(s[a] <= s[j]) a=j;
                    }
                    else a=j;
                }
            }
            if(a != -1){
                swap(s[i],s[a]);
                    return stoi(s);
            }
        }
        return num;
    }
};