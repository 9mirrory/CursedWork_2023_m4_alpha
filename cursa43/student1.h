#pragma once
#include "idata1.h"

struct session
{
	string subj[9];
	int mark[9];
};

struct Student
{
	string surname;
	string name;
	string midname;
	string faculty;
	int birthDay;
	int birthMonth;
	int birthYear;
	int startYear;
	string sex;
	string group;
	string booknum;
	string inst;
	int c;
	session sess[10];
};

void addStudent();
void edit_student();
void delete_student();
void import_students();
void exercise();
void show_group();
void show_student();