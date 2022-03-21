class Solution {
public:
    string reorderSpaces(string text) {
        int count=0;
        int wordCount=0;
        for(int i=0;i<text.size();i++)
        {
            if(text[i]==' ') count++;
            else
            {
                wordCount++;
                while(i<text.size() && text[i]!=' ') i++;
                i--;
            }
        }
        
        if(wordCount==1)
        {
            if(text[0]!=' ') return text;
            else
            {
                int i=0;
                string ans;
                while(i<text.size() && text[i]==' ') i++;
                while(i<text.size() && text[i]!=' ') 
                {
                    ans+=text[i];
                    i++;
                }
                for(int x=0;x<count;x++) ans+=" ";
                return ans;
            }
        }
        
        
        int extraSpace;
        extraSpace=count%(wordCount-1);
        int space=count/(wordCount-1);
        
        string ans="";
        int i=0;
        while(wordCount--)
        {
            
            while(i<text.size() && text[i]==' ') i++;
            while(i<text.size() && text[i]!=' ') 
            {
                ans+=text[i];
                i++;
            }
            if(wordCount)
            {
                for(int x=0;x<space;x++) ans+=" ";
            }
        }
        for(int x=0;x<extraSpace;x++) ans+=" ";
        
        return ans;
    }
};