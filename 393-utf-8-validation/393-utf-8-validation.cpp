class Solution {
public:
    bool validUtf8(vector<int>& data) 
    {
        int n=data.size();
        for(int i=0;i<n;i++)
        {
            if((data[i]>>7) == 0) 
            {
                continue;
            }
            else if((data[i]>>5) == 6)
            {
                int j=i+1;
                while(j<=i+1 && j<n)
                {
                    if((data[j]>>6) != 2) return false;
                    j++;
                }
                if(j!=i+2) return false;
                i=j-1;
            }
            else if((data[i]>>4) == 14)
            {
                int j=i+1;
                while(j<=i+2 && j<n)
                {
                    if((data[j]>>6) != 2) return false;
                    j++;
                }
                if(j!=i+3) return false;
                i=j-1;
            }
            else if((data[i]>>3) == 30)
            {
                int j=i+1;
                while(j<=i+3 && j<n)
                {
                    if((data[j]>>6) != 2) return false;
                    j++;
                }
                if(j!=i+4) return false;
                i=j-1;
            }
            else
            {
                 return false;
            }
        }
        return true;
    }
};