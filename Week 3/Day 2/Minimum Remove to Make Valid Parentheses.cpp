class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        // Vector to store the indices of the paranthesis to remove from the string
        vector<int> vc;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                vc.push_back(i);
            // If ')' comes after '(' then remove it otherwise push it
            else if (s[i] == ')')
            {
                if (!vc.empty() && s[vc.back()] == '(')
                    vc.pop_back();
                else
                    vc.push_back(i);
            }
        }

        // At the end, remove all the indices stored in the vector
        for (int i = vc.size() - 1; i >= 0; i--)
            s.erase(vc[i], 1);
        return s;
    }
};