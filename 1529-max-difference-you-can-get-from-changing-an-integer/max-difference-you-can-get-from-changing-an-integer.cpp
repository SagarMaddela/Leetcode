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
        //cout << "Max target is :" << target  << " & j is "<< j << endl;

        for(int i = 0;i < size;i++){
            if(num_str[i] == target) maxi[i] = '9';
        }

        j = 0;
        while((num_str[j] == '1'|| num_str[j] == '0') && j < size) j++;
        target = num_str[j];
        char pivot = '1';
        if(j) pivot = '0'; 
        //cout << "Mini target is :" << target << endl;
    
        for(int i = 0;i < size;i++){
            if(num_str[i] == target){
                mini[i] = pivot;
            }
           // cout << "Mini at " << i << " is " << mini[i] << endl;
        }

       // cout << stoi(maxi) << " - " << stoi(mini) << endl; 
        return stoi(maxi) - stoi(mini);
    }
};