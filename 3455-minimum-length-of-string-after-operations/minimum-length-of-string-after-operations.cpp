class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> m1;

        for (char c : s) {
            m1[c]++;
        }

        int min_len = s.size();

        for (int i = 0; i < s.size(); i++) {
            if (m1[s[i]] > 2) {
                if (m1[s[i]] % 2 == 1) {
                    min_len -= (m1[s[i]] - 1);
                    m1[s[i]] = 1;
                } else {
                    min_len -= (m1[s[i]] - 2);
                    m1[s[i]] = 2;
                }
            }
        }

        return min_len;
    }
};
