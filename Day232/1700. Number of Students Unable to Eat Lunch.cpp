class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count0 = count(students.begin(), students.end(), 0);
        int count1 = students.size() - count0;

        for (int s : sandwiches) {
            if (s == 0) {
                if (count0 == 0) return count1;
                count0--;
            } else {
                if (count1 == 0) return count0; 
                count1--;
            }
        }
        return 0;
    }
};