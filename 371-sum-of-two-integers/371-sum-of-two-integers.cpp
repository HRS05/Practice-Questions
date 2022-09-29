class Solution {
public:
    
        
    int getSum(int a, int b) 
    {
        int c=0;
        int sum=0;
        for(int i=0;i<32;i++){
            int x=(a>>i)&1;
            int y=(b>>i)&1;
            sum+=((x^y^c)<<i);
            c=((x&y)|(c&y)|(c&x));
            
        }
        return sum;  
    }
    
    /*
    int getSum(int a, int b) 
    {
        if(b>0)
        {
             while(b>0)
            {
                a++;
                b--;
            }  
        }
        else
        {
            while(b<0)
            {
                a--;
                b++;
            }
        }
    return a;
    }
    */
};