#include "student1.h"

void addStudent()
{
	int j = 0, NumMarks, sesscount;
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	cout << "===================================" << endl;
	cout << "|  ���� ����� ������ �� ��������  |" << endl;
	cout << "===================================" << endl;
	cout << "������� ���-�� ���������: ";
	cin >> n;
	cin.get();
	string man = "�", woman = "�";
	Student* students = new Student[n];
	for (int i = 0; i < n; i++)
	{
		students[i].c = FALSE;
		ofstream out;
		out.open("studentInfo.bin", ios_base::app | ios_base::binary);
		cout << "������� ������ ������� " << i + 1 << "." << endl;
		cout << "������� �������: ";
		students[i].surname = istring();
		cout << "\n������� ���: ";
		students[i].name = istring();
		cout << "\n������� ��������: ";
		students[i].midname = istring();
		cout << "\n������� ��� ��������: ";
		students[i].birthYear = iyear();
		cout << "������� ����� ��������: ";
		students[i].birthMonth = imonth();
		cout << "������� ���� ��������: ";
		students[i].birthDay = iday(students[i].birthMonth);
		cout << "\n������� ��� �����������: ";
		students[i].startYear = iyear();
		cout << "\n������� �������� �������: ";
		students[i].faculty = istring();
		cout << "\n������� �������� ��������� (����������): ";
		students[i].inst = istring();
		cout << "\n������� �������� ������: ";
		students[i].group = istring();
		cout << "\n������� ����� �������� ������: ";
		students[i].booknum = istring();
		cout << "\n������� ��� \n(�, �) : ";
		students[i].sex = istring();
		while (students[i].sex != "�" && students[i].sex != "�")
		{
			students[i].sex = istring();
			cin.clear();
			cin.ignore(100, '\n');
			cout << "������������ ����!\n���������� ��� ��� (������� ������ 1 �����):";
		}
		out << students[i].surname << " " << students[i].name << " " << students[i].midname << " " << students[i].birthDay << "." << students[i].birthMonth << "." << students[i].birthYear
			<< " " << students[i].startYear << " " << students[i].faculty << " " << students[i].inst << " " << students[i].group << " " << students[i].booknum << " " << students[i].sex << " ";
		cout << "\n������� ���������� ������ ( �� 9 ): ";
		sesscount = iint();
		if (sesscount > 9)
		{
			sesscount = 9;
		}
		for (int k = 0; k < sesscount; k++)
		{
			cout << "\n������ ���-�� ��������� �� " << k + 1 << " ������: ";
			cin >> NumMarks;
			if (NumMarks > 10)
			{
				NumMarks = 10;
			}
			out << "[";
			for (int k1 = 0; k1 < NumMarks; k1++)
			{
				cout << "\n������� �������� �������� " << k1 + 1 << " : ";
				students[i].sess[k].subj[k1] = istring();
				cout << "\n������� ������ �� ������� " << students[i].sess[k].subj[k1] << " : ";
				students[i].sess[k].mark[k1] = imark();
				if (students[i].sess[k].mark[k1] <= 3)
				{
					students[i].c = TRUE;
				}
				out << students[i].sess[k].subj[k1] << "-" << students[i].sess[k].mark[k1];
				out << " ";
			}
			out << "] ";
		}
		out << students[i].c << "\n";
		out.close();
	}
	delete[] students;
	cout << "������. ������� ENTER, ����� ��������� � ������� ����";
	getchar();
	getchar();
	int main();
}

