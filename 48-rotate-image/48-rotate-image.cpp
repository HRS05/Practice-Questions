class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size()==0) return;
        int n=matrix.size();
        
             for (int i = 0; i < n; i++) 
             {
            for (int j = i + 1; j < n; j++) 
            {
                int tmp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }
        
        
        for(int i=0;i<n;i++)
        {
            int a=0;
            int b=n-1;
            while(a<b)
            {
                swap(matrix[i][a],matrix[i][b]);
                a++;
                b--;
            }
        }
        
    }
};


