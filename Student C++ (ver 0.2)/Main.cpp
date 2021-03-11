#include "DataBaseHander.h"
#include "Student.h"
#include <iostream>

using namespace std;

int main() {

	string age;
	string name;
	string city;
	string institute;
	string district;
	string adress;
	string caffe;
	string cinema;

	unsigned int numberWorkDay;
	unsigned int numberNonWorkDay;
	unsigned int cost;
	
	cout << "Enter the student information" << endl << "--------------------" << endl;
	cout << "Enter name: ";
	getline(cin, name);
	cout << "--------------" << endl;
	cout << "Enter age: ";
	getline(cin, age);
	cout << "--------------" << endl;
	cout << "Enter city: ";
	getline(cin, city);
	cout << "--------------" << endl;
	cout << "Enter institute: ";
	getline(cin, institute);
	cout << "--------------" << endl;
	cout << "Enter district: ";
	getline(cin, district);
	cout << "--------------" << endl;
	cout << "Enter adress: ";
	getline(cin, adress);
	cout << "--------------" << endl;
	cout << "Enter caffe: ";
	getline(cin, caffe);
	cout << "--------------" << endl;
	cout << "Enter cinema: ";
	getline(cin, cinema);
	cout << "--------------" << endl;
	cout << "Enter number work days in the month: ";
	cin >> numberWorkDay;
	cout << "--------------" << endl;
	cout << "Enter number non-work days in the month: ";
	cin >> numberNonWorkDay;
	cout << "--------------" << endl;
	
	Student firstStudent(age, name, city, institute, district, adress, caffe, cinema, numberWorkDay, numberNonWorkDay);

	cost = firstStudent.CounterMonthCost(numberWorkDay, numberNonWorkDay);

	cout << "Student monthly cost of living: " << cost << endl;

	return 0;
}