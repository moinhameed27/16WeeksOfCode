/*
Sort the Array. In this way maximum number of coins will be on the right side which can be picked by Alice and You.
Minimum number of coins will be on the left side which will be picked by Bob. The most important part of this question
is that Bob should pick the smallest number of coins, not the last one remaining after You and Alice picked.
So going with with the example:
[9, 8, 7, 6, 5, 1, 2, 3, 4]
1. After Sorting
[1, 2, 3, 4, 5, 6, 7, 8, 9]
2. Alice picks 9, You pick 8 and Bob picks 1
[2, 3, 4, 5, 6, 7]
3. Alice picks 7, You pick 6 and Bob picks 2
[3, 4, 5]
4. Alice picks 5, You pick 4 and Bob picks 3
5. Answer = 8 + 6 + 4 -> 18
*/

class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        int n = piles.size();
        int ans = 0;
        sort(begin(piles), end(piles));

        // Start with i = n / 3 and you'll only access coins picked by You if incremented 2 every time
        for (int i = n / 3; i < n; i += 2)
            ans += piles[i];

        return ans;
    }
};
