class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int mismatched_count = 0;
        char mismatched_letters[2];
        for(int i = 0;i < s1.length();i++){
            if(s1[i] != s2[i]) {
                mismatched_count++;
                switch (mismatched_count) {
                    case 1:
                    mismatched_letters[0] = s1[i];
                    mismatched_letters[1] = s2[i];
                    break;
                    case 2:
                    if((mismatched_letters[0] != s2[i]) || (mismatched_letters[1] != s1[i]))
                    return false;
                    break;
                    case 3:
                    return false;
                    break;
                }
            }
        }

        if(mismatched_count == 1)
        return false;
        else
        return true;
    }
};