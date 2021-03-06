class NumMatrix {

private:
    vector<vector<int> > matrix;
public:
    NumMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        matrix=vector<vector<int> >(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                matrix[i][j]=matrix[i-1][j]+matrix[i][j-1]-matrix[i-1][j-1]+mat[i-1][j-1];
            }
        }
        
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; col1++; row2++; col2++; 
        return matrix[row2][col2] - matrix[row2][col1 - 1] - matrix[row1 - 1][col2] + matrix[row1 - 1][col1 - 1];
    }
    
    
/*    
// sc: O(m*n)
// TC : O(r2-r1)
private:
    vector<vector<int> > matrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        vector<vector<int> > dp(matrix.size(),vector<int>(matrix[0].size(),0));
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(j==0) dp[i][j]=matrix[i][j];
                else dp[i][j]=dp[i][j-1]+matrix[i][j];
            }
        }
        this->matrix=dp;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=0;
        
        for(int i=row1;i<=row2;i++)
        {
            if(col1!=0) ans+=this->matrix[i][col2]-this->matrix[i][col1-1];
            else ans+=this->matrix[i][col2];
        }
        return ans;
    }
     */   

    /*
    // TLE solution
    
private:
    vector<vector<int> > matrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++)
        {
            vector<int> v;
            for(int j=0;j<matrix[0].size();j++)
            {
                v.push_back(matrix[i][j]);
            }
            this->matrix.push_back(v);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
       int ans=0;
        for(int i=row1;i<=row2 && i>=0;i++)
        {
           for(int j=col1;j<=col2 && j>=0;j++)
           {
               ans=ans+this->matrix[i][j];
               //cout<<matrix[i][j]<<"  ";
           }
            cout<<endl;
        }
        return ans;
    }
    */
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */