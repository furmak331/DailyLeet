class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() % 2 != 0) {
            return false;
        }
        
        int n = s.size();
        int balance = 0;
        int available = 0;
        
        for (int i = 0; i < n; i++) {
            if (locked[i] == '1') {
                balance += (s[i] == '(' ? 1 : -1);
            } else {
                available++;
            }
            
            if (balance + available < 0) {
                return false;
            }
        }
        
        balance = 0;
        available = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            if (locked[i] == '1') {
                balance += (s[i] == ')' ? 1 : -1);
            } else {
                available++;
            }
            
            if (balance + available < 0) {
                return false;
            }
        }
        
        return true;
    }
};