void show_student()
{
	system("cls");
	size_t space1, space2, space3, space4, space5, space6, space13, space7, space8, space9, space10, dot1, dot2, space11, space12;
	size_t comma1;
	int semicolonCount, commaCount, n = 3, i = 0, c, i1;
	string group, line, line1, name, surname;
	ifstream ifs;
	bool action = false;
	ifs.open("studentInfo.bin", ios::in | ios::binary);
	string man = "�", woman = "�";
	Student* student = new Student[n];
	cout << "|----------------------------------------------|" << endl;
	cout << "|      ����� ���������� � �������� �� �����    |" << endl;
	cout << "|______________________________________________|" << endl;
	cout << "������� ������� ��������: " << endl;
	surname = istring();
	cout << "������� ��� ��������: " << endl;
	name = istring();
	string subs = "";
	subs += surname;
	subs += " ";
	subs += name;
	if (ifs.is_open())
	{
		while (getline(ifs, line))
		{
			if (line.find(subs) != std::string::npos)
			{
				action = true;
				space1 = 0;
				dot1 = 0;
				semicolonCount = 0;
				semicolonCount = count(line.begin(), line.end(), ']');
				space1 = line.find(" ", 0);
				space2 = line.find(" ", space1 + 1);
				space3 = line.find(" ", space2 + 1);
				dot1 = line.find(".", space3 + 1);
				dot2 = line.find(".", dot1 + 1);
				space4 = line.find(" ", dot2 + 1);
				space5 = line.find(" ", space4 + 1);
				space6 = line.find(" ", space5 + 1);
				space7 = line.find(" ", space6 + 1);
				space8 = line.find(" ", space7 + 1);
				space9 = line.find(" ", space8 + 1);
				space10 = line.find(" ", space9 + 1);
				student[i].surname = line.substr(0, space1);
				student[i].name = line.substr(space1 + 1, space2 - space1 - 1);
				student[i].midname = line.substr(space2 + 1, space3 - space2 - 1);
				student[i].birthDay = stoi(line.substr(space3 + 1, dot1 - space3 - 1));
				student[i].birthMonth = stoi(line.substr(dot1 + 1, dot2 - dot1 - 1));
				student[i].birthYear = stoi(line.substr(dot2 + 1, space4 - dot2 - 1));
				student[i].startYear = stoi(line.substr(space4 + 1, space5 - space4 - 1));
				student[i].faculty = line.substr(space5 + 1, space6 - space5 - 1);
				student[i].inst = line.substr(space6 + 1, space7 - space6 - 1);
				student[i].group = line.substr(space7 + 1, space8 - space7 - 1);
				student[i].booknum = line.substr(space8 + 1, space9 - space8 - 1);
				student[i].sex = line.substr(space9 + 1, space10 - space9 - 1);
				space11 = space10;
				space12 = line.find("[", space10);
				space13 = line.find("]", space10);
				line1 = line.substr(space12, space13 - space12 + 1);
				for (int k1 = 0; k1 < semicolonCount; k1++)
				{
					space12 = line.find("[", space11 + 1);
					space13 = line.find("]", space12 + 1);
					commaCount = count(line1.begin(), line1.end(), ' ');
					for (int j = 0; j < commaCount; j++)
					{
						comma1 = line.find("-", space12 + 1);
						space10 = space12;
						space12 = line.find(" ", comma1 + 1);
						student[i].sess[k1].subj[j] = line.substr(space10 + 1, comma1 - space10 - 1);
						student[i].sess[k1].mark[j] = stoi(line.substr(comma1 + 1, space12 - comma1 - 1));
					}
					space11 = line.find(" ", space12 + 1);
				}
				student[i].c = stoi(line.substr(space11 + 1, 1));
				c = 0;
				cout << "\n\n�������:		    " << student[i].surname << " " << student[i].name << " " << student[i].midname << "\n����� �������� ������:	    " << student[i].booknum
					<< "\n���� ��������:		    " << student[i].birthDay << "." << student[i].birthMonth << "." << student[i].birthYear
					<< "\n���:		            " << student[i].sex
					<< "\n��������:		    " << student[i].inst << "\n�����������:		    " << student[i].faculty
					<< "\n��� �����������:	    " << student[i].startYear;
				for (int k2 = 0; student[i].sess[k2].subj[1] != ""; k2++)
				{
					cout << "\n������ �� " << k2 + 1 << " ������: ";
					for (int k1 = 0; student[i].sess[k2].subj[k1] != ""; k1++)
					{
						cout << student[i].sess[k2].subj[k1] << " - " << student[i].sess[k2].mark[k1] << " ";
					}
				}
			}
			break;
		}
		if (!action)
		{
			cout << "������ �������� ���. ������� �����, ����� ��������� �������";
			getchar();
			getchar();
			show_student();
		}
	}
	delete[] student;
	ifs.close();
	cout << "\n������. ������� ENTER, ����� ��������� � ������� ����";
	getchar();
	getchar();
	int main();
}

