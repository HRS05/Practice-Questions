class Solution {
public:
    
    bool isSafe(int row,int column,vector<string> board)
    {
        for(int i=column-1;i>=0;i--)
        {
            if(board[row][i]=='Q' && i!=column) return false;
        }
        int i,j;
        i=row; j=column;
        i=i+1; j=j-1;
        while(i<board.size() && j>=0)
        {
            if(board[i][j]=='Q') return false;
            i=i+1; j=j-1;
        }
        i=row; j=column;
        i=i-1; j=j-1;
        while(i>=0 && j>=0)
        {
            if(board[i][j]=='Q') return false;
            i=i-1; j=j-1;
        }
        
        return true;
    }
        
    void solve(vector<vector<string> > &boards,vector<string> &board,int column)
    {
        if(column==board.size())
        {
            boards.push_back(board);
            return;
        }
        for(int row=0;row<board.size();row++)
        {
            if(isSafe(row,column,board))
            {
                board[row][column]='Q';
                solve(boards,board,column+1);
                board[row][column]='.';
            }
        }
        
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > boards;
        vector<string> board;
        string file(n,'.');
        for(int i=0;i<n;i++)
        {
            board.push_back(file);
        }
        solve(boards,board,0);
        return boards;    
    }
};