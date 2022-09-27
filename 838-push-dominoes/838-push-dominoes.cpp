class Solution {
public:
    string pushDominoes(string dominoes) {
        int right=-1;
        int left=0;
        while(left < dominoes.size())
        {

            if(dominoes[left] == 'L')
            {
                                                                                               // cout<<right<<endl;

                if(right==-1 )
                {
                    cout<<left<<endl;
                    //for(int i=right+1;i<left;i++)
                    for(int i=left-1;i>right;i--)
                    {
                        if(dominoes[i]!='.') break;
                        dominoes[i]='L';
                    }
                }
                else
                {
                                                                    cout<<left<<endl;

                    int a=right+1;
                    int b=left-1;
                    right=-1;
                    while(a<b)
                    {
                        if(dominoes[a]!='.')
                        {
                            while(b>a){
                                if(dominoes[b]!='.') break;
                                dominoes[b]='L';
                                b--;
                            }
                            break;
                        }
                        if(dominoes[b]!='.')
                        {
                            while(b>a){
                                if(dominoes[a]!='.') break;
                                dominoes[a]='R';
                                a++;
                            }
                            break;
                        }
                        dominoes[a]='R'; right=a;
                        dominoes[b]='L'; 
                        b--; a++;
                        right=-1;
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
};