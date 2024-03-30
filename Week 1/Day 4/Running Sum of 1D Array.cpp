class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        // First Element will be the same as nums
        ans[0] = nums[0];
        // Storing next sum by prefix addition
        for (int i = 1; i < n; i++)
        {
            ans[i] = nums[i] + ans[i - 1];
        }
        return ans;
    }
};
