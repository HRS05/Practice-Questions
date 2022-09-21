class Solution {
public:
    int minFlips(string target) {
        int count=0;
        int n=target.size();
        int i=n-1;
        while(i>=0 && target[i] == '1') i--;
        if(i!=n-1) count++;
        if(i==-1) return count;
        while(i>=0)
        {
            if(target[i]=='1') count+=2;
            while(i>=0 && target[i] == '1') i--;
            i--;
        }
        return count;
    }
};