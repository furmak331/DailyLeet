class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.length()) return false;
        if (k == s.length()) return true;
        
        int oddMask = 0;
        
        for (char c : s) {
            oddMask ^= (1 << (c - 'a'));
        }
        
        int oddCount = __builtin_popcount(oddMask);
        
        return oddCount <= k;
    }
};