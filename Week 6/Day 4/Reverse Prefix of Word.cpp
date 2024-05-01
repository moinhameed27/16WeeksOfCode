class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0, j = 0;
        int n = word.size();
        
        // Finding the index of the target character
        while(j < n && word[j] != ch)
            j++;
        
        // If character is not present in the string, return word as it is
        if(j == n)
            return word;
        
        // Reverse the string from index 0 to character index
        while(i < j)
        {
            swap(word[i], word[j]);
            i++;
            j--;
        }
        
        return word;
    }
};