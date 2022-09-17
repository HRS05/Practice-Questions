class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n=words.size();
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[words[i]]++;    
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(mp[words[i]] <= 0) continue;
            mp[words[i]]--;
            string s=words[i]; 
            reverse(s.begin(),s.end());
            if(mp.find(s) != mp.end() && mp[s]>0)
            {
                count+=4;
                mp[s]--;
            }
            else mp[words[i]]++;
        }
        for(auto x : mp)
        {
            if(x.second > 0 && x.first[0]==x.first[1]) {
                count+=2;
                break;
            }
        }
        return count;
    }
};