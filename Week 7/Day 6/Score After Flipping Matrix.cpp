// Way - I (Modifying Input)
class Solution
{
public:
    int matrixScore(vector<vector<int>> &grid)
    {
        int m = grid.size();    // Rows
        int n = grid[0].size(); // Cols

        // Flipping entire row if MSB is 0
        for (int i = 0; i < m; i++)
        {
            if (grid[i][0] == 0)
            {
                for (int j = 0; j < n; j++)
                    grid[i][j] = 1 - grid[i][j];
            }
        }

        // Flipping entire column if number of zeros in the col are greater than number of ones
        for (int j = 1; j < n; j++)
        {
            int countZeros = 0;
            for (int i = 0; i < m; i++)
            {
                if (grid[i][j] == 0)
                    countZeros++;
            }
            int countOnes = m - countZeros;
            if (countOnes < countZeros)
            {
                for (int i = 0; i < m; i++)
                {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        // Calculating score by adding score of each row
        int score = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                score += grid[i][j] * pow(2, n - j - 1);
            }
        }
        return score;
    }
};


// Way - II (Without Modifying Input)
class Solution
{
public:
    int matrixScore(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // Score of first column as it will always contain Ones
        int score = pow(2, n - 1) * m;

        // Column Processing
        for (int j = 1; j < n; j++)
        {
            int countOnes = 0;
            for (int i = 0; i < m; i++)
            {
                // Checking with respect to first element of row if current element is flipped or not
                if (grid[i][j] != grid[i][0])
                    countOnes++;
            }

            int countZeros = m - countOnes;

            // Flip Case : If number of zeros are greater
            int ones = max(countOnes, countZeros);

            // Multipy current significant bit with number of ones in that column
            score += pow(2, n - j - 1) * ones;
        }
        return score;
    }
};