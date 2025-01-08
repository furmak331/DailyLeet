#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPrefixAndSuffix(const string &a, const string &b) {
        int n = a.size();
        int m = b.size();
        if (n > m) return false; 
        if (b.substr(0, n) == a && b.substr(m - n) == a) {
            return true;
        }
        return false;
    }

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (i != j && isPrefixAndSuffix(words[i], words[j])&&i!=j) {
                    count++;
                }
            }
        }
        return count;
    }
};