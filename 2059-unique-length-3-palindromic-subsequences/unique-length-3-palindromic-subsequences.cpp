class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, INT_MAX);
        vector<int> last(26, INT_MIN);
        
        for (int i = 0; i < s.length(); i++) {
            int idx = s[i] - 'a';
            first[idx] = min(first[idx], i);
            last[idx] = max(last[idx], i);
        }
        
        int total = 0;
        for (int i = 0; i < 26; i++) {
            if (first[i] < last[i]) {
                vector<bool> between(26, false);
                for (int j = first[i] + 1; j < last[i]; j++) {
                    between[s[j] - 'a'] = true;
                }
                total += count(between.begin(), between.end(), true);
            }
        }
        
        return total;
    }
};