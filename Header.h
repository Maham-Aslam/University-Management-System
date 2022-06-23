#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class Person {
	char* first_name;
public:
	Person();
	Person(char[]);
	Person(const Person&);
	char* getPersonName();
	virtual void show() = 0;
	virtual void print() {
		cout << "Name = " << first_name << endl;
	}
	virtual ~Person() {
		delete[]first_name;
	}
};
class Employee :public Person {
	char* id;
public:
	Employee() :Person(0) {
		id = 0;
	}
	Employee(char idee[], char f[]) :Person(f) {
		int len = 0;
		for (int i = 0; idee[i] != '\0'; i++) {
			len++;
		}
		id = new char[len + 1];
		for (int i = 0; i <= len; i++) {
			id[i] = idee[i];
		}
	}
	Employee(const Employee& obj) {
		id = obj.id;
	}
	char* getEmployeeID() {
		return id;
	}
	void show() {
		cout << "Employee_ID = " << id << endl;
	}
	void print() {
		Person::print();
		cout << "Employee_ID = " << id << endl;
	}
	virtual ~Employee() {
		delete[]id;
	}
};
class Registration {
	char grade;
	char* attendance_list;
	int current_attendance;
public:
	Registration() {
		grade = '0';
		attendance_list = nullptr;
		current_attendance = 0;
	}
	Registration(char g) {
		grade = g;
		attendance_list = new char[14];
		current_attendance = 0;
	}
	void setGrade(char g) {
		grade = g;
	}
	char getGrade() {
		return grade;
	}
	int geteCurrentAttendance() {
		return current_attendance;
	}
	char getMarkedAttendance(int n) {
		return attendance_list[n];
	}
	void setAttendance(char n) {
		attendance_list[current_attendance++] = n;
	}
};
class Course {
	char* course_name;
	char* course_id;
	Registration* reg;
	static int course_count;
	static int totalquizzes;
	static int totalassignments;
public:
	Course();
	Course(char[], char[]);
	char* getCourseName();
	char* getID();
	Registration* getReg() {
		return reg;
	}
	int getTotalQuiz() {
		return totalquizzes;
	}
	int getTotalAssignments() {
		return totalassignments;
	}
};
class Manager :public Employee {

public:
	Manager() :Employee(0, 0) {}
	Manager(char idee[], char f[]) :Employee(idee, f) {}
	~Manager() {}
};
class Student :public Person {
	char* rollnum;
	int pass;
	static int student_count;
	Course** registered_courses;
	int current_registration;
	float quiz_list[3];
	float assignment_list[3];
public:
	Student(char roll[], char f[]) :Person(f) {
		registered_courses = new Course * [4];
		current_registration = 0;
		student_count++;
		pass = 0;
		int len = 0;
		for (int i = 0; roll[i] != '\0'; i++) {
			len++;
		}
		rollnum = new char[len + 2];
		quiz_list[3];
		for (int i = 0; i <= len; i++) {
			rollnum[i] = roll[i];
		}
		assignment_list[3];
		for (int i = 0; i < 3; i++) {
			quiz_list[i] = -1;
			assignment_list[i] = -1;
		}
	}
	char* getRollNum() {
		return rollnum;
	}
	void setStuPass(int id) {
		pass = id;
	}
	int getStuPass() {
		return pass;
	}
	int getRegistration_Count() {
		return current_registration;
	}
	Course* getRigisteredCourse(int n) {
		return registered_courses[n];
	}
	void setQuiz_list();
	void setAssignment_list();
	bool CourseRegistration(Course*, int);
	bool CourseUnregistration(Course*, int);
	bool CourseWithdraw(Course*, int);
	float getQuiz_list() {
		return quiz_list[0];
	}
	float getAssignment_list() {
		return assignment_list[0];
	}
	float getRequiredQuiz(int n) {
		return quiz_list[n];
	}
	float getRequiredAssignment(int n) {
		return assignment_list[n];
	}
	void ShowMarksheet();
	void show() {
		cout << "Student_ID = " << rollnum << endl;
	}
	void print() {
		Person::print();
		cout << "Student_ID = " << rollnum << endl;
	}
	~Student() {
		delete[]rollnum;
	}
};
class Teacher :public Employee {
	int Tpassword;
	Course** assigned_courses;
	int current_Tcourses;
	static int teacher_count;
public:
	Teacher() :Employee(0, 0) {
		Tpassword = 0;
		assigned_courses = nullptr;
		current_Tcourses = 0;
	}
	Teacher(char idee[], char f[]) :Employee(idee, f) {
		teacher_count++;
		assigned_courses = new Course * [0];
		current_Tcourses = 0;
		Tpassword = 0;
	}
	void setPass(int id) {
		Tpassword = id;
	}
	int getPass() {
		return Tpassword;
	}
	int getCurrentTcourse() {
		return current_Tcourses;
	}
	Course* getAssignedCourse(int n) {
		return assigned_courses[n];
	}
	bool AssignedCourse(Course*, int);
	void AssignGrade(Course*);
	void UpdateAttendance(Course*);
	~Teacher() {}
};
class HOD :public Employee {
	int Hpass;
public:
	HOD() :Employee(0, 0) {
		Hpass = 0;
	}
	HOD(char idee[], char name[]) :Employee(idee, name) {
		Hpass = 0;
	}
	void setHOD_pass(int n) {
		Hpass = n;
	}
	int getHOD_pass() {
		return Hpass;
	}
	bool CourseRegistration(Student*, Course*, int);
	bool CourseUnregistration(Student*, Course*, int);
	bool CourseAssigned(Teacher*, Course*, int);
	~HOD() {}
};
class Department {
	char* dep_name;
	int total_courses;
	Course** course_list;
	int current_count;
	Teacher** teacher_list;
	int total_teachers;
	int current_teachers;
	Manager* IT_manager;
	Student** student_list;
	int total_students;
	int current_students;
	HOD* hod;
	static int depart_count;
public:
	Department();
	Department(char[], int);
	int getTotalCourses();
	char* getName();
	void AddCourseData(char[], char[]);
	void setTotalTeachers(int);
	int getTotalTeachers();
	void Add_TeachersData(char[], char[]);
	void setManager(char[], char[]);
	Manager* getManager();
	void setTotalStudents(int);
	int getTotalStudents();
	void Add_StudentsData(char[], char[]);
	void setHOD(char[], char[]);
	Student* getRequiredStudent(int);
	Teacher* getRequiredTeacher(int);
	Course* getRequuiredCourse(int);
	void AddNewTeacher(char[], char[], int);
	void AddNewStudent(char[], char[], int);
	void PassRecord(int, int);
	HOD* getDepHOD(int);
	void setHOD_pass(int, int);
	void PassRecordStudent(int, int);
	void DeleteTeacher(char[], int);
	void DeleteStudent(char[], int);
	Department& operator = (const Department&);
	~Department() {
		delete[]dep_name;
	}
};
class University {
	char* uni_name;
	int total_dep;
	Department** dep_list;
	int current_depcount;
public:
	University();
	University(const char[]);
	University(const University& obj);
	void setUniName(char[]);
	char* getUniName();
	void setTotalDep(int);
	int getTotalDep();
	Department* Add_DepData(char[], int);
	Department* getRequiredDep(int);
	Department getDepObj(Department*);
	void UpdateData();
	~University();
};

