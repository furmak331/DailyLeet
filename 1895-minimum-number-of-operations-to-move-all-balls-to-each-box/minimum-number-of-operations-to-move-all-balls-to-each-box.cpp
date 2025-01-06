class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> answer(n, 0);  
        vector<int> validindex;
        
        for(int i = 0; i < n; i++) {
            if(boxes[i] == '1') {
                validindex.push_back(i);
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < validindex.size(); j++) {
                answer[i] += abs(validindex[j] - i);
            }
        }
        
        return answer;
    }
};