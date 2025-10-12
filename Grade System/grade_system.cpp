
#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

struct Student {
	string name;
	double grade;
};

void inputStudents(vector<Student>& students, int count) {
	for (int i = 0; i < count; ++i) {
		Student s;
		cout << "Enter name for student " << (i + 1) << ": ";
		getline(cin, s.name);
		cout << "Enter grade for " << s.name << ": ";
		while (!(cin >> s.grade) || s.grade < 0 || s.grade > 100) {
			cout << "Invalid grade. Enter a value between 0 and 100: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
		students.push_back(s);
	}
}

double calculateAverage(const vector<Student>& students) {
	double sum = 0;
	for (const auto& s : students) {
		sum += s.grade;
	}
	return students.empty() ? 0 : sum / students.size();
}

double findHighest(const vector<Student>& students) {
	double highest = students.empty() ? 0 : students[0].grade;
	for (const auto& s : students) {
		if (s.grade > highest) highest = s.grade;
	}
	return highest;
}

double findLowest(const vector<Student>& students) {
	double lowest = students.empty() ? 0 : students[0].grade;
	for (const auto& s : students) {
		if (s.grade < lowest) lowest = s.grade;
	}
	return lowest;
}

int main() {
	int numStudents;
	cout << "Student Grade Management System" << endl;
	cout << "Enter number of students: ";
	while (!(cin >> numStudents) || numStudents <= 0) {
		cout << "Invalid number. Enter a positive integer: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

	vector<Student> students;
	inputStudents(students, numStudents);

	cout << "\nStudent Grades:" << endl;
	for (const auto& s : students) {
		cout << s.name << ": " << s.grade << endl;
	}

	cout << "\nAverage Grade: " << calculateAverage(students) << endl;
	cout << "Highest Grade: " << findHighest(students) << endl;
	cout << "Lowest Grade: " << findLowest(students) << endl;

	return 0;
}
