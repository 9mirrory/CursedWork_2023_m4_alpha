#pragma once
#include "idata1.h"

struct session
{
	string subj[9];
	int mark[9];
};

struct StudentData
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

class Student
{
public:
	StudentData* printInfo(StudentData* s)
	{
		setlocale(LC_ALL, "Russian");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		int sesscount, commaCount, n = 33, i = 0;
		while (s[i].name != "")
		{
			sesscount = 0;
			for (int j = 0; s[i].sess[j].subj[0] != ""; j++)
			{
				if (s[i].sess[j].subj[0] != "")
				{
					sesscount++;
				}
			}
			cout << "\n____________________________________________________________";
			cout << "\n|ÔÈÎ ÑÒÓÄÅÍÒÀ:		    |" << s[i].surname << " " << s[i].name << " " << s[i].midname;
			cout << "\n|___________________________|______________________________|";
			cout << "\n|ÍÎÌÅÐ ÇÀ×ÅÒÍÎÉ ÊÍÈÆÊÈ:	    |" << s[i].booknum;
			cout << "\n|___________________________|______________________________|";
			cout << "\n|ÄÀÒÀ ÐÎÆÄÅÍÈß:		    |" << s[i].birthDay << "." << s[i].birthMonth << "." << s[i].birthYear;
			cout << "\n|___________________________|______________________________|";
			cout << "\n|ÏÎË:		            |" << s[i].sex;
			cout << "\n|___________________________|______________________________|";
			cout << "\n|ÈÍÑÒÈÒÓÒ:		    |" << s[i].inst;
			cout << "\n|___________________________|______________________________|";
			cout << "\n|ÍÀÏÐÀÂËÅÍÈÅ:		    |" << s[i].faculty;
			cout << "\n|___________________________|______________________________|";
			cout << "\n|ÃÎÄ ÏÎÑÒÓÏËÅÍÈß:	    |" << s[i].startYear;
			cout << "\n|___________________________|______________________________|";
			for (int k2 = 0; k2 < sesscount; k2++)
			{
				cout << "\nÎöåíêè çà " << k2 + 1 << " ñåññèþ: ";
				for (int k1 = 0; s[i].sess[k2].subj[k1] != ""; k1++)
				{
					cout << s[i].sess[k2].subj[k1] << " - " << s[i].sess[k2].mark[k1] << " ";
				}
			}
			cout << "\n|_________________________________________________________|";
			i++;
		}
		return 0;
	}

