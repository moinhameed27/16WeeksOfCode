class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        // Loose Constraints (Nested Loop can work)
        // Sorting the Names array with respect to heights array
        for(int i = 1; i < names.size(); i++)
        {
            for(int j = 0; j < names.size() - 1; j++)
            {
                if(heights[j] < heights[j + 1])
                {
                    swap(heights[j], heights[j + 1]);
                    swap(names[j], names[j + 1]);
                }
            }
        }
        return names;
    }
};








