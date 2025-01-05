class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> netShifts(n + 1, 0);

        for (int i = 0; i < shifts.size(); i++) {
            int start = shifts[i][0];
            int end = shifts[i][1];
            int direction = (shifts[i][2] == 1) ? 1 : -1;

            netShifts[start] += direction;
            netShifts[end + 1] -= direction;
        }

        int cumulativeShift = 0;
        for (int i = 0; i < n; i++) {
            cumulativeShift += netShifts[i];
            int currentPos = s[i] - 'a';                     
            int newPos = (currentPos + cumulativeShift % 26 + 26) % 26;
            s[i] = 'a' + newPos;                           
        }

        return s;
    }
};
