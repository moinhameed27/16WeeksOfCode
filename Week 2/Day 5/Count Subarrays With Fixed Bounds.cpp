class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        int i = 0, n = nums.size();                      
        long long temp, ans = 0;                         
        int minKPos = -1, maxKPos = -1, culpritIdx = -1; 
        // Culprit Index is that element index which is out of bound i.e (culpritIdx > maxK || culpritIdx < minK)
        while (i < n)
        {
            // Check if the current element is culprit or not
            if (nums[i] < minK || nums[i] > maxK)
                culpritIdx = i; 

            // Check if the current element is equal to minK
            if (nums[i] == minK)
                minKPos = i; 

            // Check if the current element is equal to maxK
            if (nums[i] == maxK)
                maxKPos = i; 

            // Calculate the length of the smaller subarray between minKPos and maxKPos, compared to the culprit index
            long long smaller = min(minKPos, maxKPos);
            temp = smaller - culpritIdx;   // Calculate the length of the subarray
            ans += (temp <= 0) ? 0 : temp; // If the length is positive, add it to the answer

            i++; 
        }
        return ans; 
    }
};
