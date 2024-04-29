class Solution
{
    int binarySearch(vector<int> &nums, int start, int end, int target, bool firstIndex)
    {
        int ans = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target)
                start = mid + 1;
            else if (nums[mid] > target)
                end = mid - 1;
            else
            {
                ans = mid;
                // If we are checking for the first presence of target, eliminate the second presence by (end = mid - 1)
                if (firstIndex)
                    end = mid - 1;
                // Second time, we'll get the second presence of the target
                else
                    start = mid + 1;
            }
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> ans(2, -1);
        ans[0] = binarySearch(nums, 0, n - 1, target, true);
        ans[1] = binarySearch(nums, 0, n - 1, target, false);

        return ans;
    }
};