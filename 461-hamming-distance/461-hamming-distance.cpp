class Solution {
public:
    int hammingDistance(int x, int y) {
        int count=0;
        for(int i=0;i<32;i++)
        {
            //cout<< (x&1) <<"  "<<( y&1) <<endl;
            if((x&1)==1 && (y&1)==0) count++;
            else if((x&1)==0 && (y&1)==1) count++;
            x>>=1;
            y>>=1;
        }
        return count;
    }
};