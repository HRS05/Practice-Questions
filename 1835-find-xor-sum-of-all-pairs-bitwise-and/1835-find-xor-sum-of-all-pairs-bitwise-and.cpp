class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int xxor=0;
        int ans=0;
        for(int num : arr1) xxor^=num;
        for(int num : arr2) ans^=(xxor & num);
        return ans;
    }
};