int Student::student_count = 0;
int Teacher::teacher_count = 0;
int Department::depart_count = 0;
int Course::course_count = 0;
int Course::totalassignments = 3;
int Course::totalquizzes = 3;

Person::Person() {
	first_name = nullptr;
}
Person::Person(char first[]) {
	int len = 0;
	for (int i = 0; first[i] != '\0'; i++) {
		len++;
	}
	first_name = new char[len + 1];
	for (int i = 0; i <= len; i++) {
		first_name[i] = first[i];
	}

}
Person::Person(const Person& obj) {
	first_name = obj.first_name;
}
char* Person::getPersonName() {
	return first_name;
}
//Person::~Person() {
//	delete[]first_name;
//}

Course::Course() {
	reg = nullptr;
	course_name = nullptr;
	course_id = nullptr;
}
Course::Course(char idee[], char name[]) {
	course_count++;
	reg = new Registration('0');
	int len = 0;
	for (int i = 0; idee[i] != '\0'; i++) {
		len++;
	}
	course_id = new char[len + 1];
	for (int i = 0; i <= len; i++) {
		course_id[i] = idee[i];
	}
	len = 0;
	for (int i = 0; name[i] != '\0'; i++) {
		len++;
	}
	course_name = new char[len + 1];
	for (int i = 0; i <= len; i++) {
		course_name[i] = name[i];
	}
}
char* Course::getID() {
	return course_id;
}
char* Course::getCourseName() {
	return course_name;
}

