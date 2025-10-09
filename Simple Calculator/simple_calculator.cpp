
#include <iostream>
#include <cmath>
using namespace std;

// This is my first calculator program!
int main() {
    int choice;
    double num1, num2;
    // I want to keep running until the user chooses to exit
    do {
        // Show menu
        cout << "\nCalculator Menu:\n";
        cout << "1. Add\n";
        cout << "2. Subtract\n";
        cout << "3. Multiply\n";
        cout << "4. Divide\n";
        cout << "5. Square Root\n";
        cout << "6. Power\n";
        cout << "7. Factorial\n";
        cout << "0. Exit\n";
        cout << "Choose an operation: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Please enter a number!" << endl;
            continue;
        }
        if (choice == 1) {
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Please enter numbers!" << endl;
                continue;
            }
            cout << "Result: " << (num1 + num2) << endl;
        } else if (choice == 2) {
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Please enter numbers!" << endl;
                continue;
            }
            cout << "Result: " << (num1 - num2) << endl;
        } else if (choice == 3) {
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Please enter numbers!" << endl;
                continue;
            }
            cout << "Result: " << (num1 * num2) << endl;
        } else if (choice == 4) {
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Please enter numbers!" << endl;
                continue;
            }
            if (num2 == 0) {
                cout << "Can't divide by zero!" << endl;
            } else {
                cout << "Result: " << (num1 / num2) << endl;
            }
        } else if (choice == 5) {
            cout << "Enter a number: ";
            cin >> num1;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Please enter a number!" << endl;
                continue;
            }
            if (num1 < 0) {
                cout << "Can't take square root of negative!" << endl;
            } else {
                cout << "Result: " << sqrt(num1) << endl;
            }
        } else if (choice == 6) {
            cout << "Enter base and exponent: ";
            cin >> num1 >> num2;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Please enter numbers!" << endl;
                continue;
            }
            cout << "Result: " << pow(num1, num2) << endl;
        } else if (choice == 7) {
            int n;
            cout << "Enter a non-negative integer: ";
            cin >> n;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Please enter an integer!" << endl;
                continue;
            }
            if (n < 0) {
                cout << "Can't do factorial of negative!" << endl;
            } else {
                unsigned long long result = 1;
                for (int i = 1; i <= n; i++) {
                    result = result * i;
                }
                cout << "Result: " << result << endl;
            }
        } else if (choice == 0) {
            cout << "Bye!" << endl;
        } else {
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);
    return 0;
}
