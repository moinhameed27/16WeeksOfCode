class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int n = nums.size();        
        int i = 0, j = 0, ans = 0;  
        unordered_map<int, int> mp; // Map to store the frequency of elements

        while (j < n)
        {
            // Increment frequency of the current element
            mp[nums[j]]++; 

            // Shrink the window from the left until the frequency of elements is not greater than k
            while (i < j && mp[nums[j]] > k)
            {
                mp[nums[i]]--; // Decrement frequency of the element at the left pointer
                i++;           // Move the left pointer
            }

            // Update the maximum length of good subarray
            ans = max(ans, j - i + 1);
            j++; // Move the right pointer
        }
        return ans; 
    }
};
