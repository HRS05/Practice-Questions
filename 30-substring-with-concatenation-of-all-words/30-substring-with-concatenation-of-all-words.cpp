class Solution {
public:
    
    bool check(map<string,int> wordsCount,string s,int wordLength)
    {
        int i;
        for(i=0;i<s.size();i+=wordLength)
        {
            string word=s.substr(i,wordLength);
            if(wordsCount.find(word)!=wordsCount.end())
            {
                if(--wordsCount[word] == -1){
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordLength=words[0].size();
        int wordsLength=words.size() * wordLength;
        map<string,int> wordsCount;
        vector<int> ans;
        for(int i=0;i<words.size();i++)
        {
            wordsCount[words[i]]++;
        }
        int i=0;
        while(i+wordsLength <= s.size())
        {
            if(check(wordsCount,s.substr(i,wordsLength),wordLength)){
                ans.push_back(i);   
            }
            i++;
        }
        return ans;
    }
};