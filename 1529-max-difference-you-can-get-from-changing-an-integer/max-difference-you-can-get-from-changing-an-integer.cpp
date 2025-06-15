class Solution {
public:
    int maxDiff(int num) {
        std::string num_str = to_string(num);
        std::string maxi = num_str;
        std::string mini = num_str;
        int size = maxi.length();

        int j = 0;
        while(num_str[j] == '9' && j < size) j++;
        char target = num_str[j];

        for(int i = 0;i < size;i++) if(num_str[i] == target) maxi[i] = '9';

        j = 0;
        while((num_str[j] == '1'|| num_str[j] == '0') && j < size) j++;
        target = num_str[j];

        char pivot = '1';
        if(j) pivot = '0';
         
        for(int i = 0;i < size;i++) if(num_str[i] == target) mini[i] = pivot;
        return stoi(maxi) - stoi(mini);
    }
};