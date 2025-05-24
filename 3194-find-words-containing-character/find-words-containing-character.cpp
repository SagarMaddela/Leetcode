class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        std::vector<int> result;
        int length = words.size();
        for(int i = 0; i < length;i++){
            for(char ch : words[i]){
                if(ch == x){
                    result.push_back(i);
                    break;
                }
            }
        }
        return result;
    }
};