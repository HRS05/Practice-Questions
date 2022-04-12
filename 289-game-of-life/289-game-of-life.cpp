class Solution {
public:
    int R, C;
    bool isLive(int status) {
        return status == 1;
    }
    int getLiveNeighborsCnt(int row, int col, vector<vector<int>>& board) {
        int cnt = 0;
        cnt += row - 1 >= 0 && board[row - 1][col] ? 1 : 0;
        cnt += row + 1 < R && board[row + 1][col] ? 1 : 0;
        cnt += col - 1 >= 0 && board[row][col - 1] ? 1 : 0;
        cnt += col + 1 < C && board[row][col + 1] ? 1 : 0;
        cnt += row - 1 >= 0 && col - 1 >= 0 && board[row - 1][col - 1] ? 1 : 0;
        cnt += row - 1 >= 0 && col + 1 < C && board[row - 1][col + 1] ? 1 : 0;
        cnt += row + 1 < R && col - 1 >= 0 && board[row + 1][col - 1] ? 1 : 0;
        cnt += row + 1 < R && col + 1 < C && board[row + 1][col + 1] ? 1 : 0;
        
        return cnt;
    }
    void gameOfLife(vector<vector<int>>& board) {
        R = board.size(), C = board[0].size();
		int liveNeighborsCnt;
		// store current board state
        vector<vector<int>> tempBoard = board;        
        for(int r = 0; r < R; r++) {
            for(int c = 0; c < C; c++) {
				// compute number of live neighbors
                liveNeighborsCnt = getLiveNeighborsCnt(r, c, tempBoard);
				// Apply conditions and update state of board
                if(isLive(board[r][c])) {
                    if(liveNeighborsCnt < 2 || liveNeighborsCnt > 3) board[r][c] = 0;
                } else {
                    board[r][c] = liveNeighborsCnt == 3 ? 1 : 0;
                }
            }
        }
    }
    
    
    /*
    int check(int i,int j,int n,int m,vector<vector<int> > &grid,vector<vector<int> > &dp)
    {
        int live=0,dead=0;
        
        for(int x=0;x<8;x++)
        {
            int a=i+dp[x][0];
            int b=j+dp[x][1];
            if(a>=0 && a<n && b>=0 && a<m)
            {
                if(grid[a][b]==0) dead++;
                else live++;
            }
        }
        if(grid[i][j]==1 && (live<2 || live>3)) return 0;
        else if(grid[i][j]==1) return 1;
           
        if(grid[i][j]==0 && live==3) return 1; 
        return 0;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int> >  grid=board;
        vector<vector<int> > dp(8);
        //{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1};
        
        dp[0][0]=-1; dp[0][1]=-1;
        dp[1][0]=-1; dp[1][1]=0;
        dp[2][0]=-1; dp[2][1]=1;
        dp[3][0]=0; dp[3][1]=1;
        dp[4][0]=1; dp[4][1]=1;
        dp[5][0]=1; dp[5][1]=0;
        dp[6][0]=1; dp[6][1]=-1;
        dp[7][0]=0; dp[7][1]=-1;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                board[i][j]=check(i,j,n,m,grid,dp);
            }
        }
       
    }*/
};