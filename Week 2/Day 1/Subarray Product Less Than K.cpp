class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int n = nums.size();                      
        int i = 0, j = 0, count = 0, product = 1; 

        // If k is less than or equal to 1, no subarray will have product less than k, return 0
        if (k <= 1)
            return 0;

        while (j < n)
        {
            product *= nums[j]; // Update product by including the next element

            // Shrink the window from the left until product is less than k
            while (product >= k)
            {
                product /= nums[i]; // Exclude elements from the left and update product
                i++;                // Move the left pointer
            }

            // Count the number of subarrays that can be formed with the current window
            count += (j - i) + 1;
            j++; // Move the right pointer
        }
        return count; 
    }
};
