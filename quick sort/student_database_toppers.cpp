#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    int rollNo;
    string name;
    float sgpa;
};

// Function to partition the array for quick sort
int partition(vector<Student>& students, int low, int high) {
    float pivot = students[high].sgpa;
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        if (students[j].sgpa >= pivot) {
            i++; 
            swap(students[i], students[j]);
        }
    }
    swap(students[i + 1], students[high]);
    return (i + 1);
}

// Quick sort function to arrange students by SGPA in descending order
void quickSort(vector<Student>& students, int low, int high) {
    if (low < high) {
        int pi = partition(students, low, high); 
        quickSort(students, low, pi - 1); 
        quickSort(students, pi + 1, high);
    }
}

int main() {
    vector<Student> students = {
        {1, "Alice", 9.5},
        {3, "Bob", 8.8},
        {2, "Charlie", 9.2},
        {5, "David", 8.5},
        {4, "Eve", 9.0},
        // Add more students here
    };

    // Sort students by SGPA in descending order using quick sort
    quickSort(students, 0, students.size() - 1);

    // Print the top 10 toppers
    cout << "Top 10 Toppers:" << endl;
    for (int i = 0; i < min(10, (int)students.size()); i++) {
        cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name << ", SGPA: " << students[i].sgpa << endl;
    }

    return 0;
}
