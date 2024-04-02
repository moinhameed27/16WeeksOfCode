class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        // mp1 for the mapping of s[i] --> t[i]
        unordered_map<char, char> mp1;
        // mp2 for the mapping of t[i] -- > s[i]
        unordered_map<char, char> mp2;

        int size = s.size();    // Size is same of both strings

        for (int i = 0; i < size; i++)
        {
            char ch1 = s[i];
            char ch2 = t[i];

            // If ch1 is already mapped but to any other character than ch2 
            // OR
            // If ch2 is already mapped but to any other charcter than ch1
            if (mp1.find(ch1) != mp1.end() && mp1[ch1] != ch2 || mp2.find(ch2) != mp2.end() && mp2[ch2] != ch1)
                return false;
            
            // If not mapped already, map them
            mp1[ch1] = ch2;
            mp2[ch2] = ch1;
        }
        return true;
    }
};