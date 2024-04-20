/*
If the string is already a palindrome, then there will be only one step to make the string empty, else it will take
two steps as the string contains only two characters (only 'a' and 'b')
*/

class Solution {
public:
    int removePalindromeSub(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j)
        {
            if(s[i] != s[j])
                return 2;
            i++; j--;
        }
        return 1;
    }
};