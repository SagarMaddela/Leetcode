#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1) {
            return word;
        }
        char max = 'a';
        int max_index = -1;
        int length = word.length();
        for (int i = 0; i < length; i++) {
            if (word[i] > max) {
                max = word[i];
                max_index = i;
            }
            else if (word[i] == max) {
                int left = max_index + 1;
                int right = i + 1;
                while (true) {
                    if (left >= length || right >= length) {
                        break;
                    }
                    if (word[left] > word[right]) {
                        if (word[left] > max) {
                            max = word[left];
                            max_index = left;
                        }
                        break;
                    }
                    else if (word[left] < word[right]) {
                        if (word[right] > max) {
                            max = word[right];
                            max_index = right;
                        } else {
                            max_index = i;
                        }
                        break;
                    }
                    else {
                        left++;
                        right++;
                    }
                }
            }
        }
       string result;
        int substrLength;
        if (max_index > (numFriends - 2)) {
            substrLength = length - max_index;
            result = word.substr(max_index, substrLength);
        } else {
            substrLength = length - numFriends + 1;
            result = word.substr(max_index, substrLength);
        }
        return result;
            }
};
