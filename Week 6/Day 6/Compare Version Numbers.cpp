class Solution
{
    // Function to break whole string into tokens by using delimeter '.'
    vector<string> getTokens(string version)
    {
        stringstream ss(version);

        string token = "";
        vector<string> tokens;

        // Getting each token with respect to '.' and pushing it in tokens vector
        while (getline(ss, token, '.'))
            tokens.push_back(token);

        return tokens;
    }

public:
    int compareVersion(string version1, string version2)
    {
        // Converting both strings to vector of token strings
        vector<string> v1 = getTokens(version1);
        vector<string> v2 = getTokens(version2);

        int m = v1.size(), n = v2.size();
        int i = 0;

        // Loop should keep going until both strings are traversed
        while (i < m || i < n)
        {
            // If one vector ends, take it's next value as 0
            int a = i < m ? stoi(v1[i]) : 0;
            int b = i < n ? stoi(v2[i]) : 0;

            if (a < b)
                return -1;
            else if (a > b)
                return 1;
            else
                i++;    // Equal case
        }
        return 0;
    }
};