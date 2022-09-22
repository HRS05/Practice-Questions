class Solution {
public:
    
    bool f(int index,int i,int j,vector<vector<char>  > &board,string word)
    {
        int n=board.size();
        int m=board[0].size();
        if(i<0 || i>=n || j<0 || j>=m) return false;
        
        if(board[i][j]==' ') return false;
        //if(v[i][j]!=-1) return false;

        if(word[index] != board[i][j]) return false;
        if(index==word.size()-1) return true;
        char c=board[i][j];
        board[i][j]=' ';
        if(f(index+1,i+1,j,board,word)) return true;
        if(f(index+1,i-1,j,board,word)) return true;
        if(f(index+1,i,j+1,board,word)) return true;
        if(f(index+1,i,j-1,board,word)) return true;
        board[i][j]=c;
        return false;
        
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(f(0,i,j,board,word)) return true;
                }
            }
        }
        return false;
    }
};