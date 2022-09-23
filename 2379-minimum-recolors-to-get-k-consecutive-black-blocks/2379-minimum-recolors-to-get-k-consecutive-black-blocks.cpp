class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count=0;
        int maxi=0;
        for(int i=0;i<k;i++) if(blocks[i]=='B') count++;
        maxi=count;
        for(int i=k;i<blocks.size();i++)
        {
            if(blocks[i-k]=='B') count--;
            if(blocks[i]=='B') count++;
            maxi=max(maxi,count);
        }
        
        //if(maxi>k) return 0;
        return k-maxi;
    }
};