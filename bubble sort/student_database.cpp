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

// Function to swap two students in the vector
void swap(Student& a, Student& b) {
    Student temp = a;
    a = b;
    b = temp;
}

// Bubble sort to arrange students by roll number in ascending order
void bubbleSort(vector<Student>& students) {
    int n = students.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].rollNo > students[j + 1].rollNo) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

int main() {
    vector<Student> students = {
        {1, "Alice", 9.5},
        {3, "Bob", 8.8},
        {2, "Charlie", 9.2},
        {5, "David", 8.5},
        {4, "Eve", 9.0}
    };

    // Sort students by roll number using bubble sort
    bubbleSort(students);

    // Print the roll call list
    cout << "Roll Call List:" << endl;
    for (const Student& student : students) {
        cout << "Roll No: " << student.rollNo << ", Name: " << student.name << ", SGPA: " << student.sgpa << endl;
    }

    return 0;
}
