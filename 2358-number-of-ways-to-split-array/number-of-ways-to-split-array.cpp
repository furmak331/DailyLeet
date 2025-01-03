class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long totalSum = 0; 
        long long leftSum = 0;
        long long count = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }
          for(int i = 0; i < nums.size() - 1; i++) {
            leftSum += nums[i];
            long long rightSum = totalSum - leftSum;
            
            if(leftSum >= rightSum) {  
                count++;
            }
        }
        
        return count;
    }
};