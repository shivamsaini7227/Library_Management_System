#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdio>

using namespace std;

int saving();												   // 1
int adminView();											   // 2
int studentLogin();											   // 3
int adminLogin();											   // 4
int checkStudentCredentials(string username, string password); // 5
int studentcheck(string username);							   // 6
void registerstudent();										   // 7
void markMyAttendance();									   // 8
void attdbyuser();											   // 9
void attdbyroll();											   // 10
int deleteStudentbyRollno();								   // 11
int detailsofstudents();									   // 12								 
int countMyAttendance(string username);						   // 13
int checkListOfStudentsRegistered();						   // 14					 
int studentView();											   // 15

int saving() // 1
{
	for (int i = 0; i < 3; i++)
	{
		cout << "\n Saving Records ...";
		for (int ii = 0; ii < 20000; ii++)
		{ // take some time for the saving records
			for (int iii = 0; iii < 20000; iii++)
			{
			} // loop for some time delay
		}
	}

	cout << "\n Exiting Now ...";
	for (int i = 0; i < 3; i++)
	{
		for (int ii = 0; ii < 20000; ii++)
		{
			for (int iii = 0; iii < 20000; iii++)
			{
			}
		}
	}

	return 0;
}

int adminView() // 2
{
	int goBack = 0;
	while (1)

	{
		system("clear");
		cout << "\n 1 Register a Student";
		cout << "\n 2 Delete student by rollno";
		cout << "\n 3 detail of student";
		cout << "\n 4 Check List of Student registered by userame";
		cout << "\n 0 Go Back <- \n";
		int choice;

		cout << "\n Enter you choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			registerstudent();
			break;
		case 2:
			deleteStudentbyRollno();
			break;
		case 3:
			detailsofstudents();
			break;
		case 4:
			checkListOfStudentsRegistered();
			break;
		case 0:
			goBack = 1;
			break;
		default:
			cout << "\n Invalid choice. Enter again ";
			getchar();
		}

		if (goBack == 1)
		{
			break; // break the loop
		}
	}

	return 0;
}

int adminLogin() // 4
{
	system("clear");
	cout << "\n                       --------- Admin Login --------";

	string username;
	string password;

	cout << "\n Enter username : ";
	cin >> username;
	cout << "\n Enter password : ";
	cin >> password;

	if (username == "admin" && password == "admin@2")
	{
		adminView();
		getchar();
		saving();
	}
	else
	{
		cout << "\n Error ! Invalid Credintials..";
	}

	return 0;
}

int checkStudentCredentials(string username, string password) // 5

{
	// read file line by line & check if username-password.dat exist?
	// if it exsist return 1 else 0

	ifstream in;
	in.open("db.dat");

	// file opens and run

	if (in)
	{
		// The file exists, and is open for input
		int recordFound = 0;
		string line;
		string temp = username + password + ".info";
		cout << "\n file name is : " << temp;
		while (getline(in, line))
		{
			if (line == temp)
			{
				recordFound = 1;
				break;
			}
		}

		if (recordFound == 0)
			return 0;

		else
			return 1;
	}

	else
	{
		return 0;
	}
}

int studentcheck(string username) // 6
{
	ifstream read;
	read.open("username.txt");
	string line;
	int recordfound = 0;

	read.is_open();

	while (getline(read, line))
	{
		if (line == username + ".dat")
		{
			return 1;
		}

		else
			return 0;
	}
	return 0;
}

class student
{
private:
	char name[30];
	char password[20];
	char username[20], rollno[10];
	char branch[20], address[100], dob[10], bloodgrp[4];
	int attd;

public:
	void getdata()
	{
		cout << "\nENTER USERNAME : "<<endl;
		cin >> username;

		// check if record already exist..
		studentcheck(username);

		if (&studentcheck)

		{
			cout << "WRITE THE BRANCH " << endl;
			cin>>branch;

			cout << " Enter password : "<<endl;
			cin >> password;

			cout << " Enter Name : "<<endl;
			cin>>name;

			cout << "ENTER ROLL NO : "<<endl;
			cin >> rollno;

			cout << "ENTER YOUR DOB " << endl;
			cin >> dob;

			cout << "ENTER YOUR BLOOD GROUP " << endl;
			cin >> bloodgrp;

			cout << "WRITE YOUR ADDRESS " << endl;
			cin >> address;

			cout << "\n write the number of attendance" << endl;
			cin >> attd;

			cin.ignore(1, '\n');

			ofstream out1("attendance.txt", ios::app);
			out1 << username << ' ' << password << ' ' << rollno << ' ' << attd;
			out1.close();
		}

		else
			cout << "THE STUDENT ALREADY REGISTERED" << endl;
	}

	void show()
	{
		cout << name << ' ' << rollno << ' ' << attd << ' ' << branch << ' ' << address << ' ' << dob << ' ' << bloodgrp;
	}
	void showregister()
	{
		cout << username << ' ' << password << ' ' << rollno << ' ' << attd;
	}
};

