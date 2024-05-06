class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int i = 0, j = 0;
        int ans = 0, countZeros = 0;

        while (j < n)
        {
            if (nums[j] == 0)
                countZeros++;
            while (countZeros > k)
            {
                if (nums[i] == 0)
                    countZeros--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};