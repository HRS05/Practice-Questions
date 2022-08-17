class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> v({".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."});
        set<string> s;
        for(string word : words)
        {
            string str="";
            for(char c : word)
            {
                str+=v[c-'a'];
            }
            s.insert(str);
        }
        return s.size();
    }
};