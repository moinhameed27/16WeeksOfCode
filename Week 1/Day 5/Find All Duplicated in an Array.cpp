class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        // Numbers are in the range [1,n] so for storing the nth element --> freq(n + 1)
        vector<int> freq(n + 1);
        vector<int> ans;
        for(int i : nums)
            // Storing Frequency of Elements
            freq[i]++;
        
        for(int j = 1; j <= n; j++)
        {
            if(freq[j] == 2)
            // Checking for double frequency elements and storing 'em
                ans.push_back(j);
        }
        
        return ans;
    }
};







