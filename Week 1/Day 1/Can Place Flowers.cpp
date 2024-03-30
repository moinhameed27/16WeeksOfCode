class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int s = flowerbed.size();
        int i = 0;
        // Loop until all flowers are planted or end of flowerbed is reached
        while (n > 0 && i < s)
        {
            // If the current plot already has a flower, skip to the next available plot
            if (flowerbed[i] == 1)
                // Increment by 2 as no flowers can be placed in adjacent plots
                i += 2;
            else
            {
                // Check if the current plot and its adjacent plots are empty and plantable
                if ((i == 0 || flowerbed[i - 1] == 0) && (i == s - 1 || flowerbed[i + 1] == 0))
                {
                    n--;
                    i++;
                }
                i++;
            }
        }
        // Return true if all flowers are planted, false otherwise
        return n == 0;
    }
};