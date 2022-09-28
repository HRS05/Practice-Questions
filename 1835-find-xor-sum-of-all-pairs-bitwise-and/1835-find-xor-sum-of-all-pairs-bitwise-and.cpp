class Solution {
public:
    /*
    We can observe that (a1 & bi) XOR (a1 & bi) XOR ... XOR (an & bi) is the same as (a1 XOR a2 XOR ... XOR an) & bi.

So, we calculate XOR sum of the first array xa. Then, the final result is (xa & b1) XOR (xa & b2) XOR ... XOR (xa & bm), resulting in a linear solution.
    */
    
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        // int xxor=0;
        // int ans=0;
        // for(int num : arr1) xxor^=num;
        // for(int num : arr2) ans^=(xxor & num);
        // return ans;
        
        //or
        
        int xxor1=0;
        int xxor2=0;
        for(int num : arr1) xxor1^=num;
        for(int num : arr2) xxor2^=num;
        return xxor1 & xxor2;
        
    }
};