class Solution {
public:
    //on and on solution
     string pushDominoes(string dominoes){
        int n = dominoes.size();
        vector<int> x(n, 0);
        int f = 0;
        for(int i = 0; i < n; i++){
            if(dominoes[i] == 'R') f = n;
            if(dominoes[i] == 'L') f = 0;
            x[i] = f;
            if(f > 0) f--;
        }
        f = 0;
        for(int i = n-1; i >= 0; i--){
            if(dominoes[i] == 'L') f = n;
            if(dominoes[i] == 'R') f = 0;
            x[i] -= f;
            if(f > 0) f--;
        }
        string ans;
        for(int &i: x){
            if(i == 0){
                ans += '.';
            }
            else if(i < 0){
                ans += 'L';
            }
            else{
                ans += 'R';
            }
        }
        return ans;
    }
    
    
    /*
    //on solution
    string pushDominoes(string dominoes) {
        int right=-1;
        int left=0;
        while(left < dominoes.size())
        {
            if(dominoes[left] == 'L')
            {
                if(right==-1 )
                {
                    for(int i=left-1;i>right;i--)
                    {
                        if(dominoes[i]!='.') break;
                        dominoes[i]='L';
                    }
                }
                else
                {
                    int a=right+1;
                    int b=left-1;
                    right=-1;
                    while(a<b)
                    {
                        // if we undo comment below code so, it will works
                        // if(dominoes[a]!='.')
                        // {
                        //     while(b>a){
                        //         if(dominoes[b]!='.') break;
                        //         dominoes[b]='L';
                        //         b--;
                        //     }
                        //     break;
                        // }
                        // if(dominoes[b]!='.')
                        // {
                        //     while(b>a){
                        //         if(dominoes[a]!='.') break;
                        //         dominoes[a]='R';
                        //         a++;
                        //     }
                        //     break;
                        // }
                        dominoes[a]='R'; 
                        dominoes[b]='L'; 
                        b--; a++;
                    }
                }
            }
            else if(dominoes[left] == 'R')
            {
                if(right!=-1)
                {
                    for(int i=right+1;i<left;i++) dominoes[i]='R';
                }
                right=left;
            }
            left++;
        }
        if(right!=-1)
        {
            for(int i=right+1;i<dominoes.size();i++) dominoes[i]='R';
        }
        return dominoes;
    }
    */
};