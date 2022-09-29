class Solution {
public:
    
    int getSum(int a, int b) {
        /*
            a=9
            b=11
            a(9) ->      1001
            b(11) ->     1011
            a^b -->      0010
            (a&b)<<1--> 10010 
            ans = getSum(a^b , ((a&b)<<1))
        
        */
        if (b==0) return a;
        int sum = a ^ b;
        int cr = (unsigned int) (a & b) << 1;
        return getSum(sum, cr);
        
        
    }
    
    
    // int getSum(int a, int b) 
    // {
    //     if(b>0)
    //     {
    //          while(b>0)
    //         {
    //             a++;
    //             b--;
    //         }  
    //     }
    //     else
    //     {
    //         while(b<0)
    //         {
    //             a--;
    //             b++;
    //         }
    //     }
    // return a;
    // }
};