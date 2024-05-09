class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        sort(begin(happiness), end(happiness));
        int n = happiness.size();
        long long sum = 0;
        int minus = 0, i = n - 1;

        while (minus < k)
        {
            int add = happiness[i] - minus > 0 ? happiness[i] - minus : 0;
            sum += add;
            minus++;
            i--;
        }
        
        return sum;
    }
};