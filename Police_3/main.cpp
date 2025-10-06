#include<iostream>
#include<map>
#include<fstream>
#include<list>
#include<string>
using std::cin;
using std::cout;
using std::endl;

#define HUMAN_TAKE_PARAMETERS const std::string& name, const std::string& second_name, int age, const std::string& criminal_record, const std::string& Date_of_birth,const std::string& Date_when_the_fine_was_fixed
int  how_more_people;


#define tab "\t"
#define delimiter "\n----------------------------------------------------\n"



class Human;
std::map<std::string, std::string> The_list_of_violators;	//Вынес в заголовочную часть кода, чтобы функции могли прям так считывать
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
void Entering_the_full_information_of_the_accused();
void Request_for_full_information_output();
void clear_Human();

Human** group = nullptr;
int group_size = 0;

class Human
{
	std::string name;
	std::string second_name;
	int age;
	std::string Date_of_birth;
	std::string Date_when_the_fine_was_fixed;
	std::string criminal_record;
public:
	~Human() {};
	void input_info()
	{
		cout << "Введите имя:\t";cin >> name;
		cout << "Введите Фамилию:\t";cin >> second_name;
		cout << "Введите Возраст:\t";cin >> age;
		cout << "Напишите о наличи судимости(причины или их отсутствие):\t";cin >> criminal_record;
		cout << "Дата рождения:\t";cin >> Date_of_birth;
		cout << "Дата фиксации штрафа:\t";cin >> Date_when_the_fine_was_fixed;
	}
	void info()
	{
		cout << "Имя - " << name << "Фамилия - " << second_name << "Возраст - " << age
			<< "Судимости(если 'да' - сколько и за что)" << criminal_record << "Дата рождения - "
			<< Date_of_birth << "Дата фиксации штрафа - " << Date_when_the_fine_was_fixed;
	}
};


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
	cout << "4) Ввод полных данных" << endl;
	cout << "5) Запрос на вывод полной информации" << endl;
	cout << "6) Удалить штраф" << endl;
	cout << "7) Найти по номеру автомобиля" << endl;
	cout << "8) поиск по диапазону номеров" << endl;
	cout << "9) Сохранить" << endl;
	cout << "10) Загрузить файл" << endl;
	cout << "11) Полная очистка файла" << endl;
	cout << "12) Выход" << endl;
	cout << "13) Тыкай сюда, если делали ввод полных" << endl;
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
			database();			//Оператор свитч для перебора действий, вначале сделал через цикл, потом понял, что это был неправильный подход, через возврат функций в мэйн я обнулял свой результат, и получалось ,что база данных всегда пуста
			break;
		case 2:
			add_violation();
			break;
		case 3:
			add_several_violation();
			break;
		case 4:
			Entering_the_full_information_of_the_accused();
			break;
		case 5:
			Request_for_full_information_output();
			break;
		case 6:
			delete_violation();
			break;
		case 7:
			find_car_number();
			break;
		case 8:
			range_of_number();
			break;
		case 9:
			save_file();
			break;
		case 10:
			load_file();
			break;
		case 11:
			clear_file();
			break;
		case 12:
			clear_Human();
			break;
		case 13:
			cout << "Выход из программы" << endl;
			break;
		}
	} while (select != 13);
}

void database()
{
	//Вывод базы данных на консоль, функция empty() - проверяет пустоту строки
	if (The_list_of_violators.empty())
	{
		cout << "База данных отсутствует" << endl;
	}
	else
	{
		cout << "----------База Данных----------" << endl;
		for (std::map<std::string, std::string>::iterator it = The_list_of_violators.begin(); it != The_list_of_violators.end(); ++it)
		{
			cout << it->first << tab << it->second << endl;	//цикл прохода по внесённым данным
		}
	}
}
void add_violation()
{
	//Ввод данных от руки
	std::string number_car;		cout << "Введите номер машины:\t";	cin >> number_car;
	std::string fine;			cout << "Причины выдачи штрафа:\t";	cin >> fine;

	The_list_of_violators[number_car] = fine;	//Обращение по ключу, в моём случае - по номеру машины

	std::cout << "База данных пополнена\n";
}
void add_several_violation()
{
	//Запрос на выдачу нескольких штрафов, используя цикл и уже имеющуюся функцию ввода ОДНОГО штрафа
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
	//Функция для удаления штрафов по номеру
	std::string number_car;
	cout << "Введите номр машины, который хотите удалить из штрафного списка:\t"; cin >> number_car;
	if (The_list_of_violators.erase(number_car))
		cout << "Номер: " << number_car << " - был удалён" << endl;
	else
		cout << "Такой номер " << number_car << " не был внесён в базу данных";
}
void find_car_number()
{
	//Поиск по номеру машины среди введённых в базу данных номеров
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
	//не реализовано, хз как надо
}

void save_file()
{
	//Сохранение базы данных в txt формат
	std::ofstream fout("Police.txt"/*, std::ios_base::app*/);
	for (std::map<std::string, std::string>::iterator it = The_list_of_violators.begin(); it != The_list_of_violators.end(); ++it)
	{
		fout << it->first << tab << it->second << endl;
	}
	fout.close();
	cout << "Данные сохранены в файл Police.txt" << endl;
	system("start notepad Police.txt");
}

void load_file()
{
	//Загрузка базы данных из уже имеющегося файла
	std::ifstream fin("Police.txt");
	if (fin.is_open())
	{
		The_list_of_violators.clear(); //Очистка предыдущих данных перед новой загрузкой
		while (!fin.eof())
		{
			std::string buffer;
			std::getline(fin, buffer);
			cout << buffer << endl;
		}
		cout << "Загрузка данных прошла успешно" << endl;
	}
	else
	{
		std::cerr << "Ошибка: файл не обнаружен" << endl;
	}
	fin.close();
}
void clear_file()
{
	//Полная очистка базы данных, выгрузка из имеющегося файла, удаление и сохранение пустого файла
	The_list_of_violators.clear();
	save_file();
	cout << "База данных полностью очищена" << endl;
}

void Entering_the_full_information_of_the_accused()
{
	clear_Human();

	cout << "Введите количество людей, которое хотите поместить в группу:\t"; cin >> group_size;
	group = new Human*[group_size];

	for (int i = 0; i < group_size; i++)
	{
		cout << i + 1 << " человек в группе" << endl;
		group[i] = new Human();
		group[i]->input_info();
	}
}

void Request_for_full_information_output()
{
	database();
	cout << "Полная информация об обвиняемых" << endl;
	for (int i = 0; i < group_size; i++)
	{
		group[i]->info();
	}
}

void clear_Human()
{
	for (int i = 0; i < group_size; i++) 
		delete group[i];
	delete[] group;
	group = nullptr;
	group_size = 0;
}