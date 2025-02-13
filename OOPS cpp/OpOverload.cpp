#include <iostream>
#include <conio.h>
#include <process.h>
using namespace std;

/* Class representing a Date */
class date {
    int ag, dd, mm, yy;  // ag: Leap year flag, dd: Day, mm: Month, yy: Year

public:
    /* Constructor to initialize date and check for leap year */
    date(int d, int m, int y) {
        dd = d;
        mm = m;
        yy = y;

        // Check if the year is a leap year
        if ((y % 4) == 0)
            ag = 1;
        else {
            ag = 0;
            // If February and day > 28 in a non-leap year, exit with error
            if (m == 2 && d > 28) {
                cout << "Error since not a leap year";
                getch();
                exit(0);
            }
        }
    }

    /* Member functions */
    int return_date(date d);  // Returns the number of days passed in the year
    int operator-(date d2);   // Overloaded - operator to find the difference between two dates
    date operator+(int n);    // Overloaded + operator to add days to a date

    /* Friend function to output the date */
    friend ostream& operator<<(ostream& out, date d1);
};

/* Array containing the number of days in each month */
int a[20] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/* Overloaded - operator: calculates the difference between two dates */
int date::operator-(date d2) {
    int a1, a2, x = 0;
    date d1(dd, mm, yy); // Copying the current date

    // Validate that d1 (current date) is greater than d2
    if (d1.yy < d2.yy || (d1.yy == d2.yy && d1.mm < d2.mm) || (d1.yy == d2.yy && d1.mm == d2.mm && d1.dd < d2.dd)) {
        cout << "Error: Second date is greater than first date";
        getch();
        exit(0);
    }

    // Get the day number within the year for both dates
    a1 = return_date(d1);
    a2 = return_date(d2);

    // Add days from full years in between
    for (int i = d2.yy; i < d1.yy; i++) {
        x += (i % 4 == 0) ? 366 : 365;
    }

    // Add the difference of days within the same year
    x += a1 - a2;

    return x;
}

/* Function to calculate the total number of days passed in the year */
int date::return_date(date d) {
    int int_val = d.dd;  // Start with the current day
    for (int i = 0; i < d.mm; i++)
        int_val += a[i]; // Sum days from previous months

    // If it's a leap year and the month is after February, add an extra day
    if (d.ag == 1 && d.mm > 2)
        int_val++; 

    return int_val;
}

/* Overloaded + operator: Adds days to a date */
date date::operator+(int n) {
    date d(dd, mm, yy); // Copy current date
    for (int i = 0; i < n; i++) {
        d.dd++;
        
        // Get the number of days in the current month (handle leap year case for February)
        int days_in_month = (d.mm == 2 && d.yy % 4 == 0) ? 29 : a[d.mm];

        // Move to the next month if the days exceed the limit
        if (d.dd > days_in_month) {
            d.dd = 1;
            d.mm++;
        }
        
        // Move to the next year if the month exceeds December
        if (d.mm > 12) {
            d.mm = 1;
            d.yy++;
        }
    }
    return d;
}

/* Friend function to output the date */
ostream& operator<<(ostream& out, date d1) {
    out << d1.dd << "-" << d1.mm << "-" << d1.yy;
    return out;
}

/* Main function */
int main() {
    int d, m, y, no_of_days;

    // Take first date input
    cout << "Enter a valid date (dd mm yyyy): ";
    cin >> d >> m >> y;

    // Validate input date
    if (d > ((m == 2 && y % 4 == 0) ? 29 : a[m]) || m > 12) {
        cout << "Error: Invalid date";
        getch();
        exit(0);
    }

    date d1(d, m, y);  // Create first date object

    // Take second date input
    cout << "Enter a valid date which is lesser than the first date: ";
    cin >> d >> m >> y;

    // Validate input date
    if (d > ((m == 2 && y % 4 == 0) ? 29 : a[m]) || m > 12) {
        cout << "Error: Invalid date";
        getch();
        exit(0);
    }

    date d2(d, m, y);  // Create second date object

    // Calculate and display difference between two dates
    no_of_days = d1 - d2;
    cout << "Difference between two dates in days: " << no_of_days << endl;

    // Take input for days to be added
    cout << "Enter number of days to be added to the first date: ";
    cin >> no_of_days;

    // Add days and display new date
    d1 = d1 + no_of_days;
    cout << "The new date is: " << d1 << endl;

    getch(); // Pause the console (for Turbo C++)
    return 0;
}
