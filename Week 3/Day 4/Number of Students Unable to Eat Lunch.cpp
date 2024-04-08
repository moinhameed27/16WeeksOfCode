// Way - I --> Built in Functions (Rotate and Erase)
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

// Way - II (Counter)
class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int n = students.size();
        int arr[2] = {0};
        // arr[0] = Count of students who like circular sandwiches
        // arr[1] = Count of students who like square sandwiches

        // Counting the students according to their preference
        for (int x : students)
            arr[x]++;
    
        // Traversing the sandwiches array, decrementing the sandwiches according to preference and if there are no students of such
        // preference then return the remaining students because there's no one who can remove that sandwich from the top of stack
        for (int i = 0; i < n; i++)
        {
            if (arr[sandwiches[i]] == 0)
                return n - i;
            arr[sandwiches[i]]--;
        }

        return 0;
    }
};
