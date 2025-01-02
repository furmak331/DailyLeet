class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefix(words.size() + 1, 0); 
        vector<int> ans;
        
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        
        for (int i = 0; i < words.size(); i++) {
            if (isVowel(words[i][0]) && isVowel(words[i].back())) {
                prefix[i + 1] = prefix[i] + 1;
            } else {
                prefix[i + 1] = prefix[i];
            }
        }
        
        for (const auto& query : queries) {
            int begin = query[0];
            int end = query[1];
            ans.push_back(prefix[end + 1] - prefix[begin]);
        }
        
        return ans;
    }
};
