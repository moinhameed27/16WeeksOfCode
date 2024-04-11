/*
The Approach to the solution is that we'll try to traverse the string in increasing order. If the
current element is non-decreasing, add it to the answer. For the next time, if the current element
is less than previous element, remove the previous element. At the same time, check for preceding 
zeros. If there are any, remove them for the correct output.
Corner Case :  If the elements are already in the increading order, then there will be no elements
removed with this approach so we'll check if k is still greater than zero then, we'll simply remove
last k elements remaining.
At last if string is empty, we've to return "0" as given in the question. Otherwise whatever the 
output is.
*/

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        string ans;
        int n = num.size();

        for (int i = 0; i < n; i++)
        {
            // If ans is not empty & last element in ans is greater than current element(culprit)
            // & k is greater than zero(elements are still to be removed)
            while (ans.size() > 0 && ans.back() > num[i] && k > 0)
            {
                ans.pop_back();
                k--;
            }

            // Special case for Preceding zeros
            if (ans.size() > 0 || num[i] != '0')
                ans.push_back(num[i]);
        }

        // If elements are in increasing order, remove last k elements
        while (ans.size() > 0 && k > 0)
        {
            ans.pop_back();
            k--;
        }

        // If resulting string is empty, then simply return "0"
        if (ans == "")
            return "0";

        return ans;
    }
};