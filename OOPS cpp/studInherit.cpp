#include <iostream>
using namespace std;

/* Base class: student */
class student {
public:
    int reg, age;
    char name[20];

    /* Function to read student details */
    void read_data();
};

/* Derived class: UG Student */
class ugstudent : public student {
public:
    int stipend, sem;
    float fees; 

    /* Function to read UG student details */
    void read_data();
};

/* Derived class: PG Student */
class pgstudent : public student {
public:
    int stipend, sem;
    float fees; 

    /* Function to read PG student details */
    void read_data();
};

/* Function to read student details */
void student::read_data() {
    cout << "\nEnter name: ";
    cin >> name;
    cout << "\nEnter Reg. No.: ";
    cin >> reg;
    cout << "\nEnter age: ";
    cin >> age;
}

/* Function to read UG student details */
void ugstudent::read_data() {
    student::read_data(); // Call base class function
    cout << "\nEnter the semester: ";
    cin >> sem;
    cout << "\nEnter the fees: ";
    cin >> fees;
    cout << "\nEnter the stipend: ";
    cin >> stipend;
}

/* Function to read PG student details */
void pgstudent::read_data() {
    student::read_data(); // Call base class function
    cout << "\nEnter the semester: ";
    cin >> sem;
    cout << "\nEnter the fees: ";
    cin >> fees;
    cout << "\nEnter the stipend: ";
    cin >> stipend;
}

/* Main function */
int main() {
    ugstudent ug[20];  // Array to store UG students
    pgstudent pg[20];  // Array to store PG students

    int i, n, m;
    float average; // Fixed 'oat' to 'float'

    /* Read UG student data */
    cout << "\nEnter the number of UG students: ";
    cin >> n;

    for (i = 0; i < n; i++) {
        cout << "\nEnter details for UG Student " << i + 1 << ":";
        ug[i].read_data();
    }

    /* Compute average age for UG students per semester */
    for (int sem = 1; sem <= 8; sem++) {
        float sum = 0;
        int found = 0, count = 0;

        for (i = 0; i < n; i++) {
            if (ug[i].sem == sem) {
                sum += ug[i].age;
                found = 1;
                count++;
            }
        }

        if (found == 1) {
            average = sum / count;
            cout << "\nAverage age of UG students in semester " << sem << " is " << average;
        }
    }

    /* Read PG student data */
    cout << "\n\nEnter the number of PG students: ";
    cin >> m;

    for (i = 0; i < m; i++) {
        cout << "\nEnter details for PG Student " << i + 1 << ":";
        pg[i].read_data();
    }

    /* Compute average age for PG students per semester */
    for (int sem = 1; sem <= 8; sem++) {
        float sum = 0;
        int found = 0, count = 0;

        for (i = 0; i < m; i++) {
            if (pg[i].sem == sem) {
                sum += pg[i].age;
                found = 1;
                count++;
            }
        }

        if (found == 1) {
            average = sum / count;
            cout << "\nAverage age of PG students in semester " << sem << " is " << average;
        }
    }

    return 0;
}
