class Solution {
public:
     int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
       int ans = 0;
        priority_queue<int> pq;
        
        for(auto s: stations) {
            
            while(startFuel < s[0] && pq.size()) {
                startFuel += pq.top();
                pq.pop();
                ans++;
            }      
            
            if(startFuel < s[0]) return -1;
            
            pq.push(s[1]);
        }
        
        while(startFuel < target && pq.size()) {
            startFuel += pq.top();
            pq.pop();
            ans++;
        }
        
        if(startFuel < target) return -1;
        
        return ans;
    }
    
    
    
//     int helper(long long int curr,long long int target,long long int startFuel,int lastVisitIndex,vector<vector<int> > &stations)
//     {
//         if(target<=curr+startFuel) {
//             return 0;
//         }
//         int ans=501;
//         int i= lastVisitIndex==-1 ? 0 : lastVisitIndex+1;
//         for(;i<stations.size();i++){
//             if(curr+startFuel>=stations[i][0]){
//                 long long int fuelLeft=startFuel-stations[i][0];
//                 int val=helper(curr+stations[i][0],target,fuelLeft+stations[i][1],i,stations);
//                 if(val!=-1)ans=min(ans,1+(int)val);
//             }
//         }
//         return ans>=501 ? -1 : ans;
//     }
    
    
//     int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
//         sort(stations.begin(),stations.end());
//         return helper(0,target,startFuel,-1,stations);
//     }
};