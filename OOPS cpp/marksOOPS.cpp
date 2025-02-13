#include <iostream>
using namespace std;

/* Base class: Student */
class Student {
public:
    int Regno;          // Student registration number
    char Name[20];      // Student name
    int Semester;       // Current semester
    char Branch[20];    // Branch of study

    /* Function to read student details */
    void GetData() {
        cout << "Enter Regno: ";
        cin >> Regno;
        cout << "Enter Name: ";
        cin >> Name;  // Will only accept a single word (fix: use gets() in Turbo C++)
        cout << "Enter Semester: ";
        cin >> Semester;
        cout << "Enter Branch: ";
        cin >> Branch;
    }
};

/* Derived class: Exams (inherits Student virtually) */
class Exams : public virtual Student {
public:
    int Marks1, Marks2, Marks3;  // Marks for 3 subjects

    /* Function to read exam marks */
    void GetMarks() {
        cout << "Enter Marks1: ";
        cin >> Marks1;
        cout << "Enter Marks2: ";
        cin >> Marks2;
        cout << "Enter Marks3: ";
        cin >> Marks3;
    }
};

/* Derived class: Sports (inherits Student virtually) */
class Sports : public virtual Student {
public:
    char Sports_grade;  // Grade in sports

    /* Function to read sports grade */
    void GetSports() {
        cout << "Enter Sports Grade: ";
        cin >> Sports_grade;
    }
};

/* Derived class: Awards (inherits from Exams and Sports) */
class Awards : public Exams, public Sports {
public:
    /* Function to display student details along with marks and sports grade */
    void Display() {
        cout << "\n=== Student Details ===\n";
        cout << "Name: " << Student::Name << endl;
        cout << "Regno: " << Student::Regno << endl;
        cout << "Branch: " << Student::Branch << endl;

        cout << "\n=== Exam Details ===\n";
        cout << "Semester: " << Exams::Semester << endl;
        cout << "Marks1: " << Marks1 << endl;
        cout << "Marks2: " << Marks2 << endl;
        cout << "Marks3: " << Marks3 << endl;

        cout << "\n=== Sports Details ===\n";
        cout << "Semester: " << Sports::Semester << endl;
        cout << "Sports Grade: " << Sports_grade << endl;
    }
};

/* Main function */
int main() {
    Awards a1;

    // Read student, exam, and sports details
    a1.GetData();
    a1.GetMarks();
    a1.GetSports();

    // Display all details
    a1.Display();

    return 0;
}
