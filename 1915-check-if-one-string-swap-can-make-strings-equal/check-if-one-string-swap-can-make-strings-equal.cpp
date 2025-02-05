class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count = 0, i1 = -1, i2 = -1;
        
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                count++;
                if (count == 1) i1 = i;
                else if (count == 2) i2 = i;
                else return false; // More than 2 mismatches → return false early
            }
        }
        
        return (count == 0) || (count == 2 && s1[i1] == s2[i2] && s1[i2] == s2[i1]);
    }
};
