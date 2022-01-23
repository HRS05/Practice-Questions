class Solution {
public:
    
    bool isCorrect(vector<vector<char> > &board,int row,int column,char c)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][column]==c && i!=row) return false;
            if(board[row][i]==c && i!=column) return false;
            if(board[3 * (row/3) + i/3][3 * (column/3) + i%3] == c && (row!=3 * (row/3) + i/3  && column!=3 * (column/3) + i%3)) return false;
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]!='.')
                {
                    if(!isCorrect(board,i,j,board[i][j])) return false;
                }
            }
        }
        return true;
    }
};