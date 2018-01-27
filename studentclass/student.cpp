//============================================================================
// Name        : studentclass.cpp
// Author      : Khayyam Saleem
// Copyright   : I pledge my honor that I have abided by the stevens honor system
// Description : Informs you which of your students are failing. 
//============================================================================

#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

class Student {

public:

	//constructor
	Student(string first, string last, float gpa, int id) : first_(first), last_(last), gpa_(gpa), id_(id) { }

	string full_name() const{
		string full_name = first_ + " " + last_;
		return full_name;
	}

	int id() const{
		return id_;
	}

	float gpa() const{
		return gpa_;
	}

	void print_info() const{
		cout << full_name() << ", GPA: " << fixed << setprecision(2) << gpa() << ", ID: " << id() << endl;
	}

private:
	string first_, last_;
	float gpa_;
	int id_;
};

vector<Student> find_failing_students(const vector<Student> &students) {
	vector<Student> failing_students;

	for (vector<Student>::const_iterator it = students.begin(); it != students.end(); ++it) {
		if (it->gpa() < 1.0) {
			failing_students.push_back(*it);
		}

	}
	return failing_students;
}

void print_students(const vector<Student> &students){
	for (vector<Student>::const_iterator it = students.begin(); it != students.end(); ++it) {
		it->print_info();
	}
}



int main() {
	string first_name, last_name;
	float gpa;
	int id;
	char repeat;
	vector<Student> students;
	do {
		cout << "Enter student's first name: ";
		cin >> first_name;
		cout << "Enter student's last name: ";
		cin >> last_name;
		gpa = -1;
		while (gpa < 0 || gpa > 4) {
			cout << "Enter student's GPA (0.0-4.0): ";
			cin >> gpa;
		}
		cout << "Enter student's ID: ";
		cin >> id;
		students.push_back(Student(first_name, last_name, gpa, id));
		cout << "Add another student to database (Y/N)? ";
		cin >> repeat;
	} while (repeat == 'Y' || repeat == 'y');
	cout << endl << "All students:" << endl;
	print_students(students);
	cout << endl << "Failing students:";
	// TODO
	// Print a space and the word 'None' on the same line if no students are
	// failing.
	// Otherwise, print each failing student on a separate line.
	if (find_failing_students(students).empty()){
		cout << " None" << endl;
	} else {
		cout << endl;
		print_students(find_failing_students(students));
	}
	return 0;
}
