#include<iostream>
#include<map>
#include<fstream>
#include<list>
#include<string>
using std::cin;
using std::cout;
using std::endl;


#define tab "\t"
#define delimiter "\n----------------------------------------------------\n"

std::map<std::string, std::string> The_list_of_violators;
void Menu();
void Call_Menu();
void database();
void add_violation();
void delete_violation();
void find_car_number();
void range_of_number();
void save_file();
void load_file();

#define POLICE

void main()
{
	setlocale(LC_ALL, "");

#ifdef POLICE
	Call_Menu();
#endif	//POLICE
}

void Menu()
{
	cout << "					База Данных ГАИ			" << endl;
	cout << "1) Показать базу данных" << endl;
	cout << "2) Добавить правонарушение" << endl;
	cout << "3) Удалить правонарушение" << endl;
	cout << "4) Найти по номеру автомобиля" << endl;
	cout << "5) поиск по диапазону номеров" << endl;
	cout << "6) Сохранить" << endl;
	cout << "7) Загрузить файл" << endl;
	cout << "8) Выход" << endl;
}

void Call_Menu()
{
	int select;
	do
	{
		Menu();
		cout << "Выберите действие:\t"; cin >> select;
		switch (select)
		{
		case 1:
			database();
			break;
		case 2:
			add_violation();
			break;
		case 3:
			delete_violation();
			break;
		case 4:
			find_car_number();
			break;
		case 5:
			range_of_number();
			break;
		case 6:
			save_file();
			break;
		case 7:
			load_file();
			break;
		case 8:
			cout << "Выход из программы" << endl;
			break;
		}
	} while (select != 7);
	//if (select == 1)
	//{
	//	database(The_list_of_violators);
	//}
	//if (select == 2)
	//{
	//	add_violation(The_list_of_violators);
	//}
	//if (select == 3)
	//{
	//	find_car_number(The_list_of_violators);
	//}
	//if (select == 4)
	//{
	//	return range_of_number();
	//}
	//if (select == 5)
	//{
	//	return save_file();
	//}
	//if (select == 6)
	//{
	//	return load_file();
	//}
	//if (select != 1, 2, 3, 4, 5, 6)
	//{
	//	return exit;
	//}
}

void database()
{
	if (The_list_of_violators.empty())
	{
		cout << "База данных отсутствует" << endl;
	}
	else
		cout << "----------База Данных----------" << endl;
	for (std::map<std::string, std::string>::iterator it = The_list_of_violators.begin(); it != The_list_of_violators.end(); ++it)
	{
		cout << it->first << tab << it->second << endl;
	}
}
void add_violation()
{
	std::string number_car;		cout << "Введите номер машины:\t";	cin >> number_car;
	std::string fine;			cout << "Причины выдачи штрафа:\t";	cin >> fine;

	The_list_of_violators[number_car] = fine;

	std::cout << "База данных пополнена\n";
}
void delete_violation()
{
	std::string number_car;
	cout << "Введите номр машины, который хотите удалить из штрафного списка:\t"; cin >> number_car;
	if (The_list_of_violators.erase(number_car))
		cout << "Номер: " << number_car << " - был удалён" << endl;
	else
		cout << "Такой номер " << number_car << " не был внесён в базу данных";
}
void find_car_number()
{
	std::string number_car;
	cout << "Введите номер для поиска:\t";cin >> number_car;

	std::map<std::string, std::string>::iterator it = The_list_of_violators.find(number_car);
	if (it != The_list_of_violators.end())
	{
		cout << "Найден номер: " << it->first << ", штраф: " << it->second << endl;
	}
	else
	{
		cout << "Такой номер не указан в базе данных" << endl;
	}
}

void range_of_number()
{

}

void save_file()
{
	std::ofstream fout("Police.txt"/*, std::ios_base::app*/);
	for (std::map<std::string, std::string>::iterator it = The_list_of_violators.begin(); it != The_list_of_violators.end(); ++it)
	{
		cout << it->first << tab << it->second << endl;
		fout << it->first << tab << it->second << endl;
	}
	fout.close();
	system("start notepad Police.txt");
}

void load_file()
{
	std::ifstream fin("Police.txt");
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			std::string buffer;
			std::getline(fin, buffer);
			cout << buffer << endl;
		}
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}
	fin.close();
}