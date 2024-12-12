#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    int rollNo;
    string name;
    float sgpa;
};

// Function to insert a student into the sorted portion of the vector
void insert(vector<Student>& students, int i) {
    Student key = students[i];
    int j = i - 1;

    // Move elements of students[0..i-1], that are greater than key, 
    // to one position ahead of their current position 
    while (j >= 0 && students[j].name > key.name) {
        students[j + 1] = students[j];
        j = j - 1;
    }
    students[j + 1] = key;
}

// Insertion sort to arrange students by name in ascending order
void insertionSort(vector<Student>& students) {
    int n = students.size();
    for (int i = 1; i < n; i++) {
        insert(students, i);
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

    // Sort students by name using insertion sort
    insertionSort(students);

    // Print the list of students
    cout << "List of Students:" << endl;
    for (const Student& student : students) {
        cout << "Roll No: " << student.rollNo << ", Name: " << student.name << ", SGPA: " << student.sgpa << endl;
    }

    return 0;
}
