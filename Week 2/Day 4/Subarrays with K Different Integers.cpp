class Solution
{
    int slidingWindow(vector<int> &nums, int k)
    {
        int i = 0, j = 0, count = 0, n = nums.size();
        unordered_map<int, int> mp;

        while (j < n)
        {
            mp[nums[j]]++; // Increment the frequency of the current element

            // Shrink the window from the left until the number of different integers becomes greater than k
            while (mp.size() > k)
            {
                // Decrement the frequency of the element at the left pointer
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]); // Remove the element from the map if its frequency becomes zero
                i++;                   // Move the left pointer
            }
            // Total number of subarrays ending at k (j - i + 1)
            count += j - i + 1;
            j++; // Move the right pointer
        }
        return count;
    }

public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        // As (j - i + 1) will also include subarrays having unique elements less than k so to remove them
        // we'll once use the sliding window function for k - 1 so that we can get exact number of subarrays
        // having unique elements equal to k
        return slidingWindow(nums, k) - slidingWindow(nums, k - 1);
    }
};
