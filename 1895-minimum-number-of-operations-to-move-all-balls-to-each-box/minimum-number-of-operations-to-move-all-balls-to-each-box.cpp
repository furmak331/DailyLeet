class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> answer(n, 0);
        
        // Count total 1s and sum of their positions
        int totalOnes = 0;
        int positionSum = 0;
        
        for(int i = 0; i < n; i++) {
            if(boxes[i] == '1') {
                totalOnes++;
                positionSum += i;
            }
        }
        
        int leftOnes = 0;
        int leftSum = 0;
        
        for(int i = 0; i < n; i++) {
            // Total moves = moves from left balls + moves from right balls
            
            // Left part: number of ones to left * current position - sum of their positions
            int leftMoves = i * leftOnes - leftSum;
            
            // Right part: sum of positions of ones to right - number of ones to right * current position
            int rightOnes = totalOnes - leftOnes;
            int rightSum = positionSum - leftSum;
            int rightMoves = rightSum - (i * rightOnes);
            
            answer[i] = leftMoves + rightMoves;
            
            // Update left counters if current position has 1
            if(boxes[i] == '1') {
                leftOnes++;
                leftSum += i;
            }
        }
        
        return answer;
    }
};