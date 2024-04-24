/*
Simple Recursion solution can run on small test cases but it isn't accepted on leetcode for bigger test cases.
So we have to do memoization before submitting it.
*/

class Solution {
public:
    // Maximum constraint is 2^37 so taking array of 38 elements
    int t[38];
    
    int findTribonacci(int n)
    {
        if(n == 0)
            return 0;
        if(n == 1 || n == 2)
            return 1;
        
        // If result is already stored in array, use that
        if(t[n] != -1)
            return t[n];
        
        int a = findTribonacci(n - 1);
        int b = findTribonacci(n - 2);
        int c = findTribonacci(n - 3);
        
        // Else store every result in the array
        return t[n] =  a + b + c;
    }
    
    int tribonacci(int n) {
        memset(t, -1, sizeof(t));
        return findTribonacci(n);
    }
};