// Way - I (Extra Space - Taking another vector and copying values Accordingly)
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        vector<int> ans(n);

        // Copying last k elements
        for (int i = 0, j = n - k; i < n && j < n; i++, j++)
            ans[i] = nums[j];

        // Copying n - k elements from the start
        for (int i = k, j = 0; i < n && j < n - k; i++, j++)
            ans[i] = nums[j];

        nums = ans;
    }
};

// Way - II (No Extra Space - Reverse)
class Solution
{
    void reverse(vector<int> &nums, int i, int j)
    {
        while (i < j)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }

public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k %= n;
        // Reversing all Elements
        reverse(nums, 0, n - 1);
        // Reversing first k elements
        reverse(nums, 0, k - 1);
        // Reversing all elements after k
        reverse(nums, k, n - 1);
    }
};