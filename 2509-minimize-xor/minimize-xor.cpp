#include <math.h>
#include <vector>
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // First get the correct count of bits in both numbers
        int bits1 = countSetBits(num1);
        int bits2 = countSetBits(num2);
        
        vector<int> num1bits;
        int temp = num1;
        while(temp > 0) {
            num1bits.insert(num1bits.begin(), temp % 2); 
            temp = temp / 2;
        }
        
        while(num1bits.size() < 32) {
            num1bits.insert(num1bits.begin(), 0);
        }
        
        vector<int> result(32, 0);
        int bitsNeeded = bits2; 
        
        for(int i = 0; i < 32 && bitsNeeded > 0; i++) {
            if(num1bits[i] == 1) {
                result[i] = 1;
                bitsNeeded--;
            }
        }
        
        if(bitsNeeded > 0) {
            for(int i = 31; i >= 0 && bitsNeeded > 0; i--) {
                if(result[i] == 0) { 
                    result[i] = 1;
                    bitsNeeded--;
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            if(result[i] == 1) {
                ans += pow(2, 31-i);
            }
        }
        
        return ans;
    }
    
private:
    int countSetBits(int n) {
        int count = 0;
        while(n > 0) {
            if(n & 1) count++;
            n = n >> 1;
        }
        return count;
    }
};