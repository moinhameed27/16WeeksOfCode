class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        int n = dist.size();
        vector<int> time(n); 

        // Calculate the time required for each monster to reach the city
        for (int i = 0; i < n; i++)
            time[i] = ceil((double)dist[i] / speed[i]);

        // Sort the time array in ascending order so that nearest monsters can be eliminated first
        sort(begin(time), end(time));

        // Initializing count and minutes as 1 because at least one monster will be eliminated for sure
        int count = 1, minutes = 1;
        for (int i = 1; i < n; i++)
        {
            // If the time remaining for the current monster to reach the city is less than or equal to the time elapsed,
            // return the count of eliminated monsters
            if (time[i] - minutes <= 0)
                return count;
            else
            {
                count++;   // Increment count of eliminated monsters
                minutes++; // Increment time passed
            }
        }
        return count;
    }
};
