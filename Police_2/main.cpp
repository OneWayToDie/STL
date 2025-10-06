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
void add_several_violation();
void delete_violation();
void find_car_number();
void range_of_number();
void save_file();
void load_file();
void clear_file();

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
	cout << "2) Добавить штраф" << endl;
	cout << "3) Добавить несколько штрафов" << endl;
	cout << "4) Удалить штраф" << endl;
	cout << "5) Найти по номеру автомобиля" << endl;
	cout << "6) поиск по диапазону номеров" << endl;
	cout << "7) Сохранить" << endl;
	cout << "8) Загрузить файл" << endl;
	cout << "9) Полная очистка файла" << endl;
	cout << "10) Выход" << endl;
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
			add_several_violation();
			break;
		case 4:
			delete_violation();
			break;
		case 5:
			find_car_number();
			break;
		case 6:
			range_of_number();
			break;
		case 7:
			save_file();
			break;
		case 8:
			load_file();
			break;
		case 9:
			clear_file();
			break;
		case 10:
			cout << "Выход из программы" << endl;
			break;
		}
	} while (select != 10);
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
void add_several_violation()
{
	int count; cout << "Сколько штрафов хотите выписать?" << endl; 
	cout << "Хочу выписать: ";cin >> count; 
	cout << endl;
	for (int i = 0; i < count; ++i)
	{
		add_violation();
	}
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
void clear_file()
{
	load_file();
	The_list_of_violators.clear();
	save_file();
}