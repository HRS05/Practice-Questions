class Solution {
public:
    void fetchUpdatedData(vector<vector<char> > &board,vector<vector<char> > &helperBoard,int r,int c)
    {
        int n=board.size();
        int m=board[0].size();
        
        
        if(r<0 || r>=n || c<0 || c>=m || board[r][c]=='X' || helperBoard[r][c]=='O') return ;
        helperBoard[r][c]='O';
        
        fetchUpdatedData(board,helperBoard,r+1,c);
        fetchUpdatedData(board,helperBoard,r-1,c);
        fetchUpdatedData(board,helperBoard,r,c+1);
        fetchUpdatedData(board,helperBoard,r,c-1);
        
    }
    
    
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<char> > helperBoard(n,vector<char>(m,'X'));
        
        for(int i=0;i<n;i++) if(board[i][0]=='O' && helperBoard[i][0]=='X') fetchUpdatedData(board,helperBoard,i,0);
        for(int i=0;i<n;i++) if(board[i][m-1]=='O' && helperBoard[i][m-1]=='X') fetchUpdatedData(board,helperBoard,i,m-1);
        for(int i=0;i<m;i++) if(board[0][i]=='O' && helperBoard[0][i]=='X') fetchUpdatedData(board,helperBoard,0,i);
        for(int i=0;i<m;i++) if(board[n-1][i]=='O' && helperBoard[n-1][i]=='X') fetchUpdatedData(board,helperBoard,n-1,i);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && helperBoard[i][j]=='X') board[i][j]='X';
                //cout<<helperBoard[i][j]<<" ";
            }  
            //cout<<endl;
        }
        
    }
};