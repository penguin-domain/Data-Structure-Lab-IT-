#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    int rollNo;
    string name;
    float sgpa;
};

void searchBySGPA(const vector<Student>& students, float targetSGPA) {
    bool found = false;
    cout << "Students with SGPA " << targetSGPA << ":" << endl;

    for (const Student& student : students) {
        if (student.sgpa == targetSGPA) {
            cout << "Roll No: " << student.rollNo << ", Name: " << student.name << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No students found with SGPA " << targetSGPA << endl;
    }
}

int main() {
    vector<Student> students = {
        {1, "Alice", 9.5},
        {3, "Bob", 8.8},
        {2, "Charlie", 9.2},
        {5, "David", 8.5},
        {4, "Eve", 9.0},
        {6, "Fred", 9.5} // Another student with the same SGPA as Alice
    };

    float targetSGPA;
    cout << "Enter the SGPA to search for: ";
    cin >> targetSGPA;

    searchBySGPA(students, targetSGPA);

    return 0;
}
