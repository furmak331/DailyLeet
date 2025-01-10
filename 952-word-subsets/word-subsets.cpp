class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(26, 0);  // Store maximum frequency for words2
        
        // Calculate maximum frequency required for each character from words2
        for (const string& word : words2) {
            vector<int> currFreq(26, 0);
            for (char c : word) {
                currFreq[c - 'a']++;
                maxFreq[c - 'a'] = max(maxFreq[c - 'a'], currFreq[c - 'a']);
            }
        }
        
        vector<string> result;
        // Check each word in words1
        for (const string& word : words1) {
            vector<int> freq(26, 0);
            // Count frequency of current word
            for (char c : word) {
                freq[c - 'a']++;
            }
            
            // Check if this word has enough of each character
            bool isUniversal = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] < maxFreq[i]) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                result.push_back(word);
            }
        }
        
        return result;
    }
};