class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        int n = nums.size();
        // Sort the array to apply two pointers approach accordingly
        sort(begin(nums), end(nums));
        int i = 0, j = n - 1;

        while (i < j)
        {
            if (nums[i] == -nums[j])
                return nums[j];

            // If left pointer is greater than right pointer, increment left pointer
            else if (nums[i] < -nums[j])
                i++;

            // If left pointer is smaller than right pointer, increment right pointer
            else
                j--;
        }
        // If values not found
        return -1;
    }
};