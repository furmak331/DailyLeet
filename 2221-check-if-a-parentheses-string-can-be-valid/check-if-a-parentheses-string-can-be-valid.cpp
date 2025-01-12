class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() % 2 != 0) {
            return false;
        }
        
        int n = s.size();
        int minOpen = 0;  // minimum possible open parentheses
        int maxOpen = 0;  // maximum possible open parentheses
        
        for (int i = 0; i < n; i++) {
            if (locked[i] == '1') {
                if (s[i] == '(') {
                    minOpen++;
                    maxOpen++;
                } else {
                    minOpen--;
                    maxOpen--;
                }
            } else {
                // For unlocked position, we can either use '(' or ')'
                minOpen--;      // Consider placing ')'
                maxOpen++;      // Consider placing '('
            }
            
            // Can't have negative open parentheses
            minOpen = max(0, minOpen);
            
            // If maxOpen becomes negative, we have too many forced ')'
            if (maxOpen < 0) return false;
            
            // If minOpen > maxOpen, invalid state
            if (minOpen > maxOpen) return false;
        }
        
        // At end, need at least one way to have 0 open parentheses
        return minOpen <= 0 && 0 <= maxOpen;
    }
};