#include <sstream>

class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        int length = 1;
        char chr = word[0];
        std::stringstream ans;

        for (int i = 1; i < n; i++) {
            if (word[i] == chr) {
                length++;
                if (length == 9) {
                    ans << '9' << chr;  // Append the count and character
                    length = 0;          // Reset length after reaching 9
                }
            } else {
                if (length > 0) {
                    ans << length << chr;  // Append count and character
                }
                chr = word[i];            // Update the current character
                length = 1;               // Reset length for the new character
            }
        }
        
        if (length > 0) {
            ans << length << chr;  // Add the last accumulated count and character
        }

        return ans.str();
    }
};
