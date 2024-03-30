class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        // Find the maximum element in nums
        int maxElement = *max_element(nums.begin(), nums.end()); 
        long long ans = 0;                                       
        int i = 0, j = 0, countMax = 0, n = nums.size();         

        while (j < n)
        {
            // If the current element is the maximum element, increment countMax
            if (nums[j] == maxElement)
                countMax++;

            // Shrink the window from the left until countMax is less than k
            while (countMax >= k)
            {
                // Add the count of subarrays formed with the current j pointer
                // If max element appears >= K times in a subarray then it will also appear in all next elements subarray
                ans += n - j;

                // If the element at the left pointer is the maximum element, decrement countMax
                if (nums[i] == maxElement)
                    countMax--;
                i++; // Move the left pointer
            }
            j++; // Move the right pointer
        }
        return ans; 
    }
};
