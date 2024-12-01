#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int age;
    string major;
    float score;
};

bool compareByScoreAscending(const Student& student1, const Student& student2) {
    return student1.score < student2.score;
}

bool compareByScoreDescending(const Student& student1, const Student& student2) {
    return student1.score > student2.score;
}

void addStudent(vector<Student>& students) {
    int numStudents;
    cout << "Enter the number of students to add: ";
    cin >> numStudents;
    cin.ignore(); // Clear the newline character from the input buffer

    for (int i = 0; i < numStudents; ++i) {
        Student newStudent;
        cout << "Enter student name: ";
        getline(cin, newStudent.name);
        cout << "Enter student age: ";
        cin >> newStudent.age;
        cin.ignore(); // Clear the newline character from the input buffer
        cout << "Enter student major: ";
        getline(cin, newStudent.major);
        cout << "Enter student score: ";
        cin >> newStudent.score;
        cin.ignore(); // Clear the newline character from the input buffer

        students.push_back(newStudent);
    }

    cout << "Students added successfully!" << endl;
}

void displayStudents(const vector<Student>& students) {
    cout << "Student List:" << endl;
    for (const auto& student : students) {
        cout << "Name: " << student.name << endl;
        cout << "Age: " << student.age << endl;
        cout << "Major: " << student.major << endl;
        cout << "Score: " << student.score << endl;
        cout << "------------------------" << endl;
    }
}

void searchStudent(const vector<Student>& students) {
    string searchName;
    cout << "Enter the name of the student to search for: ";
    getline(cin, searchName);

    bool found = false;
    for (const auto& student : students) {
        if (student.name == searchName) {
            cout << "Student found:" << endl;
            cout << "Name: " << student.name << endl;
            cout << "Age: " << student.age << endl;
            cout << "Major: " << student.major << endl;
            cout << "Score: " << student.score << endl;
            cout << "------------------------" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Student not found." << endl;
    }
}

void sortStudentsAscending(vector<Student>& students) {
    sort(students.begin(), students.end(), compareByScoreAscending);
    cout << "Students sorted in ascending order by score." << endl;
}

void sortStudentsDescending(vector<Student>& students) {
    sort(students.begin(), students.end(), compareByScoreDescending);
    cout << "Students sorted in descending order by score." << endl;
}

int main() {
    vector<Student> students;
    int choice;

    while (true) {
        cout << "Student Management System" << endl;
        cout << "1. Add Student(s)" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Sort Students by Score (Ascending)" << endl;
        cout << "5. Sort Students by Score (Descending)" << endl;
        cout << "6. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the newline character from the input
    }
}
