class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k) {
            return false;
        }

        int letters[26] = {0};
        for (char& c : s) {
            ++letters[c - 'a'];
        }

        int oddCount = 0;
        for (int count : letters) {
            oddCount += count & 1;
        }
        return oddCount <= k;
    }
};