class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        
        /*
        
         128 64 32 16 8 4 2 1
         1    1  1  1 0 0 0 0 -> 240
         1    1  1  0 0 0 0 0 -> 224
         1    1  0  0 0 0 0 0 -> 192
         1    0  0  0 0 0 0 0 -> 128
        
        
        
        */
        for(int i=0;i<n;i++){
            int bytes = 0;
            int val = data[i];
            if(val > 255){
                return false;
            }else if((val & 128) == 0){
                bytes = 1;
            }else if((val & 224) == 192){ // val bit anded with 224 will give 192  
                bytes = 2;
                
            }else if((val & 240) == 224){
                bytes = 3;
                
            }else if((val & 248) == 240){
                bytes = 4;
            }else{
                return false;
            }
            
            for(int j=1;j<bytes;j++){
                if(j+i >= data.size()){ // if found a 3 degree , the utf set should have 111xxxx 10xxxxxx 10xxxxxx
                    // if the bytes + index at which you are in exceeds the data size means theres incomplete UTF set so return false;
                    return false;
                }else if((data[j+i]&192) != 128){ // if fouund any n degree the next elements should have n-1 10xxxxxx(128) elements
                    return false;
                }
            }
            i+=bytes-1; // UTF set will contain Bytes terms , so to jump on next UTF set (bytes -1)
        }
        return true;
    }
};