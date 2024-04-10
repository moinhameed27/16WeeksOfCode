/*
Approach is simple that we'll first sort the array and then add the deck elements into the answer array
alternatively. For the starting traversing, elements will be added alternatively. Then there will be some elements
remaining in the deck array to be added in the ans array. So we'll add them alternatively in the empty spaces of the 
ans array.
*/

class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        int n = deck.size();
        int i = 0, j = 0;
        vector<int> ans(n, 0);
        bool skip = false;
        // Sorting the array and adding alternatively elements
        sort(begin(deck), end(deck));

        while (i < n)
        {
            // If the space is empty
            if (ans[j] == 0)
            {
                // If there's turn of the element to be added
                if (skip == false)
                {
                    ans[j] = deck[i];
                    i++;
                }
                skip = !skip;
            }
            // For circular traversing of the array
            j = (j + 1) % n;
        }
        return ans;
    }
};