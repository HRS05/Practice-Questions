class Solution {
public:
    
    
    //intution
    //if xor from i to k is 0 ,so we can put j any where in between them !!!!
    
    int countTriplets(vector<int>& arr) {
        
        int count=0;
        for(int i=0;i<arr.size()-1;i++)
        {
            int k=i+1;
            int xxor=arr[i];
            int found=0;
            while(k<arr.size())
            {
                xxor ^= arr[k];
                if(xxor==0) count+=(k-i);
                k++;
            }
            
           
        }
            
        return count;
    }
};