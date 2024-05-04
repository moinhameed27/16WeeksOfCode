class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        int n = people.size();
        int i = 0, j = n - 1;
        int boats = 0;
        sort(begin(people), end(people));

        while (i <= j)
        {
            // If sum of left pointer and right pointer is <= limit
            if (people[i] + people[j] <= limit)
            {
                i++;
                j--;
                boats++;
            }
            // If sum is greater, decrement the left pointer as the right pointer will must take one boat for itself
            else
            {
                j--;
                boats++;
            }
        }
        return boats;
    }
};