// Way - I (String conversion)
class Solution
{
public:
    int maximum69Number(int num)
    {
        string s = to_string(num);
        for (char &ch : s)
        {
            if (ch == '6')
            {
                ch = '9';
                break;
            }
        }

        return stoi(s);
    }
};

// Way - II (Place Value)
class Solution
{
public:
    int maximum69Number(int num)
    {
        int i = 0;
        int placeValueSix = -1;
        int temp = num;

        while (temp > 0)
        {
            int rem = temp % 10;

            // If remainder is six, update place Value of Six
            if (rem == 6)
                placeValueSix = i;

            i++;
            temp /= 10;
        }

        // If there's no six in the number
        if (placeValueSix == -1)
            return num;

        // Adding 3 * 10^placevalue of nearest starting 6 to num
        return num + 3 * pow(10, placeValueSix);
    }
};
