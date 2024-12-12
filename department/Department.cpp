#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    int rollNo;
    string name;
    string division;
    string address;
};

void addStudent(const string& filename) {
    ofstream fout(filename, ios::app | ios::binary);
    if (!fout) {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }

    Student student;
    cout << "Enter Roll No: ";
    cin >> student.rollNo;
    cin.ignore(); // Clear newline character
    cout << "Enter Name: ";
    getline(cin, student.name);
    cout << "Enter Division: ";
    getline(cin, student.division);
    cout << "Enter Address: ";
    getline(cin, student.address);

    fout.write(reinterpret_cast<const char*>(&student), sizeof(student));
    fout.close();

    cout << "Student record added successfully." << endl;
}

void deleteStudent(const string& filename, int rollNo) {
    ifstream fin(filename, ios::binary);
    if (!fin) {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }

    ofstream fout("temp.dat", ios::binary);
    if (!fout) {
        cerr << "Error: Unable to create temporary file." << endl;
        fin.close();
        return;
    }

    Student student;
    bool found = false;

    while (fin.read(reinterpret_cast<char*>(&student), sizeof(student))) {
        if (student.rollNo != rollNo) {
            fout.write(reinterpret_cast<const char*>(&student), sizeof(student));
        } else {
            found = true;
        }
    }

    fin.close();
    fout.close();

    remove(filename.c_str());
    rename("temp.dat", filename.c_str());

    if (found) {
        cout << "Student record with Roll No " << rollNo << " deleted successfully." << endl;
    } else {
        cout << "Student record with Roll No " << rollNo << " not found." << endl;
    }
}

void displayStudent(const string& filename, int rollNo) {
    ifstream fin(filename, ios::binary);
    if (!fin) {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }

    Student student;
    bool found = false;

    while (fin.read(reinterpret_cast<char*>(&student), sizeof(student))) {
        if (student.rollNo == rollNo) {
            cout << "Roll No: " << student.rollNo << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            found = true;
            break; 
        }
    }

    fin.close();

    if (!found) {
        cout << "Student record with Roll No " << rollNo << " not found." << endl;
    }
}

int main() {
    string filename = "students.dat"; 
    int choice, rollNo;

    do {
        cout << "\n1. Add Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Display Student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(filename);
                break;
            case 2:
                cout << "Enter Roll No to delete: ";
                cin >> rollNo;
                deleteStudent(filename, rollNo);
                break;
            case 3:
                cout << "Enter Roll No to display: ";
                cin >> rollNo;
                displayStudent(filename, rollNo);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 4);

    return 0;
}
