class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int unableToEat = 0;

        while (!students.empty())
        {
            // If student's prefernce matches with the sandwich, erase both and reset the counter
            if (students[0] == sandwiches[0])
            {
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
                unableToEat = 0;
            }
            else
            {
                // If preference doesn't match, left rotate the array(student goes to the end of line) and increase the counter
                rotate(students.begin(), students.begin() + 1, students.end());
                unableToEat++;
            }

            // If all students have moved to the end of the line without eating, exit the loop
            if (unableToEat == students.size())

                break;
        }
        return unableToEat;
    }
};
