#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>
#include <string>

using namespace std;

enum class Operation {
    EXIT = 0,
    ADD = 1,
    SUBTRACT = 2,
    MULTIPLY = 3,
    DIVIDE = 4,
    SQUARE_ROOT = 5,
    POWER = 6,
    FACTORIAL = 7
};

class Calculator {
private:
    static constexpr int PRECISION = 6;

    void clearInputStream() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Get a double from user input, with validation
    bool getDoubleInput(double& value, const string& prompt) {
        cout << prompt;
        if (cin >> value) {
            return true;
        }
        clearInputStream();
        cout << "Error: Invalid input. Please enter a valid number.\n";
        return false;
    }

    bool getIntegerInput(int& value, const string& prompt) {
        cout << prompt;
        if (cin >> value) {
            return true;
        }
        clearInputStream();
        cout << "Error: Invalid input. Please enter a valid integer.\n";
        return false;
    }

    void displayResult(double result) {
        cout << fixed << setprecision(PRECISION);
        cout << "\n======================================\n";
        cout << "  Result: " << result << "\n";
        cout << "======================================\n";
    }

    void displayError(const string& message) {
        cout << "\n⚠ Error: " << message << "\n";
    }

    double add(double a, double b) {
        return a + b;
    }

    double subtract(double a, double b) {
        return a - b;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    double divide(double a, double b) {
        if (b == 0) {
            throw runtime_error("Division by zero is undefined.");
        }
        return a / b;
    }

    double squareRoot(double a) {
        if (a < 0) {
            throw runtime_error("Square root of negative number is undefined.");
        }
        return sqrt(a);
    }

    double power(double base, double exponent) {
        return pow(base, exponent);
    }

    unsigned long long factorial(int n) {
        if (n < 0) {
            throw runtime_error("Factorial of negative number is undefined.");
        }
        if (n > 20) {
            throw runtime_error("Factorial overflow. Maximum input is 20.");
        }
        unsigned long long result = 1;
        for (int i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }

    // This function uses a member function pointer to generalize binary operations (add, subtract, etc.)
    void performBinaryOperation(double (Calculator::*operation)(double, double)) {
        double num1, num2;
        if (getDoubleInput(num1, "Enter first number: ") && 
            getDoubleInput(num2, "Enter second number: ")) {
            try {
                double result = (this->*operation)(num1, num2);
                // If the result is too large or not a number, inform the user
                if (!isfinite(result)) {
                    displayError("Result is too large or undefined.");
                } else {
                    displayResult(result);
                }
            } catch (const runtime_error& e) {
                displayError(e.what());
            }
        }
    }

    // Handles operations that require only one input (e.g., square root)
    void performUnaryOperation() {
        double num;
        if (getDoubleInput(num, "Enter number: ")) {
            try {
                double result = squareRoot(num);
                displayResult(result);
            } catch (const runtime_error& e) {
                displayError(e.what());
            }
        }
    }

    // Handles the power operation, checks for overflow
    void performPowerOperation() {
        double base, exponent;
        if (getDoubleInput(base, "Enter base: ") && 
            getDoubleInput(exponent, "Enter exponent: ")) {
            double result = power(base, exponent);
            // Check for overflow or undefined result
            if (!isfinite(result)) {
                displayError("Result is too large or undefined.");
            } else {
                displayResult(result);
            }
        }
    }

    // Factorial can easily overflow, so we catch errors and limit input
    void performFactorialOperation() {
        int n;
        if (getIntegerInput(n, "Enter non-negative integer: ")) {
            try {
                unsigned long long result = factorial(n);
                cout << fixed << setprecision(0);
                cout << "\n======================================\n";
                cout << "  Result: " << result << "\n";
                cout << "======================================\n";
            } catch (const runtime_error& e) {
                displayError(e.what());
            }
        }
    }

    void displayMenu() {
        cout << "\n======================================\n";
        cout << "|      ADVANCED CALCULATOR v1.0      |\n";
        cout << "|------------------------------------|\n";
        cout << "|  1. Addition                       |\n";
        cout << "|  2. Subtraction                    |\n";
        cout << "|  3. Multiplication                 |\n";
        cout << "|  4. Division                       |\n";
        cout << "|  5. Square Root                    |\n";
        cout << "|  6. Power                          |\n";
        cout << "|  7. Factorial                      |\n";
        cout << "|  0. Exit                           |\n";
        cout << "======================================\n";
    }

    int getUserChoice() {
        int choice;
        cout << "\nSelect operation: ";
        if (cin >> choice) {
            return choice;
        }
        clearInputStream();
        return -1;
    }

public:
    void run() {
        int choice;
        bool running = true;

        while (running) {
            displayMenu();
            choice = getUserChoice();

            switch (static_cast<Operation>(choice)) {
                case Operation::ADD:
                    performBinaryOperation(&Calculator::add);
                    break;
                case Operation::SUBTRACT:
                    performBinaryOperation(&Calculator::subtract);
                    break;
                case Operation::MULTIPLY:
                    performBinaryOperation(&Calculator::multiply);
                    break;
                case Operation::DIVIDE:
                    performBinaryOperation(&Calculator::divide);
                    break;
                case Operation::SQUARE_ROOT:
                    performUnaryOperation();
                    break;
                case Operation::POWER:
                    performPowerOperation();
                    break;
                case Operation::FACTORIAL:
                    performFactorialOperation();
                    break;
                case Operation::EXIT:
                    cout << "\nThank you for using Advanced Calculator. Goodbye!\n";
                    running = false;
                    break;
                default:
                    displayError("Invalid choice. Please select a valid operation.");
                    break;
            }
        }
    }
};

int main() {
    Calculator calculator;
    calculator.run();
    return 0;
}