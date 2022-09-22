class Solution {
    
    
    int findViolationPosition(string &num) {
        for(int i=1; i < num.size(); i++) {
            // check if previous number greater than next i.e violation
            if(num[i-1] > num[i])
                return i;
        }
        return -1;   
    }
    
    int findSmallestIndexToChange(int violation_position,string &num) {
        int smallest_index = violation_position - 1;
        for(; smallest_index >=0; smallest_index--) {
            if(num[smallest_index] != num[violation_position-1]) {
                break;
            }
        }
        return smallest_index+1;
    }
    
    string removeViolations(int smallest_index,string &num) {
        string sol = num;
        sol[smallest_index]--;
        for(int i=smallest_index+1; i<sol.size(); i++) {
            sol[i] = '9';
        }
        return sol;
    }
    
public:
    int monotoneIncreasingDigits(int n) {
        string num;
        num = to_string(n);
        int violation_position = findViolationPosition(num);
        if(violation_position == -1) 
            return n;
        int smallest_index = findSmallestIndexToChange(violation_position,num);
        string ans = removeViolations(smallest_index,num);
        return stoi(ans);
    }
};