bool HOD::CourseRegistration(Student* s, Course* c, int num) {
	bool check;
	return check = s->CourseRegistration(c, num);
}
bool HOD::CourseUnregistration(Student* s, Course* c, int num) {
	bool check;
	return check = s->CourseUnregistration(c, num);
}
bool HOD::CourseAssigned(Teacher* t, Course* c, int num) {
	bool check;
	return check = t->AssignedCourse(c, num);
}

bool Student::CourseRegistration(Course* c, int num) {
	if (current_registration == 5) {
		return false;
	}
	char* temp = c->getID();
	for (int i = 0; i < current_registration; i++) {
		char* temp2 = registered_courses[i]->getID();
		if (temp[0] == temp2[0] && temp[1] == temp2[1] && temp[2] == temp2[2] && temp[3] == temp2[3]) {
			return false;
		}
	}
	registered_courses[current_registration++] = new Course(c->getID(), c->getCourseName());
	return true;
}

bool Student::CourseUnregistration(Course* c, int num) {
	if (current_registration == 0) {
		return false;
	}
	char* temp = c->getID();
	int index = -1;
	for (int i = 0; i < current_registration; i++) {
		char* temp2 = registered_courses[i]->getID();
		if (temp[0] == temp2[0] && temp[1] == temp2[1] && temp[2] == temp2[2] && temp[3] == temp2[3]) {
			index = i;
		}
	}
	if (index == -1) {
		return false;
	}
	else {
		Course** temp_list = new Course * [current_registration - 1];
		for (int i = 0; i < index; i++) {
			temp_list[i] = new Course(registered_courses[i]->getID(), registered_courses[i]->getCourseName());
		}
		for (int i = index; i < current_registration - 1; i++) {
			temp_list[i] = new Course(registered_courses[i + 1]->getID(), registered_courses[i + 1]->getCourseName());
		}
		/*for (int i = 0; i < current_registration; i++) {
			delete[]registered_courses[i];
		}*/
		registered_courses = nullptr;
		current_registration = current_registration - 1;
		registered_courses = new Course * [current_registration];
		for (int i = 0; i < current_registration; i++) {
			registered_courses[i] = new Course(temp_list[i]->getID(), temp_list[i]->getCourseName());
		}
		/*for (int i = 0; i < current_registration; i++) {
			delete[]temp_list[i];
		}*/
		delete[]temp_list;
		return true;
	}
}
bool Student::CourseWithdraw(Course* c, int num) {
	if (current_registration == 0) {
		return false;
	}
	char* temp = c->getID();
	int index = -1;
	for (int i = 0; i < current_registration; i++) {
		char* temp2 = registered_courses[i]->getID();
		if (temp[0] == temp2[0] && temp[1] == temp2[1] && temp[2] == temp2[2] && temp[3] == temp2[3]) {
			index = i;
		}
	}
	if (index == -1) {
		return false;
	}
	else {
		Course** temp_list = new Course * [current_registration - 1];
		for (int i = 0; i < index; i++) {
			temp_list[i] = new Course(registered_courses[i]->getID(), registered_courses[i]->getCourseName());
		}
		for (int i = index; i < current_registration - 1; i++) {
			temp_list[i] = new Course(registered_courses[i + 1]->getID(), registered_courses[i + 1]->getCourseName());
		}
		/*for (int i = 0; i < current_registration; i++) {
			delete[]registered_courses[i];
		}*/
		registered_courses = nullptr;
		current_registration = current_registration - 1;
		registered_courses = new Course * [current_registration];
		for (int i = 0; i < current_registration; i++) {
			registered_courses[i] = new Course(temp_list[i]->getID(), temp_list[i]->getCourseName());
		}
		/*for (int i = 0; i < current_registration; i++) {
			delete[]temp_list[i];
		}*/
		delete[]temp_list;
		return true;
	}
}
void Student::setQuiz_list() {
	float q;
	for (int i = 0; i < 3; i++) {
		int a = -1;
		for (int b = 0; b != a; b++) {
			cout << "					Marks of Quiz_" << i + 1 << " = ";
			cin >> q;
			if (q >= 0 && q <= 10) {
				b = a - 1;
				quiz_list[i] = q;
			}
			else {
				cout << "					You have entered wrong marks...Try Again" << endl << endl;
			}
		}
	}
}
void Student::setAssignment_list() {
	float q;
	for (int i = 0; i < 3; i++) {
		int a = -1;
		for (int b = 0; b != a; b++) {
			cout << "					Marks of Assignment_" << i + 1 << " = ";
			cin >> q;
			if (q >= 0 && q <= 50) {
				b = a - 1;
				assignment_list[i] = q;
			}
			else {
				cout << "					You have entered wrong marks...Try Again" << endl << endl;
			}
		}
	}
}
void Student::ShowMarksheet() {
	for (int i = 0; i < 3; i++) {
		cout << "		Quiz_" << i + 1 << endl;
		cout << "				obtained Marks = " << quiz_list[i];
		cout << "		Total Marks = 10 " << endl << endl;
	}
	cout << endl << endl;
	for (int i = 0; i < 3; i++) {
		cout << "		Assignment_" << i + 1 << endl;
		cout << "				obtained Marks = " << assignment_list[i];
		cout << "		Total Marks = 50 " << endl << endl;
	}
}

