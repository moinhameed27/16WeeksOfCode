class Solution
{
    void reverseWord(string &s, int i, int j)
    {
        while (i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

public:
    string reverseWords(string s)
    {
        int i = 0, j = 0;
        int n = s.size();
        while (j < n)
        {
            // When a space character is found, means a word is complete
            if (s[j] == ' ')
            {
                reverseWord(s, i, j - 1);
                i = j + 1;
            }
            // For last word
            else if (j == n - 1)
                reverseWord(s, i, j);
            j++;
        }
        return s;
    }
};