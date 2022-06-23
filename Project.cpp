#include<iostream>
#include<fstream>
#include"Header.h"
#include<stdlib.h>
using namespace std;

void PrintData(Person& p) {
	p.print();
}

int main() {
	char after_portal;
	char after_portal2, after_portal3, after_portal4, after_portal5;
	system("cls");
	ifstream read;
	read.open("Data.txt");
	if (read.is_open()) {
		char uni_name[50];
		University university;
		int totaldep;
		ifstream read1;
		read1.open("Passwords.txt");
		//Read data from file "Passwords.txt" and store in University object.
		//This file contain all data of previous file with passwords additionally
		if (read1.is_open()) {
			char uni_name[50];
			read1.getline(uni_name, 50);
			university.setUniName(uni_name);
			//cout << university.getUniName() << endl;
			read1 >> totaldep;
			university.setTotalDep(totaldep);
			//cout << university.getTotalDep() << endl;
			read1.ignore();
			for (int i = 0; i < totaldep; i++) {
				char depname[50];
				read1.getline(depname, 50);
				int totalcourse;
				read1 >> totalcourse;
				Department* depart;
				depart = university.Add_DepData(depname, totalcourse);
				//cout << depart->getName() << endl;
				//cout << depart->getTotalCourses() << endl;
				for (int i = 0; i < totalcourse; i++) {
					//read1.ignore();
					char id[50];
					read1.getline(id, 50, ',');
					char name[50];
					read1.getline(name, 50);
					depart->AddCourseData(id, name);
					//cout<<depart->getRequuiredCourse(i)->getID() << " ";
					//cout << depart->getRequuiredCourse(i)->getCourseName() << endl;
				}
				int totalteachers;
				read1 >> totalteachers;
				depart->setTotalTeachers(totalteachers);
				//cout<<depart->getTotalTeachers() << endl;
				read1.ignore();
				for (int j = 0; j < totalteachers; j++) {
					char id[50];
					read1.getline(id, 50, ',');
					char name[50];
					read1.getline(name, 50, ',');
					depart->Add_TeachersData(id, name);
					//cout<<depart->getRequiredTeacher(j)->getEmployeeID() << " ";
					//cout << depart->getRequiredTeacher(j)->getPersonName() << " ";
					int passw;
					read1 >> passw;
					depart->PassRecord(j, passw);
					//cout << depart->getRequiredTeacher(j)->getPass() << endl;
					if (j == 0) {
						depart->setHOD(id, name);
						depart->setHOD_pass(i, passw);
					}
					read1.ignore();
				}
				int manager_count;
				read1 >> manager_count;
				//cout << manager_count << endl;
				read1.ignore();
				char manager_id[50];
				read1.getline(manager_id, 50, ',');
				char manager_name[50];
				read1.getline(manager_name, 50);
				depart->setManager(manager_id, manager_name);
				//cout<<depart->getManager()->getEmployeeID() << " ";
				//cout << depart->getManager()->getPersonName() << endl;
				int totalstudents;
				read1 >> totalstudents;
				depart->setTotalStudents(totalstudents);
				//cout<<depart->getTotalStudents() << endl;
				read1.ignore();
				for (int i = 0; i < totalstudents; i++) {
					char id[50];
					read1.getline(id, 50, ',');
					char name[50];
					read1.getline(name, 50, ',');
					depart->Add_StudentsData(id, name);
					int passw;
					read1 >> passw;
					depart->PassRecordStudent(i, passw);
					//cout << depart->getRequiredStudent(i)->getRollNum() << " ";
					//cout << depart->getRequiredStudent(i)->getPersonName() << " ";
					//cout << depart->getRequiredStudent(i)->getStuPass() << endl;
					read1.ignore();
				}
				//*university.getRequiredDep(i) = *depart;

				//cout << endl;
			}
		}
		read1.close();
		int x = -1;
		for (int k = 0; k != x; k++) {
			int b = -1;
			for (int a = 0; a != b; a++) {
				system("cls");
				cout << endl << endl << endl << endl;
				cout << " WELCOME TO:" << endl << endl << endl;
				cout << "				 _____________________________________________" << endl;
				cout << "				|___________";
				cout << university.getUniName();
				cout << "___________|" << endl;
				if (a != 0) {
					cout << endl << "					Invalid ID or Password. Enter again!" << endl;
				}
				cout << endl << "					Enter Login_ID: ";
				try {
					//Check ID and opens portal according to entred data
					char login[4];
					int len = 0;
					cin >> login;
					for (int i = 0; login[i] != '\0'; i++) {
						len++;
					}
					if (len == 4 || len == 3) {
						//Opens specific portal
						throw login;
					}
					else {
						throw "hello";
					}
				}
				catch (char login[]) {
					int len = 0;
					for (int i = 0; login[i] != '\0'; i++) {
						len++;
					}
					if (len == 4) {
						// Student Portal
						cout << endl << "					Enter Password: ";
						int pass;
						cin >> pass;
						for (int k = 0; k < totaldep; k++) {
							Department* dep = university.getRequiredDep(k);
							int students = dep->getTotalStudents();
							for (int i = 0; i < students; i++) {
								Student* student = dep->getRequiredStudent(i);
								char* id = student->getRollNum();
								//check whether the entered ID matches university student's IDs or not
								if (login[0] == id[0] && login[1] == id[1] && login[2] == id[2] && login[3] == id[3] && student->getStuPass() == pass) {
									int clock1 = -1;
									for (int clock = 0; clock != clock1; clock++) {
										system("cls");
										cout << endl << " ______________________________________________________________________________________________________________________" << endl;
										cout << "|_____________________________________________________STUDENTS' PORTAL_________________________________________________|" << endl;
										cout << endl << endl << " Student_Name = ";
										cout << student->getPersonName() << endl;
										cout << " Student_ID  = " << id << endl;
										cout << " Department = " << dep->getName() << endl;
										cout << endl << endl;
										cout << "					->Press 'A' to  Register Courses" << endl;
										cout << endl << "					->Press'S' to Unregister Courses" << endl;
										cout << endl << "					->Press 'W' to Withdraw a Course" << endl;
										cout << endl << "					->Press 'D' to Change Password" << endl;
										cout << endl << "					->Press 'F' to View Attendance of specific Course" << endl;
										cout << endl << "					->Press 'K' to View Marksheet of specific Course" << endl;
										a = b - 1;
										cout << endl << "					->Press selected Alphabet then press ENTER__ ";
										//Input Alphabet to perform specific task of Student
										cin >> after_portal2;
										try {

											if (after_portal2 == 'A' || after_portal2 == 'a') {
												//Registration of Courses
												throw 5;
											}
											if (after_portal2 == 'S' || after_portal2 == 's') {
												int press;
												int count4 = 1;
												//Unregister Courses for Student
												system("cls");
												cout << endl << " ______________________________________________________________________________________________________________________" << endl;
												cout << "|________________________________________________Unregisteration of Courses______________________________________________|" << endl;
												cout << endl << endl << endl;
												for (int j = 0; j < dep->getTotalCourses(); j++) {
													//Display all courses of department
													cout << "					->Press " << count4++ << " to Unregister ";
													cout << "'" << dep->getRequuiredCourse(j)->getCourseName() << "'" << endl;
												}
												cout << endl << "					->Press selected Number then press ENTER__ ";
												//Input Number to perform specific task of Student
												int q = -1;
												for (int f = 0; f != q; f++) {
													cin >> press;
													if (press > 0 && press < 9) {
														f = q - 1;
													}
													else {
														cout << endl << "					You have pressed wrong key...Select number between 1 to 8 " << endl;
														cout << "					->Press selected Number then press ENTER__ ";
													}
												}
												bool check2;
												check2 = student->CourseUnregistration(dep->getRequuiredCourse(press - 1), press);
												if (check2 == false) {
													cout << "						This Course is not being registered yet! " << endl;
												}
												else {
													cout << endl << "					  Selected Course is Unregistered" << endl;
												}
												//return to login page
												int null = -1;
												for (int w = 0; w != null; w++) {
													cout << endl << "					->Press 'X' to veiw previous page__";
													char input;
													cin >> input;
													if (input == 'X' || input == 'x') {
														clock = clock1 - 1;
														w = null - 1;
													}
													else {
														cout << "					wrong key is pressed...Try Again" << endl;
													}
												}
											}
											if (after_portal2 == 'W' || after_portal2 == 'w') {
												int press;
												int count4 = 1;
												//Withdraw Courses for Student
												system("cls");
												cout << endl << " ______________________________________________________________________________________________________________________" << endl;
												cout << "|________________________________________________Withdraw a Courses______________________________________________|" << endl;
												cout << endl << endl << endl;
												for (int j = 0; j < dep->getTotalCourses(); j++) {
													//display all courses of department
													cout << "					->Press " << count4++ << " to Withdraw ";
													cout << "'" << dep->getRequuiredCourse(j)->getCourseName() << "'" << endl;
												}
												cout << endl << "					->Press selected Number then press ENTER__ ";
												//Input Number to perform specific task of Student
												int q = -1;
												for (int f = 0; f != q; f++) {
													cin >> press;
													if (press > 0 && press < 9) {
														f = q - 1;
													}
													else {
														cout << endl << "					You have pressed wrong key...Select number between 1 to 8 " << endl;
														cout << "					->Press selected Number then press ENTER__ ";
													}
												}
												bool check2;
												check2 = student->CourseWithdraw(dep->getRequuiredCourse(press - 1), press);
												if (check2 == false) {
													cout << "						This Course is not being registered yet! " << endl;
												}
												else {
													cout << endl << "					  Selected Course is withdrawal" << endl;
												}
												int null = -1;
												//return to login page
												for (int w = 0; w != null; w++) {
													cout << endl << "					->Press 'X' to veiw previous page__";
													char input;
													cin >> input;
													if (input == 'X' || input == 'x') {
														clock = clock1 - 1;
														w = null - 1;
													}
													else {
														cout << "					wrong key is pressed...Try Again" << endl;
													}
												}
											}
											if (after_portal2 == 'F' || after_portal2 == 'f') {
												int press;
												int count4 = 1;
												//Attendance of Specific Course
												system("cls");
												cout << endl << " ______________________________________________________________________________________________________________________" << endl;
												cout << "|________________________________________________Attendance of Courses______________________________________________|" << endl;
												cout << endl << endl << endl;
												for (int j = 0; j < dep->getTotalCourses(); j++) {
													//display all courses of department
													cout << "					->Press " << count4++ << " to view Attendance of ";
													cout << "'" << dep->getRequuiredCourse(j)->getCourseName() << "'" << endl;
												}
												cout << endl << "					->Press selected Number then press ENTER__ ";
												//Input Number to perform specific task of Student
												int q = -1;
												for (int f = 0; f != q; f++) {
													cin >> press;
													if (press > 0 && press < 9) {
														f = q - 1;
													}
													else {
														cout << endl << "					You have pressed wrong key...Select number between 1 to 8 " << endl;
														cout << "					->Press selected Number then press ENTER__ ";
													}
												}
												system("cls");
												cout << endl << " ______________________________________________________________________________________________________________________" << endl;
												cout << "|___________________________________________________Attendance_________________________________________________|" << endl;
												cout << endl << endl << endl;
												cout << endl << endl << " Student_Name = ";
												cout << student->getPersonName() << endl;
												cout << " Student_ID  = " << id << endl;
												cout << " Course_Name = " << dep->getRequuiredCourse(press - 1) << endl;
												cout << endl << endl << endl;
												char* temp6 = dep->getRequuiredCourse(press - 1)->getID();
												int index = -1;
												//Check whether the course is registred or not 
												//if registered then mark attendance
												for (int m = 0; m < student->getRegistration_Count(); m++) {
													char* temp2 = student->getRigisteredCourse(m)->getID();
													if (temp6[0] == temp2[0] && temp6[1] == temp2[1] && temp6[2] == temp2[2] && temp6[3] == temp2[3]) {
														index = m;
													}
												}
												if (index == -1) {
													cout << "					This course is not being Registered yet...Forst register this course!" << endl;
												}
												//check whether teacher has updated attendance or not
												else if (student->getRigisteredCourse(index)->getReg()->geteCurrentAttendance() == 0) {
													cout << "					Teacher has not updated Attendance yet!" << endl;
												}
												else {
													int number = student->getRigisteredCourse(index)->getReg()->geteCurrentAttendance();
													for (int m = 0; m < number; m++) {
														cout << "					Lecture_" << m + 1 << "	 ";
														cout << m + 1 << "-" << "08-2020" << "	";
														cout << student->getRigisteredCourse(index)->getReg()->getMarkedAttendance(m) << endl;
													}
												}
												//return to login page
												int null = -1;
												for (int w = 0; w != null; w++) {
													cout << endl << "					->Press 'X' to veiw previous page__";
													char input;
													cin >> input;
													if (input == 'X' || input == 'x') {
														clock = clock1 - 1;
														w = null - 1;
													}
													else {
														cout << "					wrong key is pressed...Try Again" << endl;
													}
												}
											}
											if (after_portal2 == 'D' || after_portal2 == 'd') {
												//Change Password
												system("cls");
												cout << endl << " ______________________________________________________________________________________________________________________" << endl;
												cout << "|____________________________________________________Change Password_________________________________________________|" << endl;
												cout << endl << endl << endl;
												int f2 = -1;
												int pass = 0;
												//check whether the user knows his password
												for (int v = 0; v != f2; v++) {
													cout << "						Enter Current Password = ";
													cin >> pass;
													if (pass != student->getStuPass()) {
														cout << "					Password is wrong... Try Again" << endl;
													}
													else {
														v = f2 - 1;
													}
												}
												cout << endl << "					Enter New Password then Press Enter key = ";
												int passw;
												cin >> passw;
												//saves new password
												student->setStuPass(passw);
												cout << endl << "					New Password is set successfully! " << endl;
												university.UpdateData();
												//return to login page
												int null = -1;
												for (int w = 0; w != null; w++) {
													cout << endl << "					 ->Press 'X' to veiw previous page__";
													char input;
													cin >> input;
													if (input == 'X' || input == 'x') {
														clock = clock1 - 1;
														w = null - 1;
													}
													else {
														cout << "					wrong key is pressed...Try Again" << endl;
													}
												}
											}
											if (after_portal2 == 'K' || after_portal2 == 'k') {
												int press;
												int count4 = 1;
												system("cls");
												cout << endl << " ______________________________________________________________________________________________________________________" << endl;
												cout << "|__________________________________________View Marksheet of Specific Course________________________________________|" << endl;
												cout << endl << endl;
												for (int j = 0; j < dep->getTotalCourses(); j++) {
													cout << "					->Press " << count4++ << " to view Marksheet of ";
													cout << "'" << dep->getRequuiredCourse(j)->getCourseName() << "'" << endl;
												}
												cout << endl << "					->Press selected Number then press ENTER__ ";
												int q = -1;
												for (int f = 0; f != q; f++) {
													cin >> press;
													if (press > 0 && press < 9) {
														f = q - 1;
													}
													else {
														cout << endl << "					You have pressed wrong key...Select number between 1 to 8 " << endl;
														cout << "					->Press selected Number then press ENTER__ ";
													}
												}
												system("cls");
												cout << endl << " ______________________________________________________________________________________________________________________" << endl;
												cout << "|___________________________________________________Marksheet of Course_________________________________________________|" << endl;
												cout << endl;
												cout << "Course_Name = " << dep->getRequuiredCourse(press - 1)->getCourseName() << endl;
												if (student->getAssignment_list() == -1 && student->getQuiz_list() == -1) {
													cout << endl << endl << "					Your Teacher has not updated any evaluation yet! " << endl;
												}
												else {
													student->ShowMarksheet();
												}
												int null = -1;
												for (int w = 0; w != null; w++) {
													cout << endl << "					->Press 'X' to veiw previous page__";
													char input;
													cin >> input;
													if (input == 'X' || input == 'x') {
														clock = clock1 - 1;
														w = null - 1;
													}
													else {
														cout << "					wrong key is pressed...Try Again" << endl;
													}
												}
											}
										}
										catch (int n) {
											int press;
											int count4 = 1;
											//Register Courses for Student
											system("cls");
											cout << endl << " ______________________________________________________________________________________________________________________" << endl;
											cout << "|________________________________________________Registeration of Courses______________________________________________|" << endl;
											cout << endl << endl << endl;
											//display all courses of department
											for (int j = 0; j < dep->getTotalCourses(); j++) {
												cout << "					->Press " << count4++ << " to Register ";
												cout << "'" << dep->getRequuiredCourse(j)->getCourseName() << "'" << endl;
											}
											cout << endl << "					->Press selected Number then press ENTER__ ";
											//Input Number to perform specific task of Student
											int q = -1;
											for (int f = 0; f != q; f++) {
												cin >> press;
												if (press > 0 && press < 9) {
													f = q - 1;
												}
												else {
													cout << endl << "					You have pressed wrong key...Select number between 1 to 8 " << endl;
													cout << "					->Press selected Number then press ENTER__ ";
												}
											}
											//check whether selected course is previously registered or not
											bool check2;
											check2 = student->CourseRegistration(dep->getRequuiredCourse(press - 1), press);
											if (check2 == true) {
												cout << endl << "					  Selected Course is Registered" << endl;
											}
											else if (check2 == false && student->getRegistration_Count() == 5) {
												cout << "					You can register 5 Courses only" << endl;
											}
											else if (check2 == false && student->getRegistration_Count() != 5) {
												cout << "						This Course is already registered! " << endl;
											}
											//return to login page
											int null = -1;
											for (int w = 0; w != null; w++) {
												cout << endl << "					->Press 'X' to veiw previous page__";
												char input;
												cin >> input;
												if (input == 'X' || input == 'x') {
													clock = clock1 - 1;
													w = null - 1;
												}
												else {
													cout << "					wrong key is pressed...Try Again" << endl;
												}
											}
										}
										catch (...) {
											clock = clock1 - 1;
										}
									}
								}
							}
						}
					}
					//check whether the entered ID matches university Teachers' IDs or not
					else if (len == 3 && login[0] == login[1] && login[1] == login[2]) {
						//Teachers' Portal
						cout << endl << "					Enter Password: ";
						int pass;
						cin >> pass;
						for (int i = 0; i < totaldep; i++) {
							Department* dep = university.getRequiredDep(i);
							int teachers = dep->getTotalTeachers();
							for (int i = 0; i < teachers; i++) {

								if (i == 0) {
									//HOD's Portal
									HOD* hod = dep->getDepHOD(i);
									char* id = hod->getEmployeeID();
									if (login[0] == id[0] && login[1] == id[1] && login[2] == id[2] && hod->getHOD_pass() == pass) {
										int clock1 = -1;
										for (int clock = 0; clock != clock1; clock++) {
											system("cls");
											cout << endl << " ______________________________________________________________________________________________________________________" << endl;
											cout << "|_____________________________________________________HOD's PORTAL____________________________________________________|" << endl;
											cout << endl << endl << " HOD_Name = ";
											cout << hod->getPersonName() << endl;
											cout << " HOD_ID  = " << id << endl;
											cout << " Department = " << dep->getName() << endl;
											cout << endl << endl;
											cout << "					->Press 'A' to  Register Courses" << endl;
											cout << endl << "					->Press'S' to Unregister Courses" << endl;
											cout << endl << "					->Press 'D' to assign Courses to Teachers" << endl;
											cout << endl << "					->Press 'F' to view Grades of Specific Course" << endl;

											a = b - 1;
											cout << endl << "					->Press selected Alphabet then press ENTER__ ";
											//Input Alphabet to perform specific task of HOD
											cin >> after_portal3;
											try {

												if (after_portal3 == 'A' || after_portal3 == 'a') {
													//Register Courses for students
													throw 5;
												}
												if (after_portal3 == 'S' || after_portal3 == 's') {
													system("cls");
													int d = -1;
													int index;
													//check whether the ID is valid
													cout << endl << endl << endl;
													for (int c = 0; c != d; c++) {

														char tempid[25];
														cout << endl << "						Enter ID of Student = ";
														cin >> tempid;
														int length = 0;
														for (int j = 0; tempid[j] != '\0'; j++) {
															length++;
														}
														if (length > 4 || length < 4) {

															cout << "					ID must be a 4-digit number" << endl;
														}
														int count2 = 0;
														if (length == 4) {
															for (int a = 0; a < dep->getTotalStudents(); a++) {
																char* temp = dep->getRequiredStudent(a)->getRollNum();
																if (temp[0] != tempid[0] || temp[1] != tempid[1] || temp[2] != tempid[2] || temp[3] != tempid[3]) {

																}
																else {
																	count2++;
																	index = a;
																}
															}
															if (count2 < 1) {
																cout << "				Entered ID does not exists...Enter existing data only!" << endl;
															}
														}
														if (count2 > 0) {
															c = d - 1;
														}
													}
													int press;
													int count4 = 1;
													//Unregister Courses for Student
													system("cls");
													cout << endl << " ______________________________________________________________________________________________________________________" << endl;
													cout << "|________________________________________________Unregisteration of Courses______________________________________________|" << endl;
													cout << endl << endl << " Student_Name = ";
													cout << dep->getRequiredStudent(index)->getPersonName() << endl;
													cout << " Student_ID  = " << dep->getRequiredStudent(index)->getRollNum() << endl;
													cout << " Department = " << dep->getName() << endl;
													cout << endl << endl << endl;
													//display all courses of department
													for (int j = 0; j < dep->getTotalCourses(); j++) {
														cout << "					->Press " << count4++ << " to Unregister ";
														cout << "'" << dep->getRequuiredCourse(j)->getCourseName() << "'" << endl;
													}
													cout << endl << "					->Press selected Number then press ENTER__ ";
													//Input Number to perform specific task of Student
													int q = -1;
													for (int f = 0; f != q; f++) {
														cin >> press;
														if (press > 0 && press < 9) {
															f = q - 1;
														}
														else {
															cout << endl << "					You have pressed wrong key...Select number between 1 to 8 " << endl;
															cout << "					->Press selected Number then press ENTER__ ";
														}
													}
													bool check2;
													check2 = hod->CourseUnregistration(dep->getRequiredStudent(index), dep->getRequuiredCourse(press - 1), press);
													if (check2 == false) {
														cout << "						This Course is not being registered yet! " << endl;
													}
													else {
														cout << endl << "					  Selected Course is Unregistered" << endl;
													}
													//return to login page
													int null = -1;
													for (int w = 0; w != null; w++) {
														cout << endl << "					->Press 'X' to veiw previous page__";
														char input;
														cin >> input;
														if (input == 'X' || input == 'x') {
															clock = clock1 - 1;
															w = null - 1;
														}
														else {
															cout << "					wrong key is pressed...Try Again" << endl;
														}
													}
												}
												if (after_portal3 == 'D' || after_portal3 == 'd') {
													system("cls");
													int d = -1;
													int index;
													cout << endl << endl << endl;
													//check whether the ID is valid
													for (int c = 0; c != d; c++) {

														char tempid[25];
														cout << endl << "						Enter ID of Teacher = ";
														cin >> tempid;
														int length = 0;
														for (int j = 0; tempid[j] != '\0'; j++) {
															length++;
														}
														if (length > 3 || length < 3) {
															//check = true;
															cout << "					ID must be a 3-digit number" << endl;
														}
														int count2 = 0;
														if (length == 3) {
															for (int a = 0; a < dep->getTotalTeachers(); a++) {
																char* temp = dep->getRequiredTeacher(a)->getEmployeeID();
																if (temp[0] != tempid[0] || temp[1] != tempid[1] || temp[2] != tempid[2]) {
																	//check = true;
																}
																else {
																	count2++;
																	index = a;
																}
															}
															if (count2 < 1) {
																cout << "				Entered ID does not exists...Enter existing data only!" << endl;
															}
														}
														if (count2 > 0) {
															c = d - 1;
														}
													}
													//Assign Courses to Teachers
													int press;
													int count4 = 1;
													system("cls");
													cout << endl << " ______________________________________________________________________________________________________________________" << endl;
													cout << "|________________________________________________Assign Courses to Teacher______________________________________________|" << endl;
													cout << endl << endl << " Teacher_Name = ";
													cout << dep->getRequiredTeacher(index)->getPersonName() << endl;
													cout << " Teacher_ID  = " << dep->getRequiredTeacher(index)->getEmployeeID() << endl;
													cout << " Department = " << dep->getName() << endl;
													cout << endl << endl << endl;
													//display all courses of department
													for (int j = 0; j < dep->getTotalCourses(); j++) {
														cout << "					->Press " << count4++ << " to Assign ";
														cout << "'" << dep->getRequuiredCourse(j)->getCourseName() << "'" << endl;
													}
													cout << endl << "					->Press selected Number then press ENTER__ ";
													//Input Number to perform specific task of Student
													int q = -1;
													for (int f = 0; f != q; f++) {
														cin >> press;
														if (press > 0 && press < 9) {
															f = q - 1;
														}
														else {
															cout << endl << "					You have pressed wrong key...Select number between 1 to 8 " << endl;
															cout << "					->Press selected Number then press ENTER__ ";
														}
													}
													//check if some course is already assigned to teacher or not
													bool check2;
													bool check3 = false;
													for (int l = 0; l < index; l++) {
														int course_count;
														course_count = dep->getRequiredTeacher(l)->getCurrentTcourse();
														char* idee3;
														idee3 = dep->getRequuiredCourse(press - 1)->getID();
														for (int m = 0; m < course_count; m++) {
															char* idee;
															idee = dep->getRequiredTeacher(l)->getAssignedCourse(m)->getID();
															if (idee[0] == idee3[0] && idee[1] == idee3[1] && idee[2] == idee3[2] && idee[3] == idee3[3]) {
																check2 = false;
																check3 = true;
															}
														}
													}
													for (int l = index + 1; l < dep->getTotalTeachers(); l++) {
														int course_count;
														course_count = dep->getRequiredTeacher(l)->getCurrentTcourse();
														char* idee3;
														idee3 = dep->getRequuiredCourse(press - 1)->getID();
														for (int m = 0; m < course_count; m++) {
															char* idee;
															idee = dep->getRequiredTeacher(l)->getAssignedCourse(m)->getID();
															if (idee[0] == idee3[0] && idee[1] == idee3[1] && idee[2] == idee3[2] && idee[3] == idee3[3]) {
																check2 = false;
																check3 = true;
															}
														}
													}
													if (check3 == false) {
														check2 = hod->CourseAssigned(dep->getRequiredTeacher(index), dep->getRequuiredCourse(press - 1), press);
													}
													if (check2 == true) {
														cout << endl << "					  Selected Course is Assigned successfully" << endl;
													}
													if (check2 == false && dep->getRequiredTeacher(index)->getCurrentTcourse() == 1) {
														cout << "					You can assign single Course only" << endl;
													}

													else if (check3 == true && check2 == false) {
														cout << "				This Course is assigned to some other Teacher of same section! " << endl;
													}
													//return to login page
													int null = -1;
													for (int w = 0; w != null; w++) {
														cout << endl << "					->Press 'X' to veiw previous page__";
														char input;
														cin >> input;
														if (input == 'X' || input == 'x') {
															clock = clock1 - 1;
															w = null - 1;
														}
														else {
															cout << "					wrong key is pressed...Try Again" << endl;
														}
													}
												}
												if (after_portal3 == 'F' || after_portal3 == 'f') {
													//View Grades
													int press;
													int count4 = 1;
													system("cls");
													cout << endl << " ______________________________________________________________________________________________________________________" << endl;
													cout << "|_____________________________________________View Grades of Specific Course___________________________________________|" << endl;
													cout << endl << endl;
													//display all courses of department
													for (int j = 0; j < dep->getTotalCourses(); j++) {
														cout << "					->Press " << count4++ << " to view Grades of ";
														cout << "'" << dep->getRequuiredCourse(j)->getCourseName() << "'" << endl;
													}
													cout << endl << "					->Press selected Number then press ENTER__ ";
													int q = -1;
													for (int f = 0; f != q; f++) {
														cin >> press;
														if (press > 0 && press < 9) {
															f = q - 1;
														}
														else {
															cout << endl << "					You have pressed wrong key...Select number between 1 to 8 " << endl;
															cout << "					->Press selected Number then press ENTER__ ";
														}
													}
													system("cls");
													cout << endl << " ______________________________________________________________________________________________________________________" << endl;
													cout << "|_______________________________________________________Grade_List_____________________________________________________|" << endl;
													cout << endl << endl;
													char* idee = dep->getRequuiredCourse(press - 1)->getID();
													//check if teacher has updated grades or not
													bool check = false;
													for (int j = 0; j < dep->getTotalStudents(); j++) {
														for (int m = 0; m < dep->getRequiredStudent(j)->getRegistration_Count(); m++) {
															char* idee2 = dep->getRequiredStudent(j)->getRigisteredCourse(m)->getID();
															if (idee[0] == idee2[0] && idee[1] == idee2[1] && idee[2] == idee2[2] && idee[3] == idee2[3]) {
																if (dep->getRequiredStudent(j)->getRigisteredCourse(m)->getReg()->getGrade() != '0') {
																	check = true;
																}
															}
														}
													}
													if (check == false) {
														cout << "					Teacher has not given Grades yet" << endl;
													}
													else {
														cout << " Course_Name = " << dep->getRequuiredCourse(press - 1)->getCourseName() << endl << endl << endl;
														for (int j = 0; j < dep->getTotalStudents(); j++) {
															for (int m = 0; m < dep->getRequiredStudent(j)->getRegistration_Count(); m++) {
																char* idee2 = dep->getRequiredStudent(j)->getRigisteredCourse(m)->getID();
																if (idee[0] == idee2[0] && idee[1] == idee2[1] && idee[2] == idee2[2] && idee[3] == idee2[3]) {
																	cout << "		" << dep->getRequiredStudent(j)->getRollNum() << "		";
																	cout << dep->getRequiredStudent(j)->getPersonName() << "		";
																	cout << dep->getRequiredStudent(j)->getRigisteredCourse(m)->getReg()->getGrade() << endl << endl;
																}
															}
														}
													}
													//return to login page
													int null = -1;
													for (int w = 0; w != null; w++) {
														cout << endl << "					->Press 'X' to veiw previous page__";
														char input;
														cin >> input;
														if (input == 'X' || input == 'x') {
															clock = clock1 - 1;
															w = null - 1;
														}
														else {
															cout << "					wrong key is pressed...Try Again" << endl;
														}
													}
												}

											}
											catch (int n) {
												system("cls");
												int d = -1;
												int index;
												cout << endl << endl << endl;
												for (int c = 0; c != d; c++) {
													//check whether the ID is valid 

													char tempid[25];
													cout << endl << "						Enter ID of Student = ";
													cin >> tempid;
													int length = 0;
													for (int j = 0; tempid[j] != '\0'; j++) {
														length++;
													}
													if (length > 4 || length < 4) {
														//check = true;
														cout << "					ID must be a 4-digit number" << endl;
													}
													int count2 = 0;
													if (length == 4) {
														for (int a = 0; a < dep->getTotalStudents(); a++) {
															char* temp = dep->getRequiredStudent(a)->getRollNum();
															if (temp[0] != tempid[0] || temp[1] != tempid[1] || temp[2] != tempid[2] || temp[3] != tempid[3]) {

															}
															else {
																count2++;
																index = a;
															}
														}
														if (count2 < 1) {
															cout << "				Entered ID does not exists...Enter existing data only!" << endl;
														}
													}
													if (count2 > 0) {
														c = d - 1;
													}
												}
												int press;
												int count4 = 1;
												//Register Courses for Student
												system("cls");
												cout << endl << " ______________________________________________________________________________________________________________________" << endl;
												cout << "|________________________________________________Registeration of Courses______________________________________________|" << endl;
												cout << endl << endl << " Student_Name = ";
												cout << dep->getRequiredStudent(index)->getPersonName() << endl;
												cout << " Student_ID  = " << dep->getRequiredStudent(index)->getRollNum() << endl;
												cout << " Department = " << dep->getName() << endl;
												cout << endl << endl << endl;
												//display all courses of department
												for (int j = 0; j < dep->getTotalCourses(); j++) {
													cout << "					->Press " << count4++ << " to Register ";
													cout << "'" << dep->getRequuiredCourse(j)->getCourseName() << "'" << endl;
												}
												cout << endl << "					->Press selected Number then press ENTER__ ";
												//Input Number to perform specific task of Student
												int q = -1;
												for (int f = 0; f != q; f++) {
													cin >> press;
													if (press > 0 && press < 9) {
														f = q - 1;
													}
													else {
														cout << endl << "					You have pressed wrong key...Select number between 1 to 8 " << endl;
														cout << "					->Press selected Number then press ENTER__ ";
													}
												}

												bool check2;
												check2 = hod->CourseRegistration(dep->getRequiredStudent(index), dep->getRequuiredCourse(press - 1), press);
												if (check2 == true) {
													cout << endl << "					  Selected Course is Registered" << endl;
												}
												else if (check2 == false && dep->getRequiredStudent(index)->getRegistration_Count() == 5) {
													cout << "					You can register 5 Courses only" << endl;
												}
												else if (check2 == false && dep->getRequiredStudent(index)->getRegistration_Count() != 5) {
													cout << "						This Course is already registered! " << endl;
												}
												//return to login page
												int null = -1;
												for (int w = 0; w != null; w++) {
													cout << endl << "					->Press 'X' to veiw previous page__";
													char input;
													cin >> input;
													if (input == 'X' || input == 'x') {
														clock = clock1 - 1;
														w = null - 1;
													}
													else {
														cout << "					wrong key is pressed...Try Again" << endl;
													}
												}
											}
										}
									}
								}
								else if (i != 0) {
									Teacher* teacher = dep->getRequiredTeacher(i);
									char* id = teacher->getEmployeeID();
									if (login[0] == id[0] && login[1] == id[1] && login[2] == id[2] && teacher->getPass() == pass) {
										int clock1 = -1;
										for (int clock = 0; clock != clock1; clock++) {
											system("cls");
											cout << endl << " ______________________________________________________________________________________________________________________" << endl;
											cout << "|_____________________________________________________TEACHERS' PORTAL_________________________________________________|" << endl;
											cout << endl << endl << " Teacher_Name = ";
											cout << teacher->getPersonName() << endl;
											cout << " Teacher_ID  = " << id << endl;
											cout << " Department = " << dep->getName() << endl;
											cout << endl << endl;
											cout << "					->Press 'A' to  Assign Grades to Students" << endl;
											cout << endl << "					->Press'S' to Manage Attendance of Students" << endl;
											cout << endl << "					->Press 'W' to View Attendance of Students" << endl;
											cout << endl << "					->Press 'D' to Manage evaluations of Students" << endl;
											cout << endl << "					->Press 'F' to view evaluations of Students" << endl;
											a = b - 1;
											cout << endl << "					->Press selected Alphabet then press ENTER__ ";
											//Input Alphabet to perform specific task of Teacher
											cin >> after_portal5;
											try {
												if (after_portal5 == 'A' || after_portal5 == 'a') {
													throw 5;
												}
												if (after_portal5 == 'S' || after_portal5 == 's') {
													//Update Attendance of Students
													system("cls");
													cout << endl << " ______________________________________________________________________________________________________________________" << endl;
													cout << "|_____________________________________________Update Attendance of Students____________________________________________|" << endl;
													cout << endl << endl << endl;
													if (teacher->getCurrentTcourse() == 0) {
														cout << endl << "					This Teacher is not Assigned any Course from HOD..." << endl;
														cout << "						First assign him a specific Course" << endl;
													}
													else {
														//if teacher is assigned course then update attendance
														cout << " Course_Name = " << teacher->getAssignedCourse(0)->getCourseName() << endl << endl << endl;
														for (int j = 0; j < dep->getTotalStudents(); j++) {
															cout << "			" << dep->getRequiredStudent(j)->getRollNum() << "		";
															cout << dep->getRequiredStudent(j)->getPersonName();
															dep->getRequiredStudent(j)->CourseRegistration(teacher->getAssignedCourse(0), i);
															teacher->UpdateAttendance(dep->getRequiredStudent(j)->getRigisteredCourse(dep->getRequiredStudent(j)->getRegistration_Count() - 1));
															//cout << dep->getRequiredStudent(j)->getRigisteredCourse(dep->getRequiredStudent(j)->getRegistration_Count() - 1)->getReg()->getGrade() << endl;
														}
														cout << "			Attendance of all Students is marked Successfully! " << endl;
													}
													//return to login page
													int null = -1;
													for (int w = 0; w != null; w++) {
														cout << endl << "					->Press 'X' to veiw previous page__";
														char input;
														cin >> input;
														if (input == 'X' || input == 'x') {
															clock = clock1 - 1;
															w = null - 1;
														}
														else {
															cout << "					wrong key is pressed...Try Again" << endl;
														}
													}
												}
												if (after_portal5 == 'W' || after_portal5 == 'w') {
													//view attendance
													system("cls");
													cout << endl << " ______________________________________________________________________________________________________________________" << endl;
													cout << "|_____________________________________________View Attendance of Students___________________________________________|" << endl;
													cout << endl << endl;
													//check if teacher is assigned course
													if (teacher->getCurrentTcourse() == 0) {
														cout << endl << "					This Teacher is not Assigned any Course from HOD..." << endl;
														cout << "						First assign him a specific Course" << endl;
													}
													else {
														//if assigned then view attendace in that course
														char* idee = teacher->getAssignedCourse(0)->getID();
														cout << " Course_Name = " << teacher->getAssignedCourse(0)->getCourseName() << endl << endl << endl;
														bool check = false;
														for (int j = 0; j < dep->getTotalStudents(); j++) {
															for (int m = 0; m < dep->getRequiredStudent(j)->getRegistration_Count(); m++) {
																char* idee2 = dep->getRequiredStudent(j)->getRigisteredCourse(m)->getID();
																if (idee[0] == idee2[0] && idee[1] == idee2[1] && idee[2] == idee2[2] && idee[3] == idee2[3]) {
																	if (dep->getRequiredStudent(j)->getRigisteredCourse(m)->getReg()->geteCurrentAttendance() != 0) {
																		check = true;
																	}
																}
															}
														}
														if (check == false) {
															cout << "					Teacher has not Update Attendance yet" << endl;
														}
														else {
															for (int j = 0; j < dep->getTotalStudents(); j++) {
																for (int m = 0; m < dep->getRequiredStudent(j)->getRegistration_Count(); m++) {
																	char* idee2 = dep->getRequiredStudent(j)->getRigisteredCourse(m)->getID();
																	if (idee[0] == idee2[0] && idee[1] == idee2[1] && idee[2] == idee2[2] && idee[3] == idee2[3]) {
																		int number;
																		cout << "						" << dep->getRequiredStudent(j)->getRollNum() << "	";
																		cout << dep->getRequiredStudent(j)->getPersonName() << endl << endl;
																		number = dep->getRequiredStudent(j)->getRigisteredCourse(m)->getReg()->geteCurrentAttendance();
																		for (int p = 0; p < number; p++) {
																			cout << "					Lecture_" << p + 1 << "	 ";
																			cout << p + 1 << "-" << "08-2020" << "	";
																			cout << dep->getRequiredStudent(j)->getRigisteredCourse(m)->getReg()->getMarkedAttendance(p) << endl;
																		}
																		cout << endl;
																	}
																}
															}
														}
													}
													int null = -1;
													for (int w = 0; w != null; w++) {
														cout << endl << "					->Press 'X' to veiw previous page__";
														char input;
														cin >> input;
														if (input == 'X' || input == 'x') {
															clock = clock1 - 1;
															w = null - 1;
														}
														else {
															cout << "					wrong key is pressed...Try Again" << endl;
														}
													}
												}
												if (after_portal5 == 'D' || after_portal5 == 'd') {
													//Manage evaluations of Students
													system("cls");
													cout << endl << " ______________________________________________________________________________________________________________________" << endl;
													cout << "|____________________________________________Manage Evaluations of Students__________________________________________|" << endl;
													cout << endl << endl << endl;
													//check if teacher is assigned course
													if (teacher->getCurrentTcourse() == 0) {
														cout << endl << "					This Teacher is not Assigned any Course from HOD..." << endl;
														cout << "						First assign him a specific Course" << endl;
													}
													else {
														//if assigned then enter marks in each test
														cout << " Course_Name = " << teacher->getAssignedCourse(0)->getCourseName() << endl;
														cout << " Total Quizzes = " << teacher->getAssignedCourse(0)->getTotalQuiz() << endl;
														cout << " Total Assignments = " << teacher->getAssignedCourse(0)->getTotalAssignments() << endl << endl;
														for (int j = 0; j < dep->getTotalStudents(); j++) {
															cout << "		Student_Name = " << dep->getRequiredStudent(j)->getPersonName() << endl;
															cout << "		Student_ID  = " << dep->getRequiredStudent(j)->getRollNum() << endl;
															cout << "		Department = " << dep->getName() << endl;
															cout << endl;
															dep->getRequiredStudent(j)->setQuiz_list();
															cout << endl;
															dep->getRequiredStudent(j)->setAssignment_list();
															cout << endl;
														}
														cout << "					All Students are given Marks Successfully! " << endl;
														//save evaluations to Marks.txt file
														ofstream marks;
														marks.open("Marks.txt");
														marks << " Course_Name = " << teacher->getAssignedCourse(0)->getCourseName() << endl << endl;
														for (int j = 0; j < dep->getTotalStudents(); j++) {
															marks << "						" << dep->getRequiredStudent(j)->getRollNum() << "	";
															marks << dep->getRequiredStudent(j)->getPersonName() << endl << endl;
															for (int g = 0; g < 3; g++) {
																marks << "		Quiz_" << g + 1 << endl;
																marks << "				obtained Marks = " << dep->getRequiredStudent(j)->getRequiredQuiz(g);
																marks << "		Total Marks = 10 " << endl << endl;
																marks << endl << endl;
																marks << "		Assignment_" << g + 1 << endl;
																marks << "				obtained Marks = " << dep->getRequiredStudent(j)->getRequiredAssignment(g);
																marks << "		Total Marks = 50 " << endl << endl;
															}
														}

													}
													//return to login page
													int null = -1;
													for (int w = 0; w != null; w++) {
														cout << endl << "					->Press 'X' to veiw previous page__";
														char input;
														cin >> input;
														if (input == 'X' || input == 'x') {
															clock = clock1 - 1;
															w = null - 1;
														}
														else {
															cout << "					wrong key is pressed...Try Again" << endl;
														}
													}
												}
												if (after_portal5 == 'F' || after_portal5 == 'f') {
													//View evaluations of Students
													system("cls");
													cout << endl << " ______________________________________________________________________________________________________________________" << endl;
													cout << "|____________________________________________View Evaluations of Students__________________________________________|" << endl;
													cout << endl << endl << endl;
													//check whether this teacher is assigned course or not
													if (teacher->getCurrentTcourse() == 0) {
														cout << endl << "					This Teacher is not Assigned any Course from HOD..." << endl;
														cout << "						First assign him a specific Course" << endl;
													}
													//if coursed is assigned then whether evaluation is done or not
													else if (dep->getRequiredStudent(0)->getQuiz_list() == -1 && dep->getRequiredStudent(0)->getAssignment_list() == -1) {
														cout << endl << endl << "					Teacher has not updated any evaluation yet! " << endl;
													}
													else {
														//if evaluation is done then show results of class
														for (int j = 0; j < dep->getTotalStudents(); j++) {
															cout << "						" << dep->getRequiredStudent(j)->getRollNum() << "	";
															cout << dep->getRequiredStudent(j)->getPersonName() << endl << endl;
															dep->getRequiredStudent(j)->ShowMarksheet();
														}

													}
													//return to login portal
													int null = -1;
													for (int w = 0; w != null; w++) {
														cout << endl << "					->Press 'X' to veiw previous page__";
														char input;
														cin >> input;
														if (input == 'X' || input == 'x') {
															clock = clock1 - 1;
															w = null - 1;
														}
														else {
															cout << "					wrong key is pressed...Try Again" << endl;
														}
													}
												}
											}
											catch (int n) {
												//Assign Grades to Students
												system("cls");
												cout << endl << " ______________________________________________________________________________________________________________________" << endl;
												cout << "|________________________________________________Assign Grades to Students______________________________________________|" << endl;
												cout << endl << endl << endl;
												//check if the teacher is assigned this course or not
												if (teacher->getCurrentTcourse() == 0) {
													cout << endl << "					This Teacher is not Assigned any Course from HOD..." << endl;
													cout << "						First assign him a specific Course" << endl;
												}
												else {
													//assign grades
													for (int j = 0; j < dep->getTotalStudents(); j++) {
														cout << " Student_Name = " << dep->getRequiredStudent(j)->getPersonName() << endl;
														cout << " Student_ID  = " << dep->getRequiredStudent(j)->getRollNum() << endl;
														cout << " Course_Name = " << teacher->getAssignedCourse(0)->getCourseName() << endl;
														cout << " Department = " << dep->getName() << endl;
														cout << endl << endl;
														dep->getRequiredStudent(j)->CourseRegistration(teacher->getAssignedCourse(0), i);
														teacher->AssignGrade(dep->getRequiredStudent(j)->getRigisteredCourse(dep->getRequiredStudent(j)->getRegistration_Count() - 1));

													}
													cout << "					All Students are given Grades Successfully! " << endl;
													//update file of Grades
													ofstream grade;
													grade.open("Grades.txt");
													grade << "Student_ID/Student_Name/Grade" << endl << endl;
													grade << " Course_Name = " << teacher->getAssignedCourse(0)->getCourseName() << endl << endl;
													for (int g = 0; g < dep->getTotalStudents(); g++) {
														grade << "		" << dep->getRequiredStudent(g)->getRollNum() << "		";
														grade << dep->getRequiredStudent(g)->getPersonName() << "		";
														grade << dep->getRequiredStudent(g)->getRigisteredCourse(dep->getRequiredStudent(g)->getRegistration_Count() - 1)->getReg()->getGrade() << endl << endl;
													}
													grade.close();
												}
												//return to login portal
												int null = -1;
												for (int w = 0; w != null; w++) {
													cout << endl << "					->Press 'X' to veiw previous page__";
													char input;
													cin >> input;
													if (input == 'X' || input == 'x') {
														clock = clock1 - 1;
														w = null - 1;
													}
													else {
														cout << "					wrong key is pressed...Try Again" << endl;
													}
												}
											}
										}
									}
								}
							}
						}
					}
					//check whether the entered ID matches university Manager's IDs or not
					else if (len == 3) {
						//IT_Manager Portal
						for (int i = 0; i < totaldep; i++) {
							Department* dep = university.getRequiredDep(i);
							Manager* manager = dep->getManager();
							char* id = manager->getEmployeeID();
							if (login[0] == id[0] && login[1] == id[1] && login[2] == id[2]) {
								int clock1 = -1;
								for (int clock = 0; clock != clock1; clock++) {
									system("cls");
									cout << endl << " ______________________________________________________________________________________________________________________" << endl;
									cout << "|_____________________________________________________MANAGER PORTAL_________________________________________________|" << endl;
									cout << endl << endl << " Manager_Name = ";
									cout << manager->getPersonName() << endl;
									cout << " Manager_ID  = " << id << endl;
									cout << " Department = " << dep->getName() << endl;
									cout << endl << endl;
									cout << "					->Press 'A' to crete account of Teacher" << endl;
									cout << endl << "					->Press'S' to delete account of Teacher" << endl;
									cout << endl << "					->Press 'D' to crete account of Student" << endl;
									cout << endl << "					->Press'F' to delete account of Student" << endl;
									cout << endl << "					->Press 'M' to maintain account of Teacher(change password)" << endl;
									cout << endl << "					->Press 'N' to maintain account of Student(change password)" << endl;
									a = b - 1;
									//cout << endl << endl << " Press 'B' to view previous page" << endl;
									cout << endl << "					Press selected Alphabet then press ENTER__ ";
									//Input Alphabet to perform specific task of Manager
									cin >> after_portal;
									try {
										//Create new account of teacher
										if (after_portal == 'A' || after_portal == 'a') {
											throw 5;
										}
										if (after_portal == 'S' || after_portal == 's') {
											//Delete account of teacher
											system("cls");
											cout << endl << " ______________________________________________________________________________________________________________________" << endl;
											cout << "|_______________________________________________Delete Account of Teacher_____________________________________________|" << endl;
											int d = -1;
											//check if the ID is valid
											cout << endl << endl << endl;
											for (int c = 0; c != d; c++) {
												bool check = false;
												char tempid[25];
												cout << endl << "						Enter existing ID = ";
												cin >> tempid;
												int length = 0;
												for (int j = 0; tempid[j] != '\0'; j++) {
													length++;
												}
												if (length > 3 || length < 3) {
													check = true;
													cout << "					ID must be a 3-digit number" << endl;
												}
												int count2 = 0;
												int index;
												if (length == 3) {
													for (int a = 0; a < dep->getTotalTeachers(); a++) {
														char* temp = dep->getRequiredTeacher(a)->getEmployeeID();
														if (temp[0] != tempid[0] || temp[1] != tempid[1] || temp[2] != tempid[2]) {
															check = true;
														}
														else {
															count2++;
															index = a;
														}
													}
													if (count2 > 0) {
														check = false;
													}
													else {
														cout << "				Entered ID does not exists...Enter existing data only!" << endl;
													}
												}
												//if ID is valid enter password
												if (count2 > 0) {
													c = d - 1;
													int f2 = -1;
													int pass = 0;
													for (int v = 0; v != f2; v++) {
														cout << "						Enter password = ";
														cin >> pass;
														if (pass != dep->getRequiredTeacher(index)->getPass()) {
															cout << "					Password is wrong... Try Again" << endl;
														}
														else {
															v = f2 - 1;
														}
													}
													//delete account
													dep->DeleteTeacher(tempid, pass);
													university.UpdateData();
													cout << endl << "					     Teacher Account is deleted";
													int null = -1;
													//return to login page
													for (int w = 0; w != null; w++) {
														cout << endl << "					 ->Press 'X' to veiw previous page__";
														char input;
														cin >> input;
														if (input == 'X' || input == 'x') {
															clock = clock1 - 1;
															w = null - 1;
														}
														else {
															cout << "					wrong key is pressed...Try Again" << endl;
														}
													}

												}
											}
										}
										if (after_portal == 'D' || after_portal == 'd') {
											//create new account of student
											system("cls");
											cout << endl << " ______________________________________________________________________________________________________________________" << endl;
											cout << "|_____________________________________________Create New Account for Student___________________________________________|" << endl;
											int d = -1;
											//check if ID is valid
											cout << endl << endl << endl;
											for (int c = 0; c != d; c++) {
												bool check = false;
												char tempid[25];
												cout << endl << "						Enter new ID = ";
												cin >> tempid;
												int length = 0;
												for (int j = 0; tempid[j] != '\0'; j++) {
													length++;
												}
												if (length > 4 || length < 4) {
													check = true;
													cout << "				ID must be a 4-digit number" << endl;
												}

												for (int a = 0; a < dep->getTotalStudents(); a++) {
													char* temp = dep->getRequiredStudent(a)->getRollNum();
													if (temp[0] == tempid[0] && temp[1] == tempid[1] && temp[2] == tempid[2] && temp[3] == tempid[3] && length == 4) {
														cout << "				Entered ID already exists...Create new data" << endl;
														a = dep->getTotalStudents();
														check = true;
													}
												}
												if (check == false) {
													c = d - 1;
													cout << "						Enter Name_";
													char name1[30];
													cin.ignore();
													cin.getline(name1, 30);
													cout << "						Enter password = ";
													int pass;
													cin >> pass;
													dep->AddNewStudent(tempid, name1, pass);
													university.UpdateData();
													cout << endl << "					     Student Account is created";
													int null = -1;
													//return to login page
													for (int w = 0; w != null; w++) {
														cout << endl << "					 ->Press 'X' to veiw previous page__";
														char input;
														cin >> input;
														if (input == 'X' || input == 'x') {
															clock = clock1 - 1;
															w = null - 1;
														}
														else {
															cout << "					wrong key is pressed...Try Again" << endl;
														}
													}
												}
											}
										}
										if (after_portal == 'F' || after_portal == 'f') {
											//Delete account of student
											system("cls");
											cout << endl << " ______________________________________________________________________________________________________________________" << endl;
											cout << "|_______________________________________________Delete Account of Student_____________________________________________|" << endl;
											int d = -1;
											cout << endl << endl << endl;
											//check if the ID is valid
											for (int c = 0; c != d; c++) {
												//bool check = false;
												char tempid[25];
												cout << endl << "						Enter existing ID = ";
												cin >> tempid;
												int length = 0;
												for (int j = 0; tempid[j] != '\0'; j++) {
													length++;
												}
												if (length > 4 || length < 4) {
													//check = true;
													cout << "					ID must be a 4-digit number" << endl;
												}
												int count2 = 0;
												int index;
												if (length == 4) {
													for (int a = 0; a < dep->getTotalStudents(); a++) {
														char* temp = dep->getRequiredStudent(a)->getRollNum();
														if (temp[0] != tempid[0] || temp[1] != tempid[1] || temp[2] != tempid[2] || temp[3] != tempid[3]) {
															//check = true;

														}
														else {
															count2++;
															index = a;
														}
													}
													/*if (count2 > 0) {
														check = false;
													}*/
													if (count2 < 1) {
														cout << "				Entered ID does not exists...Enter existing data only!" << endl;
													}
												}
												if (count2 > 0) {
													c = d - 1;
													int f2 = -1;
													int pass = 0;
													for (int v = 0; v != f2; v++) {
														cout << "						Enter password = ";
														cin >> pass;
														if (pass != dep->getRequiredStudent(index)->getStuPass()) {
															cout << "					Password is wrong... Try Again" << endl;
														}
														else {
															v = f2 - 1;
														}
													}
													//delete account
													dep->DeleteStudent(tempid, pass);
													university.UpdateData();
													cout << endl << "					     Student Account is deleted";
													int null = -1;
													//return to login page
													for (int w = 0; w != null; w++) {
														cout << endl << "					 ->Press 'X' to veiw previous page__";
														char input;
														cin >> input;
														if (input == 'X' || input == 'x') {
															clock = clock1 - 1;
															w = null - 1;
														}
														else {
															cout << "					wrong key is pressed...Try Again" << endl;
														}
													}
												}
											}
										}
										if (after_portal == 'M' || after_portal == 'm') {
											//Change Password of teacher
											system("cls");
											cout << endl << " ______________________________________________________________________________________________________________________" << endl;
											cout << "|_____________________________________________Maintain Account of Teacher___________________________________________|" << endl;
											int d = -1;
											cout << endl << endl << endl;
											//check if the ID is valid
											for (int c = 0; c != d; c++) {
												bool check = false;
												char tempid[25];
												cout << endl << "						Enter existing ID = ";
												cin >> tempid;
												int length = 0;
												for (int j = 0; tempid[j] != '\0'; j++) {
													length++;
												}
												if (length > 3 || length < 3) {
													check = true;
													cout << "					ID must be a 3-digit number" << endl;
												}
												int count2 = 0;
												int index;
												if (length == 3) {
													for (int a = 0; a < dep->getTotalTeachers(); a++) {
														char* temp = dep->getRequiredTeacher(a)->getEmployeeID();
														if (temp[0] != tempid[0] || temp[1] != tempid[1] || temp[2] != tempid[2]) {
															check = true;
														}
														else {
															count2++;
															index = a;
														}
													}
													if (count2 > 0) {
														check = false;
													}
													else {
														cout << "				Entered ID does not exists...Enter existing data only!" << endl;
													}
												}
												if (count2 > 0) {
													c = d - 1;
													int f2 = -1;
													int pass = 0;
													for (int v = 0; v != f2; v++) {
														cout << "						Enter Current Password = ";
														cin >> pass;
														if (pass != dep->getRequiredTeacher(index)->getPass()) {
															cout << "					Password is wrong... Try Again" << endl;
														}
														else {
															v = f2 - 1;
														}
													}
													cout << endl << "					Enter New Password then Press Enter key = ";
													int passw;
													cin >> passw;
													dep->getRequiredTeacher(index)->setPass(passw);
													cout << endl << "						New Password is set successfully! " << endl;
													university.UpdateData();
													//return to login page
													int null = -1;
													for (int w = 0; w != null; w++) {
														cout << endl << "					 ->Press 'X' to veiw previous page__";
														char input;
														cin >> input;
														if (input == 'X' || input == 'x') {
															clock = clock1 - 1;
															w = null - 1;
														}
														else {
															cout << "					wrong key is pressed...Try Again" << endl;
														}
													}
												}
											}
										}
										if (after_portal == 'N' || after_portal == 'n') {
											//Change Password of student
											system("cls");
											cout << endl << " ______________________________________________________________________________________________________________________" << endl;
											cout << "|_______________________________________________Maintain Account of Student_____________________________________________|" << endl;
											int d = -1;
											cout << endl << endl << endl;
											//check if the ID is valid
											for (int c = 0; c != d; c++) {
												//bool check = false;
												char tempid[25];
												cout << endl << "						Enter existing ID = ";
												cin >> tempid;
												int length = 0;
												for (int j = 0; tempid[j] != '\0'; j++) {
													length++;
												}
												if (length > 4 || length < 4) {
													//check = true;
													cout << "					ID must be a 4-digit number" << endl;
												}
												int count2 = 0;
												int index;
												if (length == 4) {
													for (int a = 0; a < dep->getTotalStudents(); a++) {
														char* temp = dep->getRequiredStudent(a)->getRollNum();
														if (temp[0] != tempid[0] || temp[1] != tempid[1] || temp[2] != tempid[2] || temp[3] != tempid[3]) {
															//check = true;

														}
														else {
															count2++;
															index = a;
														}
													}
													/*if (count2 > 0) {
														check = false;
													}*/
													if (count2 < 1) {
														cout << "				Entered ID does not exists...Enter existing data only!" << endl;
													}
												}
												if (count2 > 0) {
													c = d - 1;
													int f2 = -1;
													int pass = 0;
													for (int v = 0; v != f2; v++) {
														cout << "						Enter Current Password = ";
														cin >> pass;
														if (pass != dep->getRequiredStudent(index)->getStuPass()) {
															cout << "					Password is wrong... Try Again" << endl;
														}
														else {
															v = f2 - 1;
														}
													}
													cout << endl << "					Enter New Password then Press Enter key = ";
													int passw;
													cin >> passw;
													dep->getRequiredStudent(index)->setStuPass(passw);
													cout << endl << "					New Password is set successfully! " << endl;
													university.UpdateData();
													//return to login page
													int null = -1;
													for (int w = 0; w != null; w++) {
														cout << endl << "					 ->Press 'X' to veiw previous page__";
														char input;
														cin >> input;
														if (input == 'X' || input == 'x') {
															clock = clock1 - 1;
															w = null - 1;
														}
														else {
															cout << "					wrong key is pressed...Try Again" << endl;
														}
													}
												}
											}
										}
										else {
											throw "hello";
										}
									}
									catch (int n) {
										//create new account of teacher
										system("cls");
										cout << endl << " ______________________________________________________________________________________________________________________" << endl;
										cout << "|_____________________________________________Create New Account for Teacher___________________________________________|" << endl;
										int d = -1;
										cout << endl << endl << endl;
										for (int c = 0; c != d; c++) {
											bool check = false;
											char tempid[25];
											cout << endl << "						Enter new ID = ";
											cin >> tempid;
											int length = 0;
											for (int j = 0; tempid[j] != '\0'; j++) {
												length++;
											}
											if (length > 3 || length < 3) {
												check = true;
												cout << "				ID must be a 3-digit number" << endl;
											}
											if (length == 3) {
												if (tempid[0] != tempid[1] || tempid[1] != tempid[2] || tempid[0] != tempid[2]) {
													check = true;
													cout << "			All 3 digits of ID must be same eg. 111" << endl;
												}
											}
											for (int a = 0; a < dep->getTotalTeachers(); a++) {
												char* temp = dep->getRequiredTeacher(a)->getEmployeeID();
												if (temp[0] == tempid[0] && temp[1] == tempid[1] && temp[2] == tempid[2] && length == 3) {
													cout << "				Entered ID already exists...Create new data" << endl;
													a = dep->getTotalTeachers();
													check = true;
												}
											}
											if (check == false) {
												c = d - 1;
												cout << "						Enter Name_";
												char name1[30];
												cin.ignore();
												cin.getline(name1, 30);
												cout << "						Enter password = ";
												int pass;
												cin >> pass;
												dep->AddNewTeacher(tempid, name1, pass);
												university.UpdateData();
												cout << endl << "					     Teacher Account is created";
												int null = -1;
												for (int w = 0; w != null; w++) {
													cout << endl << "					 ->Press 'X' to veiw previous page__";
													char input;
													cin >> input;
													if (input == 'X' || input == 'x') {
														clock = clock1 - 1;
														w = null - 1;
													}
													else {
														cout << "					wrong key is pressed...Try Again" << endl;
													}
												}
											}
										}
									}
									catch (...) {
										//cout << "You have pressed wrong key" << endl;
										clock = clock1 - 1;
									}

								}

							}
						}
					}
				}
				catch (...) {
					//cout << endl << "					Invalid ID or Password";
				}
			}
			//opens login page again
		}
	}
	system("PAUSE");
	return 0;
}