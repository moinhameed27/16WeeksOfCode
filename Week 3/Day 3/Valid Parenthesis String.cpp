class Solution
{
public:
    bool checkValidString(string s)
    {
        // Two stacks to keep track of brackets and stars
        stack<int> brackets, stars;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            // Case - I
            if (s[i] == '(')
                brackets.push(i);
            // Case - II
            else if (s[i] == '*')
                stars.push(i);
            // Case - III ( s[i] == ')' )
            else
            {
                // If there is any open bracket before, pop it - () Completed
                if (!brackets.empty())
                    brackets.pop();
                // If there is any star available, pop it - () Completed by making '*' a '('
                else if (!stars.empty())
                    stars.pop();
                // If neither is available, ')' bracket can't be completed
                else
                    return false;
            }
        }

        // Another loop to traverse the remaining open brackets - completing them using available stars
        while (!brackets.empty())
        {
            // If neither star is available, '(' can't be completed
            if (stars.empty())
                return false;
            // If star is available, check that it's index should be higher than '(' - If yes, pop both (brackets completed)
            else if (brackets.top() < stars.top())
            {
                brackets.pop();
                stars.pop();
            }
            // If index of star is less than '(', bracket cannot be completed --> e.g " *( "
            else
                return false;
        }
        return true;
    }
};