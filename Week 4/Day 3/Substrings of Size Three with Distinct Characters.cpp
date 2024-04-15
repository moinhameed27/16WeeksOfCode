class Solution
{
public:
    int countGoodSubstrings(string s)
    {
        int i = 0, j = 2;
        int ans = 0, n = s.size();
        while (j < n)
        {
            if (s[j] != s[j - 1] && s[j] != s[j - 2] && s[j - 1] != s[j - 2])
                ans++;
            i++;
            j++;
        }
        return ans;
    }
};