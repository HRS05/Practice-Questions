class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        priority_queue<int> maxHeap;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                maxHeap.push(matrix[i][j]);
                if(maxHeap.size() > k) maxHeap.pop();
            }
        }
        return maxHeap.top();
    }
};