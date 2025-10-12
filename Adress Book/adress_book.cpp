#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_CONTACTS = 100;

struct Contact {
    string name;
    string phone;
    string email;
};

class AddressBook {
private:
    Contact contacts[MAX_CONTACTS];
    int count;
public:
    AddressBook() : count(0) {}

    void addContact(const string& name, const string& phone, const string& email) {
        if (count < MAX_CONTACTS) {
            contacts[count].name = name;
            contacts[count].phone = phone;
            contacts[count].email = email;
            count++;
            cout << "Contact added!" << endl;
        } else {
            cout << "Address book is full!" << endl;
        }
    }

    void displayContacts() const {
        cout << "\nContacts List:" << endl;
        for (int i = 0; i < count; ++i) {
            cout << i + 1 << ". Name: " << contacts[i].name
                 << ", Phone: " << contacts[i].phone
                 << ", Email: " << contacts[i].email << endl;
        }
    }

    void saveToFile(const string& filename) const {
        ofstream out(filename);
        for (int i = 0; i < count; ++i) {
            out << contacts[i].name << ',' << contacts[i].phone << ',' << contacts[i].email << '\n';
        }
        out.close();
        cout << "Contacts saved to file." << endl;
    }

    void loadFromFile(const string& filename) {
        ifstream in(filename);
        string line;
        count = 0;
        while (getline(in, line) && count < MAX_CONTACTS) {
            size_t pos1 = line.find(',');
            size_t pos2 = line.rfind(',');
            if (pos1 != string::npos && pos2 != string::npos && pos1 != pos2) {
                contacts[count].name = line.substr(0, pos1);
                contacts[count].phone = line.substr(pos1 + 1, pos2 - pos1 - 1);
                contacts[count].email = line.substr(pos2 + 1);
                count++;
            }
        }
        in.close();
        cout << "Contacts loaded from file." << endl;
    }
};

int main() {
    AddressBook book;
    int choice;
    string name, phone, email, filename = "contacts.txt";

    book.loadFromFile(filename);

    do {
        cout << "\n1. Add Contact\n2. Display Contacts\n3. Save to File\n4. Exit\nChoose an option: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter phone: ";
                getline(cin, phone);
                cout << "Enter email: ";
                getline(cin, email);
                book.addContact(name, phone, email);
                break;
            case 2:
                book.displayContacts();
                break;
            case 3:
                book.saveToFile(filename);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option!" << endl;
        }
    } while (choice != 4);

    return 0;
}
