class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        // Storing the Frequency of Each Element in another Vector
        vector<int> freq(n, 0);
        for (int i : nums)
        {
            freq[i]++;
        }
        // Returning the element index which has more than one occurrences
        for (int i = 0; i < n; i++)
        {
            if (freq[i] > 1)
                return i;
        }
        // Otherwise returning 0
        return 0;
    }
};