bool Teacher::AssignedCourse(Course* c, int num) {
	if (current_Tcourses == 1) {
		return false;
	}
	char* temp = c->getID();
	for (int i = 0; i < current_Tcourses; i++) {
		char* temp2 = assigned_courses[i]->getID();
		if (temp[0] == temp2[0] && temp[1] == temp2[1] && temp[2] == temp2[2] && temp[3] == temp2[3]) {
			return false;
		}
	}
	assigned_courses[current_Tcourses++] = new Course(c->getID(), c->getCourseName());
	return true;
}
void Teacher::AssignGrade(Course* c) {
	char str;
	int b = -1;
	for (int a = 0; a != b; a++) {
		if (a != 0) {
			cout << "			Choose between grades A, B, C, D and F only!" << endl;
		}
		cout << "					Press selected Grade then press ENTER__ ";
		char grade;
		cin >> grade;
		if (grade == 'A' || grade == 'B' || grade == 'C' || grade == 'D' || grade == 'F') {
			a = b - 1;
			str = grade;
		}
		if (grade == 'a' || grade == 'b' || grade == 'c' || grade == 'd' || grade == 'f') {
			a = b - 1;
			str = grade;
		}
	}
	c->getReg()->setGrade(str - 32);
}
void Teacher::UpdateAttendance(Course* c) {
	if (c->getReg()->geteCurrentAttendance() == 15) {
		cout << "			All 15 Lectures are already marked" << endl;
	}
	else {
		char str;
		int b = -1;
		for (int a = 0; a != b; a++) {
			if (a != 0) {
				cout << "		Enter 'P' to mark present and 'A' to mark absent... These to keys are valid only!" << endl;
				cout << endl << "						";
			}
			cout << "		Attendance__ ";
			char grade;
			cin >> grade;
			if (grade == 'P' || grade == 'A' || grade == 'p' || grade == 'a') {
				a = b - 1;
				str = grade;
			}
		}
		c->getReg()->setAttendance(str - 32);
	}
}

