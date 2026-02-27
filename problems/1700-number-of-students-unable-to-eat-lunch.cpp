// problem: 1700 number of students unable to eat lunch
// difficulty: easy
// studysets: dsa-quest, queue
// url: https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/
// tags: queue, simulation, array
#include <vector>
using std::vector;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int iter = 0;
        while (students.size() > 0 && iter < students.size()) {
            if (students[0] == sandwiches[0]) {
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
                iter = 0;
            } else {
                int temp = students[0];
                students.erase(students.begin());
                students.push_back(temp);
                iter++;
            }
        }
        return students.size();
    }
};

/*
// zero one counting

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zeros = 0;
        int ones = 0;

        for (int s : students) {
            if (s == 0) ++zeros;
            else ++ones;
        }

        for (int s : sandwiches) {
            if (s == 0) {
                if (zeros == 0) return ones;
                --zeros;
            } else {
                if (ones == 0) return zeros;
                --ones;
            }
        }

        return 0;
    }
};

*/
