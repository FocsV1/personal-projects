// Simple To-Do List Console App
// Written by a human (with a little help from GitHub Copilot!)
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

struct Task {
    std::string description;
};

void loadTasks(std::vector<Task>& tasks, const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            tasks.push_back({line});
        }
    }
}

void saveTasks(const std::vector<Task>& tasks, const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& task : tasks) {
        file << task.description << std::endl;
    }
}

void showTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks yet!" << std::endl;
        return;
    }
    std::cout << "Your tasks:" << std::endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i].description << std::endl;
    }
}

void addTask(std::vector<Task>& tasks) {
    std::cout << "Enter task description: ";
    std::string desc;
    std::getline(std::cin, desc);
    if (!desc.empty()) {
        tasks.push_back({desc});
        std::cout << "Task added!" << std::endl;
    } else {
        std::cout << "Task description cannot be empty." << std::endl;
    }
}

void deleteTask(std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to delete." << std::endl;
        return;
    }
    showTasks(tasks);
    std::cout << "Enter task number to delete: ";
    int num;
    std::cin >> num;
    std::cin.ignore(); // clear newline
    if (num < 1 || num > (int)tasks.size()) {
        std::cout << "Invalid task number." << std::endl;
    } else {
        tasks.erase(tasks.begin() + num - 1);
        std::cout << "Task deleted!" << std::endl;
    }
}

int main() {
    std::vector<Task> tasks;
    const std::string filename = "tasks.txt";
    loadTasks(tasks, filename);
    while (true) {
        std::cout << "\nTo-Do List Menu:\n";
        std::cout << "1. View tasks\n";
        std::cout << "2. Add task\n";
        std::cout << "3. Delete task\n";
        std::cout << "4. Save & Exit\n";
        std::cout << "Choose an option: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore(); // clear newline
        if (choice == 1) {
            showTasks(tasks);
        } else if (choice == 2) {
            addTask(tasks);
        } else if (choice == 3) {
            deleteTask(tasks);
        } else if (choice == 4) {
            saveTasks(tasks, filename);
            std::cout << "Tasks saved. Goodbye!" << std::endl;
            break;
        } else {
            std::cout << "Invalid option. Try again." << std::endl;
        }
    }
    return 0;
}
