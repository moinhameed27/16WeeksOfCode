/*
Using sliding window approach:
When a substring is reached where at least one of each character from a, b, c is present then it is abvious
that all the next lengths will also have these characters. So we'll get the count of number of substrings as
n - j. After finding, shift the window from left side and count the next subarrays.
*/

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.size();
        unordered_map<char, int> freq;
        int ans = 0;
        int i = 0, j = 0;

        while (j < n)
        {
            freq[s[j]]++;

            while (freq['a'] >= 1 && freq['b'] >= 1 && freq['c'] >= 1)
            {
                ans += n - j;
                freq[s[i]]--;
                i++;
            }
            j++;
        }

        return ans;
    }
};