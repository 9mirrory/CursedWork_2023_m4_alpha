#include "student1.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	cout << "Курсовая работа!\n";
	int meniu = -1;
	while (meniu != 4)
	{
		system("cls");
		cout << " МЕНЮ:\n";
		cout << "  1.Ввод данных о студенте:\n";
		cout << "  2.Показать группу\n";
		cout << "  3.Показать информацию о студенте\n";
		cout << "  4.Редактировать информацию о студенте:\n";
		cout << "  5.Удалить информацию о студенте:\n";
		cout << "  6.Импортировать информацию о студентe/ах из другого файла:\n";
		cout << "  7.Выполнить задание курсовой работы (вариант 69):\n";
		cout << "  8.Выход\n\n";
		cin >> meniu;
		switch (meniu) {
		case 1:
			addStudent();
			break;
		case 2:
			show_group();
			break;
		case 3:
			show_student();
			break;
		case 4:
			edit_student();
			break;
		case 5:
			delete_student();
			break;
		case 6:
			import_students();
			break;
		case 7:
			exercise();
			break;
		case 8:
			cout << "Выход из курсовой работы" << "\n";
			break;
		default:
			main();
		}
	}
}