void registerstudent() // 7
{
	ofstream out("details.txt", ios::app);
	student s;
	s.getdata();
	out.write((char *)&s, sizeof(student));
	saving();
	cout << "sucessfully updated";
}

void markMyAttendance() // 8
{
	int goBack = 0;
	while (1)
	{
		cout << "MARK ATTENDANCE BY?" << endl;
		cout << "PRESS 1 - BY USERNAME" << endl;
		cout << "PRESS 2 - BY ROLLNO" << endl;
		int check;
		cin >> check;
		switch (check)
		{
		case 1:
			attdbyuser();
			break;

		case 2:
			attdbyroll();
			break;

		default:
			cout << "PLEASE SELECT A VALID NUMBER" << endl;
		}

		if (goBack == 1)
		{
			break; // break the loop
		}
	}
}

void attdbyuser() // 9
{
	string username, password, rollno;
	int attd;

	cout << "WRITE THE USERNAME" << endl;
	cin >> username;
	studentcheck(username);

	if (&studentcheck)
	{

		ifstream file1("attendence.txt");

		ofstream file2("temp.txt");

		while (!file1.eof())
		{
			file1 >> username >> password >> rollno >> attd;
			++attd;

			file2 << username << ' ' << attd;
		}

		remove("attendence.txt");
		rename("temp.txt", "attendence.txt");
	}
}

void attdbyroll() // 10
{
	string username, password, rollno;
	int attd;
	string check;

	cout << "WRITE THE ROLLNO" << endl;
	cin >> check;

	ifstream file1("attendence.txt");

	ofstream file2("temp.txt");

	while (!file1.eof())
	{
		file1 >> username >> password >> rollno >> attd;
		if (rollno == check)
		{
			++attd;
		}
		file2 << username << password << rollno << attd;
	}

	remove("attendence.txt");
	rename("temp.txt", "attendence.txt");
}

int deleteStudentbyRollno() // 11
{
	string rollno, password, username;
	int attd;
	string check;

	cout << "\n Delete any Student by their Roll No \n";

	cout << "WRITE THE ROLL NUMBER" << endl;
	cin >> rollno;
	ifstream in("attendance.txt");
	ofstream out("temp.txt");
	while (!in.eof())
	{
		in >> username >> password >> check >> attd;
		if (rollno == check)
		{
			continue;
		}
		out << username << ' ' << password << ' ' << check << ' ' << attd;
	}

	remove("attendence.txt");
	rename("temp.txt", "attendence.txt");

	cout << "\n Please any key to continue..";
	getchar();
	getchar();

	return 0;
}

int detailsofstudents() // 12
{
	string rollno, username, password;
	int attd;
	string check;
	;
	cout << "ENTER THE ROLL NUMBER OF THE STUDENT WHOM YOU WANT TO EXTRACT" << endl;
	cin >> rollno;

	student s;
	ifstream in("details.txt");
	in >> username >> password >> check >> attd;
	while (!in.eof())
	{
		if (rollno == check)
		{
			in.read((char *)&s, sizeof(student));
			cout << "HERES'S THE DETAILS" << endl;
			s.show();
		}
	}
	return 0;
}

int countMyAttendance(string username) // 13
{
	string rollno, uname, password;
	int attd;
	string check;

	student s;
	ifstream in("attendance.txt");
	in >> username >> password >> check >> attd;
	while (!in.eof())
	{
		if (username == uname)
		{
			cout << "THE TOTAL ATTENDANCE OF THE STUDENT IS" << endl;
			cout << attd << endl;
		}
	}
	return 0;
}

int checkListOfStudentsRegistered() // 14
{
	string username, rollno, uname, password;
	int attd;
	string check;
	student s2;
	ifstream in("attendance.txt");
	in >> username >> password >> check >> attd;
	while (!in.eof())
	{
		s2.showregister();
	}
	return 0;
}

int studentView() // 15
{
	cout << "\n ------- Student Login-------- \n";

	string username, password;

	cout << "\n Enter username : ";
	cin >> username;

	cout << "\n Enter password : ";
	cin >> password;

	int res = checkStudentCredentials(username, password);

	if (res == 0)
	{
		cout << "\n Invalid Credentials !!";
		cout << "\n Press any key for Main Menu..";
		getchar();
		getchar();
		return 0;
	}

	int goBack = 0;
	while (1)
	{
		system("clear");

		cout << "\n 1 Mark Attendance fo Today ";
		cout << "\n 2 Count my Attendance";
		cout << "\n 0. Go Back <- \n";
		int choice;

		cout << "\n Enter you choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			markMyAttendance();
			break;
		case 2:
			countMyAttendance(username);
			break;
		case 0:
			goBack = 1;
			break;
		default:
			cout << "\n Invalid choice. Enter again ";
			getchar();
		}

		if (goBack == 1)
		{
			break; // break the loop
		}
	}
	return 0;
}

int main()
{
	cout << "------------------------------*WELCOME TO ATTENDANCE MANAGEMENT SOFTWARE*--------------------------------" << endl;
	cout << adminLogin();
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
