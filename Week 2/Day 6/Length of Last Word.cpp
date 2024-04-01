class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int n = s.size();
        int count = 0;
        // Iterating from end
        for (int i = s.size() - 1; i >= 0; i--)
        {
            // Count the length of the word
            if (isalnum(s[i]))
                count++;
            // If count is non-zero and the character is not alphanumeric (means it is a space), return
            else
            {
                if (count > 0)
                    break;
            }
        }
        return count;
    }
};
