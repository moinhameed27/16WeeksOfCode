class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> freq(n + 1, 0);

        // Iterate through nums to mark the presence of positive integers
        for (int i : nums)
        {
            // Only mark the presence of positive integers
            if (i > 0 && i <= n)
                freq[i] = 1;
        }

        // Iterate through the frequency array to find the first missing positive integer
        for (int i = 1; i <= n; i++)
        {
            if (freq[i] == 0)
                return i;
        }
        
        // If no missing positive integer found, return the next positive integer after the range
        return n + 1;
    }
};
