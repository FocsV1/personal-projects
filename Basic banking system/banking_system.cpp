#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

public:
    // Constructor
    BankAccount(const std::string& accNum, const std::string& name, double initialBalance = 0.0) 
        : accountNumber(accNum), accountHolderName(name), balance(initialBalance) {
        if (initialBalance < 0) {
            balance = 0.0;
            std::cout << "Warning: Initial balance cannot be negative. Set to $0.00\n";
        }
    }

    // Getter methods
    std::string getAccountNumber() const { return accountNumber; }
    std::string getAccountHolderName() const { return accountHolderName; }
    double getBalance() const { return balance; }

    // Deposit money
    bool deposit(double amount) {
        if (amount <= 0) {
            std::cout << "Error: Deposit amount must be positive!\n";
            return false;
        }
        balance += amount;
        std::cout << "Successfully deposited $" << std::fixed << std::setprecision(2) 
                  << amount << " to account " << accountNumber << "\n";
        return true;
    }

    // Withdraw money
    bool withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "Error: Withdrawal amount must be positive!\n";
            return false;
        }
        if (amount > balance) {
            std::cout << "Error: Insufficient funds! Current balance: $" 
                      << std::fixed << std::setprecision(2) << balance << "\n";
            return false;
        }
        balance -= amount;
        std::cout << "Successfully withdrew $" << std::fixed << std::setprecision(2) 
                  << amount << " from account " << accountNumber << "\n";
        return true;
    }

    // Check balance
    void checkBalance() const {
        std::cout << "\n--- Account Balance ---\n";
        std::cout << "Account Number: " << accountNumber << "\n";
        std::cout << "Account Holder: " << accountHolderName << "\n";
        std::cout << "Current Balance: $" << std::fixed << std::setprecision(2) << balance << "\n";
        std::cout << "----------------------\n";
    }

    // Display account info
    void displayAccountInfo() const {
        std::cout << "Account: " << accountNumber 
                  << " | Holder: " << accountHolderName 
                  << " | Balance: $" << std::fixed << std::setprecision(2) << balance << "\n";
    }
};

class BankingSystem {
private:
    std::vector<BankAccount> accounts;

    // Find account by account number
    int findAccount(const std::string& accountNumber) {
        for (size_t i = 0; i < accounts.size(); ++i) {
            if (accounts[i].getAccountNumber() == accountNumber) {
                return static_cast<int>(i);
            }
        }
        return -1; // Account not found
    }

    // Clear input buffer
    void clearInputBuffer() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Get valid double input
    double getValidAmount() {
        double amount;
        while (!(std::cin >> amount)) {
            std::cout << "Invalid input! Please enter a valid number: ";
            clearInputBuffer();
        }
        return amount;
    }

public:
    // Create new account
    void createAccount() {
        std::string accountNumber, name;
        double initialBalance;

        std::cout << "\n--- Create New Account ---\n";
        std::cout << "Enter account number: ";
        std::cin >> accountNumber;

        // Check if account already exists
        if (findAccount(accountNumber) != -1) {
            std::cout << "Error: Account number already exists!\n";
            return;
        }

        clearInputBuffer(); // Clear buffer before getline
        std::cout << "Enter account holder name: ";
        std::getline(std::cin, name);

        std::cout << "Enter initial deposit amount (or 0 for no initial deposit): $";
        initialBalance = getValidAmount();

        accounts.emplace_back(accountNumber, name, initialBalance);
        std::cout << "Account created successfully!\n";
    }

    // Deposit to account
    void depositToAccount() {
        if (accounts.empty()) {
            std::cout << "No accounts exist. Please create an account first.\n";
            return;
        }

        std::string accountNumber;
        double amount;

        std::cout << "\n--- Deposit Money ---\n";
        std::cout << "Enter account number: ";
        std::cin >> accountNumber;

        int index = findAccount(accountNumber);
        if (index == -1) {
            std::cout << "Error: Account not found!\n";
            return;
        }

        std::cout << "Enter deposit amount: $";
        amount = getValidAmount();

        accounts[index].deposit(amount);
    }

    // Withdraw from account
    void withdrawFromAccount() {
        if (accounts.empty()) {
            std::cout << "No accounts exist. Please create an account first.\n";
            return;
        }

        std::string accountNumber;
        double amount;

        std::cout << "\n--- Withdraw Money ---\n";
        std::cout << "Enter account number: ";
        std::cin >> accountNumber;

        int index = findAccount(accountNumber);
        if (index == -1) {
            std::cout << "Error: Account not found!\n";
            return;
        }

        std::cout << "Enter withdrawal amount: $";
        amount = getValidAmount();

        accounts[index].withdraw(amount);
    }

    // Check balance of specific account
    void checkAccountBalance() {
        if (accounts.empty()) {
            std::cout << "No accounts exist. Please create an account first.\n";
            return;
        }

        std::string accountNumber;
        std::cout << "\n--- Check Balance ---\n";
        std::cout << "Enter account number: ";
        std::cin >> accountNumber;

        int index = findAccount(accountNumber);
        if (index == -1) {
            std::cout << "Error: Account not found!\n";
            return;
        }

        accounts[index].checkBalance();
    }

    // Display all accounts
    void displayAllAccounts() {
        if (accounts.empty()) {
            std::cout << "No accounts exist.\n";
            return;
        }

        std::cout << "\n--- All Accounts ---\n";
        for (const auto& account : accounts) {
            account.displayAccountInfo();
        }
        std::cout << "------------------\n";
    }

    // Main menu
    void showMenu() {
        std::cout << "\n========== BANKING SYSTEM ==========\n";
        std::cout << "1. Create Account\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Check Balance\n";
        std::cout << "5. Display All Accounts\n";
        std::cout << "6. Exit\n";
        std::cout << "====================================\n";
        std::cout << "Enter your choice (1-6): ";
    }

    // Run the banking system
    void run() {
        int choice;
        
        std::cout << "Welcome to the Basic Banking System!\n";
        
        while (true) {
            showMenu();
            
            if (!(std::cin >> choice)) {
                std::cout << "Invalid input! Please enter a number between 1 and 6.\n";
                clearInputBuffer();
                continue;
            }

            switch (choice) {
                case 1:
                    createAccount();
                    break;
                case 2:
                    depositToAccount();
                    break;
                case 3:
                    withdrawFromAccount();
                    break;
                case 4:
                    checkAccountBalance();
                    break;
                case 5:
                    displayAllAccounts();
                    break;
                case 6:
                    std::cout << "Thank you for using the Banking System. Goodbye!\n";
                    return;
                default:
                    std::cout << "Invalid choice! Please enter a number between 1 and 6.\n";
                    break;
            }
            
            // Pause before showing menu again
            std::cout << "\nPress Enter to continue...";
            clearInputBuffer();
            std::cin.get();
        }
    }
};

int main() {
    BankingSystem bankSystem;
    bankSystem.run();
    return 0;
}
