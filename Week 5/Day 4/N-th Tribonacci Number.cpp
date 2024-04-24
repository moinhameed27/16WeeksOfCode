// Way - I (Recursion + Memoization)
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

// Way - II (Bottom - Up Approach)
class Solution {
public:
    int tribonacci(int n) {
        int t[38];
        t[0] = 0;
        t[1] = 1;
        t[2] = 1;
        
        for(int i = 3; i <=n; i++)
            t[i] = t[i - 1] + t[i - 2] + t[i - 3];
        
        return t[n];
    }
};

// Way - III (Constant Space)
class Solution {
public:
    int tribonacci(int n) {
        if(n == 0)
            return 0;
        if(n == 1 || n == 2)
            return 1;
        
        int a = 0, b = 1, c = 1;
        int d;
        for(int i = 3; i <=n; i++)
        {
            d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return d;
    }
};