void show_group()
{
	system("cls");
	size_t space1, space2, space3, space4, space5, space6, space13, space7, space8, space9, space10, dot1, dot2, space11, space12;
	size_t comma1;
	int semicolonCount, commaCount, n = 33, i = 0, min = 2200, max = 0, i1;
	string group, line, line1, name;
	ifstream ifs;
	ifs.open("studentInfo.bin", ios::in | ios::binary);
	string man = "�", woman = "�";
	Student* student = new Student[n];
	cout << "|----------------------------------------------|" << endl;
	cout << "|      ����� ���������� � ������ �� �����      |" << endl;
	cout << "|______________________________________________|" << endl;
	cout << "������� ������ ��������: " << endl;
	group = istring();
	if (ifs.is_open())
	{
		while (getline(ifs, line))
		{
			if (line.find(group) != std::string::npos)
			{
				space1 = 0;
				dot1 = 0;
				semicolonCount = 0;
				semicolonCount = count(line.begin(), line.end(), ']');
				space1 = line.find(" ", 0);
				space2 = line.find(" ", space1 + 1);
				space3 = line.find(" ", space2 + 1);
				dot1 = line.find(".", space3 + 1);
				dot2 = line.find(".", dot1 + 1);
				space4 = line.find(" ", dot2 + 1);
				space5 = line.find(" ", space4 + 1);
				space6 = line.find(" ", space5 + 1);
				space7 = line.find(" ", space6 + 1);
				space8 = line.find(" ", space7 + 1);
				space9 = line.find(" ", space8 + 1);
				space10 = line.find(" ", space9 + 1);
				student[i].surname = line.substr(0, space1);
				student[i].name = line.substr(space1 + 1, space2 - space1 - 1);
				student[i].midname = line.substr(space2 + 1, space3 - space2 - 1);
				student[i].birthDay = stoi(line.substr(space3 + 1, dot1 - space3 - 1));
				student[i].birthMonth = stoi(line.substr(dot1 + 1, dot2 - dot1 - 1));
				student[i].birthYear = stoi(line.substr(dot2 + 1, space4 - dot2 - 1));
				student[i].startYear = stoi(line.substr(space4 + 1, space5 - space4 - 1));
				student[i].faculty = line.substr(space5 + 1, space6 - space5 - 1);
				student[i].inst = line.substr(space6 + 1, space7 - space6 - 1);
				student[i].group = line.substr(space7 + 1, space8 - space7 - 1);
				student[i].booknum = line.substr(space8 + 1, space9 - space8 - 1);
				student[i].sex = line.substr(space9 + 1, space10 - space9 - 1);
				space11 = space10;
				space12 = line.find("[", space10);
				space13 = line.find("]", space10);
				line1 = line.substr(space12, space13 - space12 + 1);
				for (int k1 = 0; k1 < semicolonCount; k1++)
				{
					space12 = line.find("[", space11 + 1);
					space13 = line.find("]", space12 + 1);
					space10 = space12;
					commaCount = count(line1.begin(), line1.end(), ' ');
					for (int j = 0; j < commaCount; j++)
					{
						comma1 = line.find("-", space12 + 1);
						space12 = line.find(" ", comma1 + 1);
						student[i].sess[k1].subj[j] = line.substr(space10 + 1, comma1 - space10 - 1);
						student[i].sess[k1].mark[j] = stoi(line.substr(comma1 + 1, space12 - comma1 - 1));
					}
					space11 = line.find(" ", space12 + 1);
				}
				student[i].c = stoi(line.substr(space11 + 1, 1));
				i++;
			}
		}
	}
	i1 = i;
	ifs.close();
	while (i1--)
	{
		bool swapped = false;
		for (int k = 0; k < i1; k++)
		{
			if (student[k].booknum > student[k + 1].booknum && student[k].c > student[k + 1].c)
			{
				swap(student[k], student[k + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
	cout << min << "-" << max;
	for (int j = 0; j < i; j++)
	{
		cout << "\n�������:		    " << student[j].surname << " " << student[j].name << " " << student[j].midname << "\n����� �������� ������:	    " << student[j].booknum
			<< "\n���� ��������:		    " << student[j].birthDay << "." << student[j].birthMonth << "." << student[j].birthYear
			<< "\n���:		            " << student[j].sex
			<< "\n��������:		    " << student[j].inst << "\n�����������:		    " << student[j].faculty
			<< "\n��� �����������:	    " << student[j].startYear;
		for (int k2 = 0; student[j].sess[k2].subj[1] != ""; k2++)
		{
			cout << "\n������ �� " << k2 + 1 << " ������: ";
			for (int k1 = 0; student[j].sess[k2].subj[k1] != ""; k1++)
			{
				cout << student[j].sess[k2].subj[k1] << " - " << student[j].sess[k2].mark[k1] << " ";
			}
		}
		cout << "\n_______________________________\n";
	}
	delete[] student;
	cout << "\n������. ������� ENTER, ����� ��������� � ������� ����";
	getchar();
	getchar();
	int main();
}

void exercise()
{
	system("cls");
	size_t space1, space2, space3, space4, space5, space6, space13, space7, space8, space9, space10, dot1, dot2, space11, space12;
	size_t comma1;
	int semicolonCount, commaCount, n = 33, i = 0, min = 2200, max = 0, c, i1;
	string group, line, line1;
	ifstream ifs;
	ifs.open("studentInfo.bin", ios::in | ios::binary);
	string man = "�", woman = "�";
	Student* student = new Student[n];
	cout << "|------------------------------------|" << endl;
	cout << "|         ������� 69                 |" << endl;
	cout << "|____________________________________|" << endl;
	cout << "������� ������ ��������: " << endl;
	group = istring();
	if (ifs.is_open())
	{
		while (getline(ifs, line))
		{ 
			if (line.find(group) != std::string::npos)
			{
				space1 = 0;
				dot1 = 0;
				semicolonCount = 0;
				semicolonCount = count(line.begin(), line.end(), ']');
				space1 = line.find(" ", 0);
				space2 = line.find(" ", space1 + 1);
				space3 = line.find(" ", space2 + 1);
				dot1 = line.find(".", space3 + 1);
				dot2 = line.find(".", dot1 + 1);
				space4 = line.find(" ", dot2 + 1);
				space5 = line.find(" ", space4 + 1);
				space6 = line.find(" ", space5 + 1);
				space7 = line.find(" ", space6 + 1);
				space8 = line.find(" ", space7 + 1);
				space9 = line.find(" ", space8 + 1);
				space10 = line.find(" ", space9 + 1);
				student[i].surname = line.substr(0, space1);
				student[i].name = line.substr(space1 + 1, space2 - space1 - 1);
				student[i].midname = line.substr(space2 + 1, space3 - space2 - 1);
				student[i].birthDay = stoi(line.substr(space3 + 1, dot1 - space3 - 1));
				student[i].birthMonth = stoi(line.substr(dot1 + 1, dot2 - dot1 - 1));
				student[i].birthYear = stoi(line.substr(dot2 + 1, space4 - dot2 - 1));
				student[i].startYear = stoi(line.substr(space4 + 1, space5 - space4 - 1));
				student[i].faculty = line.substr(space5 + 1, space6 - space5 - 1);
				student[i].inst = line.substr(space6 + 1, space7 - space6 - 1);
				student[i].group = line.substr(space7 + 1, space8 - space7 - 1);
				student[i].booknum = line.substr(space8 + 1, space9 - space8 - 1);
				student[i].sex = line.substr(space9 + 1, space10 - space9 - 1);
				space11 = space10;
				space12 = line.find("[", space10);
				space13 = line.find("]", space10);
				line1 = line.substr(space12, space13 - space12 + 1);
				for (int k1 = 0; k1 < semicolonCount; k1++)
				{
					space12 = line.find("[", space11 + 1);
					space13 = line.find("]", space12 + 1);
					commaCount = count(line1.begin(), line1.end(), ' ');
					for (int j = 0; j < commaCount; j++)
					{
						comma1 = line.find("-", space12 + 1);
						space10 = space12;
						space12 = line.find(" ", comma1 + 1);
						student[i].sess[k1].subj[j] = line.substr(space10 + 1, comma1 - space10 - 1);
						student[i].sess[k1].mark[j] = stoi(line.substr(comma1 + 1, space12 - comma1 - 1));
					}
					space11 = line.find(" ", space12 + 1);
				}
				if (student[i].birthYear < min)
				{
					min = student[i].birthYear;
				}
				if (student[i].birthYear > max)
				{
					max = student[i].birthYear;
				}
				if (student[i].group == group)
				{
					i++;
				}
				else continue;
				student[i].c = stoi(line.substr(space11 + 1, 1));
				i1 = i;
				while (i1--)
				{
					bool swapped = false;
					for (int k = 0; k < i1; k++)
					{
						if (student[k].booknum > student[k + 1].booknum && student[k].c > student[k + 1].c)
						{
							swap(student[k], student[k + 1]);
							swapped = true;
						}
					}
					if (swapped == false)
						break;
				}
				c = 0;
				cout << min << "-" << max;
				for (int j = 0; j < i; j++)
				{
					if (j == 0)
					{
						cout << "\n_______________________________\n";
						cout << "�������� � �������� 4 � 5 :\n_______________________________\n";
					}
					cout << "\n�������:		    " << student[j].surname << " " << student[j].name << " " << student[j].midname << "\n����� �������� ������:	    " << student[j].booknum
						<< "\n���� ��������:		    " << student[j].birthDay << "." << student[j].birthMonth << "." << student[j].birthYear
						<< "\n���:		            " << student[j].sex
						<< "\n��������:		    " << student[j].inst << "\n�����������:		    " << student[j].faculty
						<< "\n��� �����������:	    " << student[j].startYear;
					for (int k2 = 0; student[j].sess[k2].subj[1] != ""; k2++)
					{
						cout << "\n������ �� " << k2 + 1 << " ������: ";
						for (int k1 = 0; student[j].sess[k2].subj[k1] != ""; k1++)
						{
							cout << student[j].sess[k2].subj[k1] << " - " << student[j].sess[k2].mark[k1] << " ";
						}
					}
					cout << "\n_______________________________\n";
					if (j != 0 && j != i - 1 && student[j].c != student[j + 1].c)
					{
						cout << "�������� � �������� 3 :\n_______________________________\n";
					}
				}
			}
		}
		delete[] student;
		ifs.close();
		cout << "\n������. ������� ENTER, ����� ��������� � ������� ����";
		getchar();
		getchar();
		int main();
	}
}

void delete_student()
{
	system("cls");
	int n = 0;
	string surname, name, boonum, line;
	ifstream ifs;
	ifs.open("studentInfo.bin", ios::in | ios::binary);
	ofstream out;
	out.open("buff.bin", ios::out | ios::binary | ios::app);
	string man = "�", woman = "�";
	Student s;
	cout << "|------------------------------------|" << endl;
	cout << "|  ���� �������� ������ � ��������   |" << endl;
	cout << "|------------------------------------|" << endl;
	cout << "������� ������� ��������: " << endl;
	surname = istring();
	cout << "������� ��� ��������: " << endl;
	name = istring();
	string subs = "";
	subs += surname;
	subs += " ";
	subs += name;
	while (getline(ifs, line))
	{
		if (line.find(subs) != std::string::npos)
		{
			n++;
		}
		else out << line << "\n";
	}
	out.close();
	ifs.close();
	remove("studentInfo.bin");
	rename("buff.bin", "studentInfo.bin");
	if (n > 0)
	{
		cout << "������� " << surname << " " << name << " �� ��� ������(" << endl;
	}
	else
	{
		cout << "������� " << surname << " " << name << " ��� ������ �� �����)" << endl;
	}
	cout << "\n������. ������� ENTER, ����� ��������� � ������� ����";
	getchar();
	getchar();
	int main();
}

void import_students() { //��������������, ��� � ����������� ����� ���������� ��������� ���� ���������, 
							//�� ������ ����� ������ �������� ����� ����� ������������� ������ � �������� ����
	string filename, line;
	int n = 0;
	cout << " _______________________________________" << endl;
	cout << "|  ���� ������� ������ �� ������� ����� |" << endl;
	cout << "|_______________________________________|" << endl;
	cout << "| ������ ������� ����?                  |" << endl;
	cout << "| (1) ��������                          |" << endl;
	cout << "| (2) ������� ���������                 |" << endl;
	cout << "|_______________________________________|" << endl;
	cout << "�������� ������: ";
	n = iint();
	cout << "\n������� �������� �����: ";
	filename = istring();
	ifstream ifs;
	ofstream ofs;

	switch (n)
	{
	case 1:
		ifs.open(filename.c_str(), ios::in | ios::binary);
		ofs.open("studentInfo.bin", ios::out | ios::binary | ios::app);
		while (getline(ifs, line))
		{
			ofs << line << "\n";
		}
		break;
	case 2:
		ifs.open(filename.c_str(), ios::in);
		ofs.open("studentInfo.bin", ios::out | ios::binary | ios::app);
		while(getline(ifs,line))
		{
			ofs << line << "\n";
		}
		break;
	}
	cout << "\n������ ���� ������� ����������!!!!\n";
	cout << "������. ������� ENTER, ����� ��������� � ������� ����";
	getchar();
	getchar();
	int main();
}

void edit_student()
{
	system("cls");
	size_t space1, space2, space3, space4, space5, space6, space13, space7, space8, space9, space10, dot1, dot2, space11, space12;
	size_t comma1;
	int semicolonCount, commaCount, n, sessnum;
	string line, line1, line2, line3, subj, surname, name, boonum;
	ifstream ifs;
	ifs.open("studentInfo.bin", ios::in | ios::binary);
	ofstream out;
	out.open("buff.bin", ios::out | ios::binary);
	string man = "�", woman = "�";
	Student s;
	cout << "|------------------------------------|" << endl;
	cout << "|  ���� ��������� ������ � ��������� |" << endl;
	cout << "|------------------------------------|" << endl;
	cout << "������� ������� ��������: " << endl;
	surname = istring();
	cout << "������� ��� ��������: " << endl;
	name = istring();
	string subs = "";
	subs += surname;
	subs += " ";
	subs += name;
	while (getline(ifs, line)) 
	{
		if (line.find(subs) != std::string::npos)
		{
			space1 = 0;
			dot1 = 0;
			semicolonCount = 0;
			semicolonCount = count(line.begin(), line.end(), ']');
			space1 = line.find(" ", 0);
			space2 = line.find(" ", space1 + 1);
			space3 = line.find(" ", space2 + 1);
			dot1 = line.find(".", space3 + 1);
			dot2 = line.find(".", dot1 + 1);
			space4 = line.find(" ", dot2 + 1);
			space5 = line.find(" ", space4 + 1);
			space6 = line.find(" ", space5 + 1);
			space7 = line.find(" ", space6 + 1);
			space8 = line.find(" ", space7 + 1);
			space9 = line.find(" ", space8 + 1);
			space10 = line.find(" ", space9 + 1);
			s.surname = line.substr(0, space1);
			s.name = line.substr(space1 + 1, space2 - space1 - 1);
			s.midname = line.substr(space2 + 1, space3 - space2 -1);
			s.birthDay = stoi(line.substr(space3 + 1, dot1 - space3 - 1));
			s.birthMonth = stoi(line.substr(dot1 + 1, dot2 - dot1 - 1));
			s.birthYear = stoi(line.substr(dot2 + 1, space4 - dot2 - 1));
			s.startYear = stoi(line.substr(space4 + 1, space5 - space4 - 1));
			s.faculty = line.substr(space5 + 1, space6 - space5 - 1);
			s.inst = line.substr(space6 + 1, space7 - space6 - 1);
			s.group = line.substr(space7 + 1, space8 - space7 - 1);
			s.booknum = line.substr(space8 + 1, space9 - space8 - 1);
			s.sex = line.substr(space9 + 1, space10 - space9 - 1);
			space11 = space10;
			space12 = line.find("[", space10);
			space13 = line.find("]", space10);
			line1 = line.substr(space12, space13 - space12 + 1 );
			for (int k1 = 0; k1 < semicolonCount; k1++)
			{
				space12 = line.find("[", space11 + 1);
				space13 = line.find("]", space12 + 1);
				commaCount = count(line1.begin(), line1.end(), ' ');
				for (int j = 0; j < commaCount; j++)
				{
					comma1 = line.find("-", space12 + 1);
					space10 = space12;
					space12 = line.find(" ", comma1 + 1);
					s.sess[k1].subj[j] = line.substr(space10 + 1, comma1 - space10 - 1);
					s.sess[k1].mark[j] = stoi(line.substr(comma1 + 1, space12 - comma1 - 1));
				}
				space11 = line.find(" ", space12 + 1);
			}
			s.c = stoi(line.substr(space11 + 1, space11 + 2));
			cout << "��� �� ������ �������� ?";
			cout << "\n______________________________________";
			cout << "\n|(1) �������� �������			|";
			cout << "\n|(2) �������� ���			|";
			cout << "\n|(3) �������� ��������			|";
			cout << "\n|(4) �������� ���� ��������		|";
			cout << "\n|(5) �������� ��� �����������		|";
			cout << "\n|(6) �������� �������			|";
			cout << "\n|(7) �������� ��������			|";
			cout << "\n|(8) �������� ������			|";
			cout << "\n|(9) �������� ����� ���.������		|";
			cout << "\n|(10) �������� ���			|";
			cout << "\n|(11) �������� ������ � ������		|";
			cout << "\n|_______________________________________|";
			cout << "\n������� ����� ��������:  ";
			cin >> n;
			switch (n)
			{
				case 1:
					cout << "\n������� ����� �������: ";
					s.surname = istring();
					break;
				case 2:
					cout << "\n������� ����� ���: ";
					s.name = istring();
					break;
				case 3:
					cout << "\n������� ����� ��������: ";
					s.midname = istring();
					break;
				case 4:
					cout << "\n������� ����� ���� ��������: ";
					cout << "\n������� ����� ��� ��������: ";
					s.birthYear = iyear();
					cout << "\n������� ����� ����� ��������: ";
					s.birthMonth = imonth();
					cout << "\n������� ����� ���� ��������: ";
					s.birthDay = iday(s.birthMonth);
					break;
				case 5:
					cout << "\n������� ����� ��� �����������: ";
					s.startYear = iyear();
					break;
				case 6:
					cout << "\n������� ����� �������: ";
					s.faculty = istring();
					break;
				case 7:
					cout << "\n������� ����� ��������: ";
					s.inst = istring();
					break;
				case 8:
					cout << "\n������� ����� ������: ";
					s.group = istring();
					break;
				case 9:
					cout << "\n������� ����� ����� �������� ������: ";
					s.booknum = istring();
					break;
				case 10:
					cout << "\n������� ����� ���: ";
					while (1)
					{
						s.sex = istring();
						if (s.sex.find(man) && s.sex.find(woman))
						{
							cin.clear();
							cin.ignore(100, '\n');
							cout << "������������ ����!\n���������� ��� ��� (������� ������ 1 �����):";
							continue;
						}
					}
					break;
				case 11:
					cout << "\n������� ����� ������: ";
					sessnum = iint();
					cout << "\n������� �������� ��������";
					subj = istring();
					for (int i = 0; i < 10; i++)
					{
						if (s.sess[sessnum].subj[i] == subj)
						{
							cout << "\n�������" << s.sess[sessnum].subj[i] << "������!\n";
							cout << "������"<< s.sess[sessnum].mark[i];
							cout << "\n������� ����� ������: ";
							s.sess[sessnum].mark[i] = imark();
						}
					}
					break;
				default:
					edit_student();
			}
		}
		else out << line << "\n";
		out << s.surname << " " << s.name << " " << s.midname << " " << s.birthDay << "." << s.birthMonth << "." << s.birthYear
			<< " " << s.startYear << " " << s.faculty << " " << s.inst << " " << s.group << " " << s.booknum << " " << s.sex << " ";
		for (int k = 0; k < semicolonCount; k++)
		{

			out << "[";
			for (int k1 = 0; s.sess[k].subj[k1] != ""; k1++)
			{
				out << s.sess[k].subj[k1] << "-" << s.sess[k].mark[k1];
				out << " ";
			}
			out << "] ";
		}
		out << s.c << "\n";
	}
	out.close();
	ifs.close();
	remove("studentInfo.bin");
	rename("buff.bin", "studentInfo.bin");
	cout << "\n������. ������� ENTER, ����� ��������� � ������� ����";
	getchar();
	getchar();
	int main();
}
