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

        //cout << "Initial word: " << word << ", numFriends: " << numFriends << endl;

        for (int i = 0; i < length; i++) {
           // cout << "Checking character at index " << i << ": " << word[i] << endl;

            if (word[i] > max) {
                max = word[i];
                max_index = i;
                //cout << "New max character found: " << max << " at index " << max_index << endl;
            }
            else if (word[i] == max) {
               // cout << "Equal max character found at index " << i << ", comparing substrings..." << endl;
                int left = max_index + 1;
                int right = i + 1;

                while (true) {
                    if (left >= length || right >= length) {
                        //cout << "Reached end of string during comparison" << endl;
                        break;
                    }

                   // cout << "Comparing word[" << left << "] = " << word[left]
                      //   << " with word[" << right << "] = " << word[right] << endl;

                    if (word[left] > word[right]) {
                        if (word[left] > max) {
                            max = word[left];
                            max_index = left;
                           // cout << "Updated max to word[" << left << "] = " << max << endl;
                        }
                        break;
                    }
                    else if (word[left] < word[right]) {
                        if (word[right] > max) {
                            max = word[right];
                            max_index = right;
                           // cout << "Updated max to word[" << right << "] = " << max << endl;
                        } else {
                            max_index = i;
                           // cout << "Retaining max as " << max << ", updating max_index to " << max_index << endl;
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

       // cout << "Final max character: " << max << " at index " << max_index << endl;

       string result;
        int substrLength;

        if (max_index > (numFriends - 2)) {
            substrLength = length - max_index;
            result = word.substr(max_index, substrLength);
           // cout << "1) Using substr from " << max_index << " to " << max_index + substrLength - 1 << ": " << result << endl;
        } else {
            substrLength = length - numFriends + 1;
            result = word.substr(max_index, substrLength);
           // cout << "2) Using substr from " << max_index << " to " << max_index + substrLength - 1 << ": " << result << endl;
        }

        //cout << "Final Result: " << result << endl;
        return result;
            }
};
