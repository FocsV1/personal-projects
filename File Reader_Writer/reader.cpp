#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to write data to a file
void writeToFile(const string& filename, const string& data) {
    ofstream outFile(filename);
    
    if (outFile.is_open()) {
        outFile << data;
        outFile.close();
        cout << "Data successfully written to " << filename << endl;
    } else {
        cout << "Error: Unable to open file " << filename << " for writing." << endl;
    }
}

// Function to read data from a file
string readFromFile(const string& filename) {
    ifstream inFile(filename);
    string content;
    string line;
    
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            content += line + "\n";
        }
        inFile.close();
        cout << "Data successfully read from " << filename << endl;
        return content;
    } else {
        cout << "Error: Unable to open file " << filename << " for reading." << endl;
        return "";
    }
}

// Function to append data to an existing file
void appendToFile(const string& filename, const string& data) {
    ofstream outFile(filename, ios::app);
    
    if (outFile.is_open()) {
        outFile << data;
        outFile.close();
        cout << "Data successfully appended to " << filename << endl;
    } else {
        cout << "Error: Unable to open file " << filename << " for appending." << endl;
    }
}

// Function to display menu options
void displayMenu() {
    cout << "\n=== Simple File Reader/Writer ===" << endl;
    cout << "1. Write to file" << endl;
    cout << "2. Read from file" << endl;
    cout << "3. Append to file" << endl;
    cout << "4. Exit" << endl;
    cout << "Choose an option (1-4): ";
}

int main() {
    string filename;
    string data;
    int choice;
    
    cout << "Welcome to Simple File Reader/Writer!" << endl;
    cout << "Enter filename to work with: ";
    getline(cin, filename);
    
    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Clear the input buffer
        
        switch (choice) {
            case 1: {
                cout << "Enter data to write to file: ";
                getline(cin, data);
                writeToFile(filename, data);
                break;
            }
            case 2: {
                string content = readFromFile(filename);
                if (!content.empty()) {
                    cout << "\nFile contents:" << endl;
                    cout << "=================" << endl;
                    cout << content << endl;
                    cout << "=================" << endl;
                }
                break;
            }
            case 3: {
                cout << "Enter data to append to file: ";
                getline(cin, data);
                appendToFile(filename, data + "\n");
                break;
            }
            case 4: {
                cout << "Goodbye!" << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please select 1-4." << endl;
                break;
            }
        }
    } while (choice != 4);
    
    return 0;
}