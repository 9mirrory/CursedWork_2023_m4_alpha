#include "idata1.h"

int iint()
{
	int num;
	while (1)
	{
		cin >> num;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "������������ ���� �����!\n���������� ��� ���:";
			continue;
		}
		return num;
	}
}
int iyear() {
	int year;
	while (1) {
		year = iint();
		if (year < 1990 || year > 2023) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "������������ ���� ����! \n������� ����� ��  1990 �� 2023: ";
			continue;
		}
		return year;
	}
}

int imonth() {
	int month;
	while (1)
	{
		month = iint();
		if (month < 1 && month > 12)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "������������ ���� ������!\n������� ����� �� 1 �� 12: ";
			continue;
		}
		return month;
	}
}

int iday(int month)
{
	int day;
	while (1) {
		day = iint();
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day < 1 || day >31)
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "������������ ���� ���!\n ������� ����� �� 1 �� 31: ";
				continue;

			}
		}
		if (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day < 1 || day >30)
			{
				cin.clear();
				cin.ignore();
				cout << "������������ ���� ���!\n������� ����� �� 1 �� 30: ";
				continue;
			}
		}
		return day;
	}
}

unsigned short imark()
{
	short mark;
	while (1)
	{
		mark = iint(); // ���� ������
		if (mark < 1) mark = 1;
		else if (mark > 5) mark = 5;
		return mark;
	}
}

string istring()
{
	string str;
	getline(cin >> ws, str);
	return str;
}