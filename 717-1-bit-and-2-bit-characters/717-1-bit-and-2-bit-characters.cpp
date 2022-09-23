class Solution {
public:
    bool isOneBitCharacter(vector<int> &bits) {
    int n = bits.size();
    int idx = 0;

    while (idx < n) {
      if (bits[idx] == 0 && idx == n - 1) return true;
      if (bits[idx] == 0) idx += 1;
      if (bits[idx] == 1) idx += 2;
    }
    return false;
  }
};