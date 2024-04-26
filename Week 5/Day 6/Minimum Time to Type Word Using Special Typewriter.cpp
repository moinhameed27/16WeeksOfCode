class Solution
{
public:
    int minTimeToType(string word)
    {
        int n = word.size(), ans = 0;
        const int size = 26; // Number of lowercase alphabets
        char curr = 'a';

        for (int i = 0; i < n; i++)
        {
            // If both characters match, one second to write the word
            if (word[i] == curr)
                ans++;
            else
            {
                // Find the smaller distance between the characters as the alphabets are placed in circle
                int clockwise = (word[i] - curr + size) % size;
                int antiClockwise = (curr - word[i] + size) % size;
                // Ans += Number of seconds to reach that character + one second to write the character
                ans += min(clockwise, antiClockwise) + 1;
                // The word is written by the typewriter so update the current word
                curr = word[i];
            }
        }
        return ans;
    }
};