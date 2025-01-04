class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int total = 0;
        
        for (char c = 'a'; c <= 'z'; c++) {
            int first = s.find(c);
            int last = s.rfind(c);
            
            if (first != -1 && last != -1 && first < last) {
                unordered_set<char> between;
                for (int i = first + 1; i < last; i++) {
                    between.insert(s[i]);
                }
                total += between.size();
            }
        }
        
        return total;
    }
};