Department::Department() {
	dep_name = nullptr;
	total_courses = 0;
	course_list = nullptr;
	current_count = 0;
	teacher_list = nullptr;
	total_teachers = 0;
	current_teachers = 0;
	IT_manager = nullptr;
	student_list = nullptr;
	total_students = 0;
	current_students = 0;
	hod = nullptr;
}
Department::Department(char name[], int total) {
	depart_count++;
	hod = nullptr;
	student_list = nullptr;
	total_students = 0;
	current_students = 0;
	IT_manager = nullptr;
	teacher_list = nullptr;
	total_teachers = 0;
	current_teachers = 0;
	total_courses = total;
	course_list = new Course * [total - 1];
	current_count = 0;
	int len = 0;
	for (int i = 0; name[i] != '\0'; i++) {
		len++;
	}
	dep_name = new char[len + 2];
	for (int i = 0; i <= len; i++) {
		dep_name[i] = name[i];
	}
}
char* Department::getName() {
	return dep_name;
}
int Department::getTotalCourses() {
	return total_courses;
}
void Department::AddCourseData(char idee[], char name[]) {
	course_list[current_count++] = new Course(idee, name);
}
void Department::setTotalTeachers(int n) {
	total_teachers = n;
	teacher_list = new Teacher * [total_teachers];
}
int Department::getTotalTeachers() {
	return total_teachers;
}
void Department::Add_TeachersData(char idee[], char name[]) {
	teacher_list[current_teachers++] = new Teacher(idee, name);
}
void Department::setManager(char idee[], char name[]) {
	IT_manager = new Manager(idee, name);
}
Manager* Department::getManager() {
	return IT_manager;
}
void Department::setTotalStudents(int n) {
	total_students = n;
	student_list = new Student * [total_students];
}
int Department::getTotalStudents() {
	return total_students;
}
void Department::Add_StudentsData(char idee[], char name[]) {
	student_list[current_students++] = new Student(idee, name);
}
void Department::setHOD(char idee[], char name[]) {
	hod = new HOD(idee, name);
}
Student* Department::getRequiredStudent(int n) {
	return student_list[n];
}
Teacher* Department::getRequiredTeacher(int n) {
	return teacher_list[n];
}
Course* Department::getRequuiredCourse(int n) {
	return course_list[n];
}
void Department::AddNewTeacher(char idee[], char name[], int pass) {
	int total = getTotalTeachers();
	Teacher** list = new Teacher * [total];
	for (int i = 0; i < total; i++) {
		list[i] = teacher_list[i];
	}
	teacher_list = nullptr;
	setTotalTeachers(total_teachers + 1);
	teacher_list = new Teacher * [total_teachers];
	current_teachers++;
	for (int i = 0; i < total_teachers - 1; i++) {
		teacher_list[i] = list[i];
	}
	teacher_list[total_teachers - 1] = new Teacher(idee, name);
	teacher_list[total_teachers - 1]->setPass(pass);
}
void Department::AddNewStudent(char idee[], char name[], int pass) {
	int total = getTotalStudents();
	Student** list = new Student * [total];
	for (int i = 0; i < total; i++) {
		list[i] = student_list[i];
	}
	student_list = nullptr;
	setTotalStudents(total_students + 1);
	student_list = new Student * [total_students];
	current_students++;
	for (int i = 0; i < total_students - 1; i++) {
		student_list[i] = list[i];
	}
	student_list[total_students - 1] = new Student(idee, name);
	student_list[total_students - 1]->setStuPass(pass);
}
void Department::DeleteTeacher(char id[], int pass) {
	int index = 0;
	for (int i = 0; i < total_teachers; i++) {
		char* temp = teacher_list[i]->getEmployeeID();
		if (temp[0] == id[0] && temp[1] == id[1] && temp[2] == id[2]) {
			index = i;
		}
	}
	Teacher** temp_list = new Teacher * [total_teachers - 1];
	for (int i = 0; i < index; i++) {
		temp_list[i] = new Teacher(getRequiredTeacher(i)->getEmployeeID(), getRequiredTeacher(i)->getPersonName());
		temp_list[i]->setPass(getRequiredTeacher(i)->getPass());
	}
	for (int i = index; i < total_teachers - 1; i++) {
		temp_list[i] = new Teacher(getRequiredTeacher(i + 1)->getEmployeeID(), getRequiredTeacher(i + 1)->getPersonName());
		temp_list[i]->setPass(getRequiredTeacher(i + 1)->getPass());
	}
	/*for (int i = 0; i < total_teachers; i++) {
		delete[]teacher_list[i];
	}*/
	teacher_list = nullptr;
	total_teachers = total_teachers - 1;
	current_teachers = current_teachers - 1;
	teacher_list = new Teacher * [total_teachers];
	for (int i = 0; i < total_teachers; i++) {
		teacher_list[i] = new Teacher(temp_list[i]->getEmployeeID(), temp_list[i]->getPersonName());
		teacher_list[i]->setPass(temp_list[i]->getPass());
	}
	/*for (int i = 0; i < total_teachers; i++) {
		delete[]temp_list[i];
	}*/
	delete[]temp_list;
}
void Department::DeleteStudent(char id[], int pass) {
	int index = 0;
	for (int i = 0; i < total_students; i++) {
		char* temp = student_list[i]->getRollNum();
		if (temp[0] == id[0] && temp[1] == id[1] && temp[2] == id[2] && temp[3] == id[3]) {
			index = i;
		}
	}
	Student** temp_list = new Student * [total_students - 1];
	for (int i = 0; i < index; i++) {
		temp_list[i] = new Student(getRequiredStudent(i)->getRollNum(), getRequiredStudent(i)->getPersonName());
		temp_list[i]->setStuPass(getRequiredStudent(i)->getStuPass());
	}
	for (int i = index; i < total_students - 1; i++) {
		temp_list[i] = new Student(getRequiredStudent(i + 1)->getRollNum(), getRequiredStudent(i + 1)->getPersonName());
		temp_list[i]->setStuPass(getRequiredStudent(i + 1)->getStuPass());
	}
	/*for (int i = 0; i < total_students; i++) {
		delete[]student_list[i];
	}*/
	student_list = nullptr;
	total_students = total_students - 1;
	current_students = current_students - 1;
	student_list = new Student * [total_students];
	for (int i = 0; i < total_students; i++) {
		student_list[i] = new Student(temp_list[i]->getRollNum(), temp_list[i]->getPersonName());
		student_list[i]->setStuPass(temp_list[i]->getStuPass());
	}
	/*for (int i = 0; i < total_students; i++) {
		delete[]temp_list[i];
	}*/
	delete[]temp_list;
}
void Department::PassRecord(int num, int pass) {
	getRequiredTeacher(num)->setPass(pass);
}
HOD* Department::getDepHOD(int n) {
	return hod;
}
void Department::setHOD_pass(int num, int pass) {
	getDepHOD(num)->setHOD_pass(pass);
}
void Department::PassRecordStudent(int num, int pass) {
	getRequiredStudent(num)->setStuPass(pass);
}
//Assignment Operator
Department& Department::operator = (const Department& obj) {
	int len = 0;
	for (int i = 0; obj.dep_name[i] != '\0'; i++) {
		len++;
	}
	dep_name = new char[len + 1];
	for (int i = 0; i <= len; i++) {
		dep_name[i] = obj.dep_name[i];
	}
	total_courses = obj.total_courses;
	current_count = 0;
	course_list = new Course * [total_courses];
	for (int i = 0; i < total_courses; i++) {
		AddCourseData(obj.course_list[i]->getID(), obj.course_list[i]->getCourseName());
	}
	current_teachers = 0;
	total_teachers = obj.total_teachers;
	teacher_list = new Teacher * [total_teachers];
	for (int i = 0; i < total_teachers; i++) {
		Add_TeachersData(obj.teacher_list[i]->getEmployeeID(), obj.teacher_list[i]->getPersonName());
		teacher_list[i]->setPass(obj.teacher_list[i]->getPass());
	}
	current_students = 0;
	total_students = obj.total_students;
	student_list = new Student * [total_students];
	for (int i = 0; i < total_students; i++) {
		Add_StudentsData(obj.student_list[i]->getRollNum(), obj.student_list[i]->getPersonName());
		student_list[i]->setStuPass(obj.student_list[i]->getStuPass());
	}
	hod = new HOD;
	setHOD(teacher_list[0]->getEmployeeID(), teacher_list[0]->getPersonName());
	setHOD_pass(0, teacher_list[0]->getPass());
	IT_manager = new Manager;
	setManager(obj.IT_manager->getEmployeeID(), obj.IT_manager->getPersonName());
	return *this;
}

