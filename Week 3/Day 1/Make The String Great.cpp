#include <string>
using namespace std;

class Solution
{
public:
    string makeGood(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            // If the difference is 32, it means the characters are the same letter but different cases
            if (i < s.size() - 1 && abs(s[i] - s[i + 1]) == 32)
            {
                // Erase the current character and the next character from the string
                s.erase(i, 2);
                // Update the loop index to continue checking from the character before the removed characters
                // Ensure the loop index doesn't go below -1
                i = max(-1, i - 2);
            }
        }
        return s;
    }
};
