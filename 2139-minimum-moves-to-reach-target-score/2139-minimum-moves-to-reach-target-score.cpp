class Solution {
public:
/*    
    Intuition
    We should use double action as late as possible, as many as possible.
    Do this process reversely: Reduce target to 1.
    We try to use the HALF action as soon as possbile..


    Explanation
    If we still "half" action, we do it.
    If it's odd, we decrese it by 1 and make it half, which takes two actions.
    If it's even, we make it half, which takes one action.

    If no more "half" action, we decrement continuously to 1, which takes target - 1 actions.


    Complexity
    Time O(logn)
    Space O(1)
*/    
    int minMoves(int target, int maxDoubles) 
    {
        int res=0;
        while(target > 1 && maxDoubles)
        {
            res += 1 + target%2;
            maxDoubles--;
            target >>= 1;
        }
        
        return target-1+res;
    }
};