class Solution {
public:
    string removeOccurrences(string s, string part) {
        int partSize = part.size();
        size_t position = s.find(part);
        while (position != string::npos) {
            s.erase(position, partSize);
            position = s.find(part);
        }
        return s;
    }
};
