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

///////////////////////////////////////////////////////////////////////////////////////////////
///////////								Initializations							  /////////////
///////////////////////////////////////////////////////////////////////////////////////////////
#define HUMAN_TAKE_PARAMETERS const std::string& name, const std::string& second_name, int age, const std::string& Date_of_birth, const std::string& Date_when_the_fine_was_fixed, const std::string& criminal_record
class Human;
std::map<std::string, std::list<Human>> The_list_of_violators;	//Вынес в заголовочную часть кода, чтобы функции могли прям так считывать
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
///////////////////////////////////////////////////////////////////////////////////////////////
///////////								CLASS "HUMAN"							  /////////////
///////////////////////////////////////////////////////////////////////////////////////////////
class Human
{
	std::string fine;
	std::string name;
	std::string second_name;
	int age{};
	std::string Date_of_birth;
	std::string Date_when_the_fine_was_fixed;
	std::string criminal_record;
public:
	Human() {};
	~Human() {};
	std::string get_fine()const
	{
		return fine;
	}
	std::string get_name()const
	{
		return name;
	}
	std::string get_second_name()const
	{
		return second_name;
	}
	int get_age()const
	{
		return age;
	}
	std::string get_Date_of_birth()const
	{
		return Date_of_birth;
	}
	std::string get_Date_when_the_fine_was_fixed()const
	{
		return Date_when_the_fine_was_fixed;
	}
	std::string get_criminal_record()const
	{
		return criminal_record;
	}
	void input_info()
	{
		cout << "Введите причины получения штрафа:\t"; cin >> fine;
		cout << "Введите имя:\t";cin >> name;
		cout << "Введите Фамилию:\t";cin >> second_name;
		cout << "Введите Возраст:\t";cin >> age;
		cout << "Напишите о наличи судимости(причины или их отсутствие):\t";cin >> criminal_record;
		cout << "Дата рождения:\t";cin >> Date_of_birth;
		cout << "Дата фиксации штрафа:\t";cin >> Date_when_the_fine_was_fixed;
	}
	void info()const
	{
		cout << "Имя - " << name << endl;
		cout << "Фамилия - " << second_name << endl;
		cout << "Возраст - " << age << endl;
		cout << "Судимости(если 'да' - сколько и за что)" << criminal_record << endl;
		cout << "Дата рождения - " << Date_of_birth << endl;
		cout <<	"Дата фиксации штрафа - " << Date_when_the_fine_was_fixed << endl;
	}
};
std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	obj.info();
	return os;
}
///////////////////////////////////////////////////////////////////////////////////////////////
///////////								CLASS "HUMAN"							  /////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////
///////////									Main								  /////////////
///////////////////////////////////////////////////////////////////////////////////////////////
#define POLICE
void main()
{
	/*SetConsoleCP(1251);
	SetConsoleOutputCP(1251);*/
	setlocale(LC_ALL, "");
#ifdef POLICE
	Call_Menu();
#endif	//POLICE
}
///////////////////////////////////////////////////////////////////////////////////////////////
///////////									Menu								  /////////////
///////////////////////////////////////////////////////////////////////////////////////////////
void Menu()
{
	cout << "					База Данных ГАИ" << endl;
	cout << "1) Показать базу данных" << endl;
	cout << "2) Добавить штраф" << endl;
	cout << "3) Добавить несколько штрафов" << endl;
	cout << "4) Удалить штраф" << endl;
	cout << "5) Найти по номеру автомобиля" << endl;
	cout << "6) поиск по диапазону номеров (не работает - не тыкать)" << endl;
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
			database();			//Оператор свитч для перебора действий, вначале сделал через цикл, потом понял, что это был неправильный подход, через возврат функций в мэйн я обнулял свой результат, и получалось ,что база данных всегда пуста
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
///////////////////////////////////////////////////////////////////////////////////////////////
///////////									Menu								  /////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////
///////////					Database, add/erase-constructors					  /////////////
///////////////////////////////////////////////////////////////////////////////////////////////
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
		for (std::map<std::string, std::list<Human>>::iterator it = The_list_of_violators.begin(); it != The_list_of_violators.end(); ++it)
		{
			cout << it->first << endl;
			for (std::list<Human>::iterator violation = it->second.begin(); violation != it->second.end(); ++violation)
			{
				cout << "\t" << *violation << endl;
			}
			cout << delimiter << endl;
		}
	}
}
void add_violation()
{
	std::string number_car;	cout << "Введите номер машины:\t";	cin >> number_car;
	Human violator;
	violator.input_info();
	The_list_of_violators[number_car].push_back(violator);
	cout << "База данных пополнена\n";
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
	//Функция для удаления штрафов по номеру
	std::string number_car;
	cout << "Введите номер машины, который хотите удалить из штрафного списка:\t"; cin >> number_car;
	if (The_list_of_violators.erase(number_car))
		cout << "Номер: " << number_car << " - был удалён" << endl;
	else
		cout << "Такой номер " << number_car << " не был внесён в базу данных";
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////							Search operations							  /////////////
///////////////////////////////////////////////////////////////////////////////////////////////
void find_car_number()
{
	//Поиск по номеру машины среди введённых в базу данных номеров
	std::string number_car;
	cout << "Введите номер для поиска:\t";cin >> number_car;

	std::map<std::string, std::list<Human>>::iterator it = The_list_of_violators.find(number_car);
	if (it != The_list_of_violators.end())
	{
		cout << "Найден номер: " << it->first << endl;
		for (std::list<Human>::iterator human = it->second.begin(); human != it->second.end(); ++human)
		{
			human->info();
			cout << delimiter;
		}
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
///////////////////////////////////////////////////////////////////////////////////////////////
///////////						Save/Load/Clear operations						  /////////////
///////////////////////////////////////////////////////////////////////////////////////////////
void save_file()
{
	//Сохранение базы данных в txt формат
	std::ofstream fout("Police.txt"/*, std::ios_base::app*/);
	for (std::map<std::string, std::list<Human>>::iterator it = The_list_of_violators.begin(); it != The_list_of_violators.end(); ++it)
	{
		fout << "Номер автомобиля: " << it->first << endl;
		for (std::list<Human>::iterator human = it->second.begin(); human != it->second.end(); ++human)
		{
			fout << "Причина: " << human->get_fine() << tab;
			fout << "Имя: " << human->get_name() << tab;
			fout << "Фамилия: " << human->get_second_name() << tab;
			fout << "Возраст: " << human->get_age() << tab;
			fout << "Судимости: " << human->get_criminal_record() << tab;
			fout << "Дата рождения: " << human->get_Date_of_birth() << tab;
			fout << "Дата штрафа: " << human->get_Date_when_the_fine_was_fixed() << endl;
		}
		fout << delimiter << endl;
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
	std::ofstream fout("Police.txt");
	fout.close();
	save_file();
	cout << "База данных полностью очищена" << endl;
}
