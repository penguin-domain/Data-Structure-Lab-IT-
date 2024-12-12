#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    int rollNo;
    string name;
    float sgpa;
};

// Function to compare students based on their names
bool compareStudentsByName(const Student& a, const Student& b) {
    return a.name < b.name;
}

// Binary search to find a student by name (iterative version)
int binarySearchByName(const vector<Student>& students, const string& targetName) {
    int left = 0;
    int right = students.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (students[mid].name == targetName) {
            return mid; // Student found
        } else if (students[mid].name < targetName) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Student not found
}

int main() {
    vector<Student> students = {
        {1, "Alice", 9.5},
        {3, "Bob", 8.8},
        {2, "Charlie", 9.2},
        {5, "David", 8.5},
        {4, "Eve", 9.0}
    };

    // Sort students by name for binary search
    sort(students.begin(), students.end(), compareStudentsByName);

    string targetName;
    cout << "Enter the name of the student to search for: ";
    cin >> targetName;

    int index = binarySearchByName(students, targetName);

    if (index != -1) {
        cout << "Student Found:" << endl;
        cout << "Roll No: " << students[index].rollNo << ", Name: " << students[index].name << ", SGPA: " << students[index].sgpa << endl;
    } else {
        cout << "Student Not Found" << endl;
    }

    return 0;
}
