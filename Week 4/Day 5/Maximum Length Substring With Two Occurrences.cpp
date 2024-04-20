/*
Keep counting the frequency and whenever a character count reaches 3 then shift the window and count the length
of maximum substring.
*/

class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        unordered_map<char, int> freq;
        int n = s.size();
        int i = 0, j = 0, ans = 0;
        while (j < n)
        {
            freq[s[j]]++;
            while (freq[s[j]] == 3)
            {
                freq[s[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};