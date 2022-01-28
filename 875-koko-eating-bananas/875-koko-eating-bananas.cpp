class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        
        // using nimary search method
        int left=1;
        int right=*max_element(piles.begin(),piles.end());
        
        while(left<right)
        {
            int middle=(left+right)/2;
            int hourSpent=0;
            for(int i=0;i<piles.size();i++)
            {
                int num;
                if(piles[i]%middle==0) num=piles[i]/middle;
                else num=piles[i]/middle + 1 ;
                hourSpent+=num;
            }
            if(hourSpent<=h)
            {
                right=middle;
            }
            else
            {
                left=middle+1;
            }
        }
        return right;
        
        /*
        //this is brute force solution 
        // T : O(mn)
        int speed=1;
        while(1)
        {
            int hourSpent=0;
            for(int i=0;i<piles.size();i++)
            {
                //cout<<"hey"<<(piles[i]%speed!=0)<<endl;
                int num;
                if(piles[i]%speed==0) num=piles[i]/speed;
                else num=piles[i]/speed+1;
                    
                hourSpent=hourSpent+num;
                if(hourSpent > h)
                {
                    break;
                }
            }
            if(hourSpent <= h)
            {
                return speed;
            }
            else
            {
                speed=speed+1;
            }
        }
        */ 
    }
};