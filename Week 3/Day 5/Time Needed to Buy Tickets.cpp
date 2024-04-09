class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int ans = 0;
        while (tickets[k] > 0)
        {
            for (int i = 0; i < tickets.size(); ++i)
            {
                if (tickets[i] > 0)
                {
                    tickets[i]--;
                    ans++;
                    // If tickets at k index are bought already, return from here
                    if (i == k && tickets[k] == 0)
                        return ans;
                }
            }
        }
        return ans;
    }
};
