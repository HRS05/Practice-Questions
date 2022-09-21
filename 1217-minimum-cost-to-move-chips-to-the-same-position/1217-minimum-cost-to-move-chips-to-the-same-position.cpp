class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int ec=0;
        int oc=0;
        for(int n : position)
        {
            if(n%2 == 0) ec++;
            else oc++;
        }
        return min(ec,oc);
    }
};