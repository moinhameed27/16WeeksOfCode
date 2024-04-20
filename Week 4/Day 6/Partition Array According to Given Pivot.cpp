/* Take 3 arrays and store elements in them according to their order. At the end push all the elements in the
answer array by sequence from small - equal - large
*/

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> small, equal, large, ans;
        for(int i : nums )
        {
            if(i < pivot)
                small.push_back(i);
            else if(i == pivot)
                equal.push_back(i);
            else 
                large.push_back(i);
        }
        
        // Storing back elements in Answer array by respective sequence
        for(int i : small)
            ans.push_back(i);
        
        for(int i : equal)
            ans.push_back(i);
        
        for(int i : large)
            ans.push_back(i);
        
        return ans;
    }
};