University::University() {
	uni_name = nullptr;
	total_dep = 0;
	Department** dep_list = nullptr;
	current_depcount = 0;
}
University::University(const char name[]) {
	total_dep = 0;
	Department** dep_list = nullptr;
	current_depcount = 0;
	int len = 0;
	for (int i = 0; name[i] != '\0'; i++) {
		len++;
	}
	uni_name = new char[len + 2];
	for (int i = 0; i <= len; i++) {
		uni_name[i] = name[i];
	}
}
University::University(const University& obj) {
	int len = 0;
	for (int i = 0; obj.uni_name[i] != '\0'; i++) {
		len++;
	}
	uni_name = new char[len + 2];
	for (int i = 0; i <= len; i++) {
		uni_name[i] = obj.uni_name[i];
	}
}
void University::setUniName(char name[]) {
	int len = 0;
	for (int i = 0; name[i] != '\0'; i++) {
		len++;
	}
	uni_name = new char[len + 2];
	for (int i = 0; i <= len; i++) {
		uni_name[i] = name[i];
	}
}
char* University::getUniName() {
	return uni_name;
}
void University::setTotalDep(int n) {
	total_dep = n;
	dep_list = new Department * [total_dep - 1];
}
int University::getTotalDep() {
	return total_dep;
}
Department* University::Add_DepData(char depname[], int total) {
	Department* department = new Department(depname, total);
	dep_list[current_depcount] = department;
	return dep_list[current_depcount++];
}
Department* University::getRequiredDep(int n) {
	return dep_list[n];
}
Department University::getDepObj(Department* obj) {
	return *obj;
}
void University::UpdateData() {
	ofstream writes;
	writes.open("Passwords.txt");
	if (writes.is_open()) {
		writes << getUniName() << endl;
		writes << getTotalDep() << endl;
		for (int i = 0; i < getTotalDep(); i++) {
			writes << getRequiredDep(i)->getName() << endl;
			writes << getRequiredDep(i)->getTotalCourses() << endl;
			for (int j = 0; j < getRequiredDep(i)->getTotalCourses(); j++) {
				writes << getRequiredDep(i)->getRequuiredCourse(j)->getID() << ",";
				writes << getRequiredDep(i)->getRequuiredCourse(j)->getCourseName() << endl;
			}
			writes << getRequiredDep(i)->getTotalTeachers() << endl;
			for (int k = 0; k < getRequiredDep(i)->getTotalTeachers(); k++) {
				writes << getRequiredDep(i)->getRequiredTeacher(k)->getEmployeeID() << ",";
				writes << getRequiredDep(i)->getRequiredTeacher(k)->getPersonName() << ",";
				writes << getRequiredDep(i)->getRequiredTeacher(k)->getPass() << endl;
			}
			writes << "1" << endl;
			writes << getRequiredDep(i)->getManager()->getEmployeeID() << ",";
			writes << getRequiredDep(i)->getManager()->getPersonName() << endl;
			writes << getRequiredDep(i)->getTotalStudents() << endl;
			for (int k = 0; k < getRequiredDep(i)->getTotalStudents(); k++) {
				writes << getRequiredDep(i)->getRequiredStudent(k)->getRollNum() << ",";
				writes << getRequiredDep(i)->getRequiredStudent(k)->getPersonName() << ",";
				writes << getRequiredDep(i)->getRequiredStudent(k)->getStuPass() << endl;
			}
		}
	}
	writes.close();
}

University::~University() {
	delete[]uni_name;
}
