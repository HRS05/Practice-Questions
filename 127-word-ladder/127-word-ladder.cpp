class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s;
        bool checkForEndWord=false;
        for(int i=0;i<wordList.size();i++)
        {
            if(endWord.compare(wordList[i])==0){
                checkForEndWord=true;
            }
            s.insert(wordList[i]);
        }
        
        if(!checkForEndWord) return 0;
        queue<string> q;
        q.push(beginWord);
        int ans=0;
        while(!q.empty())
        {
            ans++;
            int size=q.size();
            while(size--)
            {
                string ss=q.front(); q.pop();
                for(int i=0;i<ss.size();i++)
                {
                    string str=ss;
                    for(char c='a';c<='z';c++)
                    {
                        str[i]=c;
                        if(ss.compare(str)==0){
                            continue;
                        }
                        if(endWord.compare(str)==0){
                            return ans+1;
                        }
                        if(s.find(str)!=s.end()){
                            q.push(str);
                            s.erase(str);
                        }
                    }
                }
            }
        }
        return 0;
    }
};