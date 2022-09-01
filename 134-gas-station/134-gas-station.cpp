class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int n=gas.size();
        int ansIndex=0;
        int sum=0;
        int sumTillNow=0;
        int i=0;
        while(i<n)
        {
            sumTillNow+=gas[i]-cost[i];
            sum+=gas[i]-cost[i];
            if(sum<0)
            {
                sum=0;
                ansIndex=i+1;
            }
            i++;
        }
        return sumTillNow<0 ? -1 : ansIndex;
    }
    
    
    
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int n=cost.size();
//         for(int i=0;i<n;i++)
//         {
//             int j=i;
//             int last=-1;
//             int currFuel=0;
            
//             while(j<n)
//             {
//                 if(last!=-1 && j==i) return i;
//                 currFuel+=gas[j];
//                 if(currFuel < cost[j]) break;
//                 currFuel-=cost[j];
//                 last=j;
//                 j++;
//                 if(j==n) j=j%n;
//             }
//         }
//         return -1;
//     }
};