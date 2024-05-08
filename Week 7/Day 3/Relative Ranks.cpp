class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        // Rank counter3 to keep track of the ranks
        int n = score.size(), rank = 1;

        vector<int> highest(score);
        sort(highest.begin(), highest.end());

        vector<string> answer(n);
        // Map to store the strings for the respective scores
        unordered_map<int, string> mp;

        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
                mp[highest[i]] = "Gold Medal";
            else if (i == n - 2)
                mp[highest[i]] = "Silver Medal";
            else if (i == n - 3)
                mp[highest[i]] = "Bronze Medal";
            else
                mp[highest[i]] = to_string(rank);
            rank++;
        }

        // Storing values in answer with respect to scores
        for (int i = 0; i < n; i++)
        {
            answer[i] = mp[score[i]];
        }

        return answer;
    }
};