	StudentData* getInfo(string subs)
	{
		setlocale(LC_ALL, "Russian");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		size_t space1, space2, space3, space4, space5, space6, space13, space7, space8, space9, space10, dot1, dot2, space11, space12;
		size_t comma1;
		int semicolonCount, commaCount, n = 33, i = 0, c, i1;
		string line, line1, name, surname;
		ifstream ifs;
		ifs.open("studentInfo.bin", ios::in | ios::binary);
		StudentData* student = new StudentData[n];
		if (ifs.is_open())
		{
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
						commaCount = count(line1.begin(), line1.end(), '-');
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
				}
			}
		}
		return student;
	}

	void addStudent()
	{
		setlocale(LC_ALL, "Russian");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		int j = 0, NumMarks, sesscount, n;
		string man = "Ì", woman = "Æ";
		system("cls");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		cout << "===================================" << endl;
		cout << "|  ÌÅÍÞ ÂÂÎÄÀ ÄÀÍÍÛÕ ÎÁ Ó×ÅÍÈÊÀÕ  |" << endl;
		cout << "===================================" << endl;
		cout << "Ââåäèòå êîë-âî ñòóäåíòîâ: ";
		cin >> n;
		cin.get();
		StudentData* students = new StudentData[n];
		for (int i = 0; i < n; i++)
		{
			students[i].c = FALSE;
			ofstream out;
			out.open("studentInfo.bin", ios_base::app | ios_base::binary);
			cout << "Ââåäèòå äàííûå ó÷åíèêà " << i + 1 << "." << endl;
			cout << "Ââåäèòå ôàìèëèþ: ";
			students[i].surname = istring();
			cout << "\nÂâåäèòå èìÿ: ";
			students[i].name = istring();
			cout << "\nÂâåäèòå îò÷åñòâî: ";
			students[i].midname = istring();
			cout << "\nÂâåäèòå ãîä ðîæäåíèÿ: ";
			students[i].birthYear = iyear();
			cout << "Ââåäèòå ìåñÿö ðîæäåíèÿ: ";
			students[i].birthMonth = imonth();
			cout << "Ââåäèòå äåíü ðîæäåíèÿ: ";
			students[i].birthDay = iday(students[i].birthMonth);
			cout << "\nÂâåäèòå ãîä ïîñòóïëåíèÿ: ";
			students[i].startYear = iyear();
			cout << "\nÂâåäèòå íàçâàíèå êàôåäðû: ";
			students[i].faculty = istring();
			cout << "\nÂâåäèòå íàçâàíèå èíñòèòóòà (ñîêðàùåííî): ";
			students[i].inst = istring();
			cout << "\nÂâåäèòå íàçâàíèå ãðóïïû: ";
			students[i].group = istring();
			cout << "\nÂâåäèòå íîìåð çà÷åòíîé êíèæêè: ";
			students[i].booknum = istring();
			cout << "\nÂâåäèòå ïîë \n(Ì, Æ) : ";
			students[i].sex = istring();
			while (students[i].sex != "Ì" && students[i].sex != "Æ")
			{
				students[i].sex = istring();
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Íåêîððåêòíûé ââîä!\nÏîïðîáóéòå åù¸ ðàç (ââåäèòå òîëüêî 1 áóêâó):";
			}
			out << students[i].surname << " " << students[i].name << " " << students[i].midname << " " << students[i].birthDay << "." << students[i].birthMonth << "." << students[i].birthYear
				<< " " << students[i].startYear << " " << students[i].faculty << " " << students[i].inst << " " << students[i].group << " " << students[i].booknum << " " << students[i].sex << " ";
			cout << "\nÂâåäèòå êîëè÷åñòâî ñåññèé ( äî 9 ): ";
			sesscount = iint();
			if (sesscount > 9)
			{
				sesscount = 9;
			}
			for (int k = 0; k < sesscount; k++)
			{
				cout << "\nÂâåñòè êîë-âî ïðåäìåòîâ çà " << k + 1 << " ñåññèþ: ";
				cin >> NumMarks;
				if (NumMarks > 10)
				{
					NumMarks = 10;
				}
				out << "[";
				for (int k1 = 0; k1 < NumMarks; k1++)
				{
					cout << "\nÂâåäèòå íàçâàíèå ïðåäìåòà " << k1 + 1 << " : ";
					students[i].sess[k].subj[k1] = istring();
					cout << "\nÂâåäèòå îöåíêó çà ïðåäìåò " << students[i].sess[k].subj[k1] << " : ";
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
		cout << "Ãîòîâî. Íàæìèòå ENTER, ÷òîáû âåðíóòüñÿ â ãëàâíîå ìåíþ";
		getchar();
		getchar();
		int main();
	}

	void edit_student()
	{
		setlocale(LC_ALL, "Russian");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		system("cls");
		int i = 0, n = 0, sessnum;
		string string, subs = "", line, subj, surname, name, man = "Ì", woman = "Æ";
		ifstream ifs;
		ifs.open("studentInfo.bin", ios::in | ios::binary);
		ofstream out;
		out.open("buff.bin", ios::out | ios::binary);
		cout << "|------------------------------------|" << endl;
		cout << "|  ÌÅÍÞ ÈÇÌÅÍÅÍÈß ÄÀÍÍÛÕ Î ÑÒÓÄÅÍÒÀÕ |" << endl;
		cout << "|------------------------------------|" << endl;
		cout << "Ââåäèòå Ôàìèëèþ ñòóäåíòà: " << endl;
		surname = istring();
		cout << "Ââåäèòå Èìÿ ñòóäåíòà: " << endl;
		name = istring();
		subs += surname;
		subs += " ";
		subs += name;
		StudentData* student = getInfo(subs);
		if (student[0].name != "" && student[0].name == name && student[0].surname == surname)
		{
			printInfo(student);
			while (getline(ifs, line))
			{
				if (line.find(subs) != string::npos)
				{
					cout << "×ÒÎ ÂÛ ÕÎÒÈÒÅ ÈÇÌÅÍÈÒÜ ?";
					cout << "\n______________________________________";
					cout << "\n|(1) ÈÇÌÅÍÈÒÜ ÔÀÌÈËÈÞ			|";
					cout << "\n|(2) ÈÇÌÅÍÈÒÜ ÈÌß			|";
					cout << "\n|(3) ÈÇÌÅÍÈÒÜ ÎÒ×ÅÑÒÂÎ			|";
					cout << "\n|(4) ÈÇÌÅÍÈÒÜ ÄÀÒÓ ÐÎÆÄÅÍÈß		|";
					cout << "\n|(5) ÈÇÌÅÍÈÒÜ ÃÎÄ ÏÎÑÒÓÏËÅÍÈß		|";
					cout << "\n|(6) ÈÇÌÅÍÈÒÜ ÊÀÔÅÄÐÓ			|";
					cout << "\n|(7) ÈÇÌÅÍÈÒÜ ÈÍÑÒÈÒÓÒ			|";
					cout << "\n|(8) ÈÇÌÅÍÈÒÜ ÃÐÓÏÏÓ			|";
					cout << "\n|(9) ÈÇÌÅÍÈÒÜ ÍÎÌÅÐ ÇÀ×.ÊÍÈÆÊÈ		|";
					cout << "\n|(10) ÈÇÌÅÍÈÒÜ ÏÎË			|";
					cout << "\n|(11) ÈÇÌÅÍÈÒÜ ÎÖÅÍÊÓ Â ÑÅÑÑÈÈ		|";
					cout << "\n|_______________________________________|";
					cout << "\nÂÂÅÄÈÒÅ ÍÎÌÅÐ ÄÅÉÑÒÂÈß:  ";
					cin >> n;
					switch (n)
					{
					case 1:
						cout << "\nÂÂÅÄÈÒÅ ÍÎÂÓÞ ÔÀÌÈËÈÞ: ";
						student[0].surname = istring();
						break;
					case 2:
						cout << "\nÂÂÅÄÈÒÅ ÍÎÂÎÅ ÈÌß: ";
						student[0].name = istring();
						break;
					case 3:
						cout << "\nÂÂÅÄÈÒÅ ÍÎÂÎÅ ÎÒ×ÅÑÒÂÎ: ";
						student[0].midname = istring();
						break;
					case 4:
						cout << "\nÂÂÅÄÈÒÅ ÍÎÂÓÞ ÄÀÒÓ ÐÎÆÄÅÍÈß: ";
						cout << "\nÂÂÅÄÈÒÅ ÍÎÂÛÉ ÃÎÄ ÐÎÆÄÅÍÈß: ";
						student[0].birthYear = iyear();
						cout << "\nÂÂÅÄÈÒÅ ÍÎÂÛÉ ÌÅÑßÖ ÐÎÆÄÅÍÈß: ";
						student[0].birthMonth = imonth();
						cout << "\nÂÂÅÄÈÒÅ ÍÎÂÛÉ ÄÅÍÜ ÐÎÆÄÅÍÈß: ";
						student[0].birthDay = iday(student[0].birthMonth);
						break;
					case 5:
						cout << "\nÂÂÅÄÈÒÅ ÍÎÂÛÉ ÃÎÄ ÏÎÑÒÓÏËÅÍÈß: ";
						student[0].startYear = iyear();
						break;
					case 6:
						cout << "\nÂÂÅÄÈÒÅ ÍÎÂÓÞ ÊÀÔÅÄÐÓ: ";
						student[0].faculty = istring();
						break;
					case 7:
						cout << "\nÂÂÅÄÈÒÅ ÍÎÂÛÉ ÈÍÑÒÈÒÓÒ: ";
						student[0].inst = istring();
						break;
					case 8:
						cout << "\nÂÂÅÄÈÒÅ ÍÎÂÓÞ ÃÐÓÏÏÓ: ";
						student[0].group = istring();
						break;
					case 9:
						cout << "\nÂÂÅÄÈÒÅ ÍÎÂÓÞ ÍÎÌÅÐ ÇÀ×ÅÒÍÎÉ ÊÍÈÆÊÈ: ";
						student[0].booknum = istring();
						break;
					case 10:
						cout << "\nÂÂÅÄÈÒÅ ÍÎÂÛÉ ÏÎË: ";
						while (1)
						{
							student[0].sex = istring();
							if (student[0].sex.find(man) && student[0].sex.find(woman))
							{
								cin.clear();
								cin.ignore(100, '\n');
								cout << "Íåêîððåêòíûé ââîä!\nÏîïðîáóéòå åù¸ ðàç (ââåäèòå òîëüêî 1 áóêâó):";
								continue;
							}
						}
					case 11:
						cout << "\nÂÂÅÄÈÒÅ ÍÎÌÅÐ ÑÅÑÑÈÈ: ";
						sessnum = iint();
						cout << "\nÂÂÅÄÈÒÅ ÍÀÇÂÀÍÈÅ ÏÐÅÄÌÅÒÀ";
						subj = istring();
						for (int i = 0; i < 10; i++)
						{
							if (student[0].sess[sessnum].subj[i] == subj)
							{
								cout << "\nÏÐÅÄÌÅÒ" << student[0].sess[sessnum].subj[i] << "ÍÀÉÄÅÍ!\n";
								cout << "ÎÖÅÍÊÀ" << student[0].sess[sessnum].mark[i];
								cout << "\nÂÂÅÄÈÒÅ ÍÎÂÓÞ ÎÖÅÍÊÓ: ";
								student[0].sess[sessnum].mark[i] = imark();
							}
						}
						break;
					default:
						edit_student();
					}
					out << student[0].surname << " " << student[0].name << " " << student[0].midname << " " << student[0].birthDay << "." << student[0].birthMonth << "." << student[0].birthYear
						<< " " << student[0].startYear << " " << student[0].faculty << " " << student[0].inst << " " << student[0].group << " " << student[0].booknum << " " << student[0].sex << " ";
					int sesscount = 0;
					for (int j = 0; student[0].sess[j].subj[0] != ""; j++)
					{
						if (student[0].sess[j].subj[0] != "")
						{
							sesscount++;
						}
					}
					for (int k = 0; k < sesscount; k++)
					{
						out << "[";
						for (int k1 = 0; student[0].sess[k].subj[k1] != ""; k1++)
						{
							out << student[0].sess[k].subj[k1] << "-" << student[0].sess[k].mark[k1];
							out << " ";
						}
						out << "] ";
					}
					out << student[0].c << "\n";
				}
				else
				{
					out << line << "\n";
				}

			}
			out.close();
			ifs.close();
			delete[] student;
			if (remove("studentInfo.bin") != 0)
				cout << "Remove operation failed" << endl;
			else
				cout << "studentInfo.bin" << " has been removed." << endl;
			if (rename("buff.bin", "studentInfo.bin") != 0)
				cout << "Rename operation failed" << endl;
			else
				cout << "buff.bin has been renamed studentInfo.bin ." << endl;
			cout << "\nÃîòîâî. Íàæìèòå ENTER, ÷òîáû âåðíóòüñÿ â ãëàâíîå ìåíþ";
			getchar();
			getchar();
			int main();
		}
		else
		{
			cout << "Òàêîãî ãðóïïû íåò. íàæìèòå åíòåð, ÷òîáû ïîâòîðèòü ïîïûòêó";
			getchar();
			getchar();
			edit_student();
		}
	}

	void delete_student()
	{
		setlocale(LC_ALL, "Russian");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		system("cls");
		int n = 0;
		string surname, name, boonum, line;
		ifstream ifs;
		ifs.open("studentInfo.bin", ios::in | ios::binary);
		ofstream out;
		out.open("buff.bin", ios::out | ios::binary | ios::app);
		string man = "Ì", woman = "Æ";
		cout << "|------------------------------------|" << endl;
		cout << "|  ÌÅÍÞ ÓÄÀËÅÍÈß ÄÀÍÍÛÕ Î ÑÒÓÄÅÍÒÅ   |" << endl;
		cout << "|------------------------------------|" << endl;
		cout << "Ââåäèòå Ôàìèëèþ ñòóäåíòà: " << endl;
		surname = istring();
		cout << "Ââåäèòå Èìÿ ñòóäåíòà: " << endl;
		name = istring();
		string subs = "";
		subs += surname;
		subs += " ";
		subs += name;
		while (getline(ifs, line))
		{
			if (line.find(subs) != string::npos)
			{
				n++;
			}
			else out << line << "\n";
		}
		out.close();
		ifs.close();
		if (remove("studentInfo.bin") != 0)
			cout << "Remove operation failed" << endl;
		else
			cout << "studentInfo.bin" << " has been removed." << endl;
		if (rename("buff.bin", "studentInfo.bin") != 0)
			cout << "Rename operation failed" << endl;
		else
			cout << "studentInfo.bin has been renamed buff.bin ." << endl;
		if (n == 0)
		{
			cout << "Ñòóäåíò " << surname << " " << name << " íå áûë íàéäåí(" << endl;
		}
		else
		{
			cout << "Ñòóäåíò " << surname << " " << name << " áûë óäàëåí èç ôàéëà)" << endl;
		}
		cout << "\nÃîòîâî. Íàæìèòå ENTER, ÷òîáû âåðíóòüñÿ â ãëàâíîå ìåíþ";
		getchar();
		getchar();
		int main();
	}

	void import_students() { //ïðåäïîëàãàåòñÿ, ÷òî â ðåïîçèòîðèè áóäåò íàõîäèòüñÿ ñòîðîííÿÿ áàçà ñòóäåíòîâ, 
		//ìû äîëæíû áóäåì ââåñòè íàçâàíèå ôàéëà ÷òîáû èìïîðòèðîâàòü çàïèñè â îñíîâíîé ôàéë
		setlocale(LC_ALL, "Russian");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		string filename, line;
		int n = 0;
		cout << " _______________________________________" << endl;
		cout << "|  ÌÅÍÞ ÈÌÏÎÐÒÀ ÄÀÍÍÛÕ ÈÇ ÄÐÓÃÎÃÎ ÔÀÉËÀ |" << endl;
		cout << "|_______________________________________|" << endl;
		cout << "| ÊÀÊÎÃÎ ÔÎÐÌÀÒÀ ÔÀÉË?                  |" << endl;
		cout << "| (1) ÁÈÍÀÐÍÛÉ                          |" << endl;
		cout << "| (2) ÎÁÛ×ÍÛÉ ÒÅÊÑÒÎÂÛÉ                 |" << endl;
		cout << "|_______________________________________|" << endl;
		cout << "ÂÛÁÅÐÈÒÅ ÔÎÐÌÀÒ: ";
		n = iint();
		cout << "\nÂÂÅÄÈÒÅ ÍÀÇÂÀÍÈÅ ÔÀÉËÀ: ";
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
			while (getline(ifs, line))
			{
				ofs << line << "\n";
			}
			break;
		}
		cout << "\nÄÀÍÍÛÅ ÁÛËÈ ÓÑÏÅØÍÎ ÏÅÐÅÍÅÑÅÍÛ!!!!\n";
		cout << "Ãîòîâî. Íàæìèòå ENTER, ÷òîáû âåðíóòüñÿ â ãëàâíîå ìåíþ";
		getchar();
		getchar();
		int main();
	}

	void exercise()
	{
		setlocale(LC_ALL, "Russian");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		system("cls");
		int studentcount, i = 0, min = 2200, max = 0, i1 = 0;
		string group;
		cout << "|------------------------------------|" << endl;
		cout << "|         Çàäàíèå 69                 |" << endl;
		cout << "|____________________________________|" << endl;
		cout << "Ââåäèòå ãðóïïó ñòóäåíòà: " << endl;
		group = istring();
		StudentData* student = getInfo(group);
		studentcount = 0;
		for (int i = 0; student[i].name != ""; i++)
		{
			if (student[i].group == group && student[i].name != "")
			{
				studentcount++;
			}
		}
		i1 = studentcount;
		while (i1--)
		{
			bool swapped = false;
			for (int k = 0; k < studentcount - 1; k++)
			{
				if (student[k].booknum > student[k + 1].booknum && student[k].c > student[k + 1].c)
				{
					swap(student[k], student[k + 1]);
					swapped = true;
				}
				if (min > student[k].birthYear)
				{
					min < student[k].birthYear;
				}
				if (max < student[k].birthYear)
				{
					max = student[k].birthYear;
				}
			}
			if (swapped == false)
				break;
		}
		for (int k = 0; k < studentcount; k++)
		{
			if (min > student[k].birthYear)
			{
				min = student[k].birthYear;
			}
			if (max < student[k].birthYear)
			{
				max = student[k].birthYear;
			}
		}
		cout << min << "-" << max;
		printInfo(student);
		delete[] student;
		cout << "\nÃîòîâî. Íàæìèòå ENTER, ÷òîáû âåðíóòüñÿ â ãëàâíîå ìåíþ";
		getchar();
		getchar();
		int main();
	}

	void show_group()
	{
		setlocale(LC_ALL, "Russian");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		system("cls");
		string group;
		cout << "|----------------------------------------------|" << endl;
		cout << "|      Âûâîä èíôîðìàöèè î ãðóïïå íà ýêðàí      |" << endl;
		cout << "|______________________________________________|" << endl;
		cout << "Ââåäèòå ãðóïïó ñòóäåíòà: " << endl;
		group = istring();
		StudentData* student = getInfo(group);
		if (student[0].name != "")
		{
			printInfo(student);
			delete[] student;
			cout << "\nÃîòîâî. Íàæìèòå ENTER, ÷òîáû âåðíóòüñÿ â ãëàâíîå ìåíþ";
			getchar();
			getchar();
			int main();
		}
		else
		{
			cout << "Òàêîãî ãðóïïû íåò. íàæìèòå åíòåð, ÷òîáû ïîâòîðèòü ïîïûòêó";
			getchar();
			getchar();
			show_student();
		}
	}

	void show_student()
	{
		setlocale(LC_ALL, "Russian");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		system("cls");
		string name, surname;
		cout << "|----------------------------------------------|" << endl;
		cout << "|      Âûâîä èíôîðìàöèè î ñòóäåíòå íà ýêðàí    |" << endl;
		cout << "|______________________________________________|" << endl;
		cout << "Ââåäèòå Ôàìèëèþ ñòóäåíòà: " << endl;
		surname = istring();
		cout << "Ââåäèòå Èìÿ ñòóäåíòà: " << endl;
		name = istring();
		string subs = "";
		subs += surname;
		subs += " ";
		subs += name;
		StudentData* student = getInfo(subs);
		if (student[0].name != "")
		{
			printInfo(student);
		}
		else
		{
			cout << "Òàêîãî ñòóäåíòà íåò. íàæìèòå åíòåð, ÷òîáû ïîâòîðèòü ïîïûòêó";
			getchar();
			getchar();
			show_student();
		}
		delete[] student;
		cout << "\nÃîòîâî. Íàæìèòå ENTER, ÷òîáû âåðíóòüñÿ â ãëàâíîå ìåíþ";
		getchar();
		getchar();
		int main();
	}
};
