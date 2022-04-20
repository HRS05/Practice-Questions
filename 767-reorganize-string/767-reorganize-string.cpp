class comp{
      public:
          bool operator()(pair<char, int> p1, pair<char, int> p2){
              return p1.second < p2.second;
          }  
    };


class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        string ans="";
        priority_queue< pair<char,int>, vector<pair<char,int> >, comp> pq;
        
        for(int i=0;i<s.size();i++) mp[s[i]]++;
        
        for(auto it : mp) pq.push({it.first,it.second});
        
        if(pq.top().second > (s.size()/2) +1 ) return "";
        
        while(!pq.empty())
        {
            if(pq.size()==1 && pq.top().second>1) return ""; 
            auto it=pq.top(); pq.pop();
            ans+=it.first;
            
            if(!pq.empty()){
            auto it1=pq.top(); pq.pop();
            ans+=it1.first;
            if(it.second > 1)pq.push({it.first,it.second-1});
            if(it1.second > 1)pq.push({it1.first,it1.second-1});
            }
            
            
            
        }
            
        return ans;
    }
};


