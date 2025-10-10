#include<Windows.h>
#include"stdafx.h"
///////////////////////////////////////////////////////////////////////////////////////////////
///////////								Initializations							  /////////////
///////////////////////////////////////////////////////////////////////////////////////////////
class Country;
class City;
const std::map<int, std::list<Country>> List_of_countries;
void Menu();
void Call_menu();
void add_Country(std::map<int, std::list<Country>>& List_of_countries);
void add_City();
void delete_Country();
void delete_City();
void count_Countries_in_the_database();
void count_Cities_in_the_database();
void count_Cities_of_the_country_n();
void display_list_of_countries(std::map<int, std::list<Country>>& List_of_countries);
void display_list_of_cities();
void save_database();
void load_database();
void clear_database();
///////////////////////////////////////////////////////////////////////////////////////////////
///////////								key = continent							  /////////////
///////////////////////////////////////////////////////////////////////////////////////////////
const std::map<int, std::string> Continent =
{
	{0, "Евразия"},
	{1, "Африка"},
	{2, "Северная Америка"},
	{3, "Южная Америка"},
	{4, "Австралия"},
	{5, "Антарктида"},
};
///////////////////////////////////////////////////////////////////////////////////////////////
///////////								Class "Country"							  /////////////
///////////////////////////////////////////////////////////////////////////////////////////////
class Country
{
	std::string country;
public:
	const std::string& get_country()const
	{
		return country;
	}
	void set_country(const std::string& country)
	{
		this->country = country;
	}
	Country()
	{
		set_country(country);
	}
	Country(const std::string& country) :country(country) {}
	Country(const Country& other) : country(other.country) {}
	const Country& operator=(const Country& other)
	{
		if (this != &other)
		{
			this->country = other.country;
		}
		return *this;
	}
	virtual ~Country() {}
	void input_info_country()
	{
		cout << "Введите название страны, которую хотите добавить:\t"; 
		SetConsoleCP(1251);
		cin >> country;
		SetConsoleCP(866);
	}
	virtual std::ostream& info(std::ostream& os)const
	{
		return os << "Страна - " << country << endl;
	}
};
std::ostream& operator<<(std::ostream os, const Country& obj)
{
	return obj.info(os);
}
///////////////////////////////////////////////////////////////////////////////////////////////
///////////								Class "City"							  /////////////
///////////////////////////////////////////////////////////////////////////////////////////////
class City :public Country
{
	std::string city;
public:
	const::std::string& get_city()const
	{
		return city;
	}
	void set_city(const std::string& city)
	{
		this->city = city;
	}
	City()
	{
		set_country(city);
	}
	City(const std::string country, const std::string city) :Country(country)
	{
		set_city(city);
	}
	~City() {}
	void input_info_city()
	{
		cout << "Введите название города, который хотите добавить:\t"; cin >> city;
	}
	std::ostream& info(std::ostream& os)const override
	{
		return Country::info(os) << "Город - " << city << endl;
	}
};
std::ostream& operator<<(std::ostream os, const City& obj)
{
	return obj.info(os);
}
///////////////////////////////////////////////////////////////////////////////////////////////
///////////									Main								  /////////////
///////////////////////////////////////////////////////////////////////////////////////////////
#define COUNTRY
void main()
{
	setlocale(LC_ALL, "");

#ifdef COUNTRY
	Call_menu();
#endif // COUNTRY
}
///////////////////////////////////////////////////////////////////////////////////////////////
///////////									Menu								  /////////////
///////////////////////////////////////////////////////////////////////////////////////////////
void Menu()
{
	cout << "1) Добавление/удаление стран и городов" << endl;
	cout << "2) Операции подсчёта" << endl;
	cout << "3) Вывод стран и городов на консоль" << endl;
	cout << "4) Сохранение, загрузка и удаление в файл" << endl;
	cout << "5) Выход" << "\n\n";
}
void menu_subsection_add_delete()
{
	cout << "1) Добавить страну" << endl;
	cout << "2) Добавить город к стране n" << endl;
	cout << "3) Удалить страну и все её города" << endl;
	cout << "4) Удалить город страны \"n\"" << endl;
	cout << "5) Назад в главное меню" << endl;
}
void menu_subsection_count()
{
	cout << "1) Посчитать все страны, находящиеся в базе данных" << endl;
	cout << "2) Посчитать все города, находящиеся в базе данных" << endl;
	cout << "3) Посчитать все города страны \"n\"" << endl;
	cout << "4) Назад в главное меню" << endl;
}
void menu_subsection_display()
{
	cout << "1) Отобразить список загруженных стран" << endl;
	cout << "2) Отобразить список загруженных городов" << endl;
	cout << "3) Назад в главное меню" << endl;
}
void menu_subsection_file()
{
	cout << "1) Сохранить базу данных в файл" << endl;
	cout << "2) Загрузить базу данных из файла" << endl;
	cout << "3) Очистить базу данных" << endl;
	cout << "4) Назад в главное меню" << endl;
}
void Call_menu()
{
	std::map<int, std::list<Country>> List_of_countries;
	int menu_select;
	int subsection_select;
	do
	{
		Menu();
		cout << "Выберите действие:\t"; cin >> menu_select;
		switch (menu_select)
		{
		case 1:
			do
			{
				menu_subsection_add_delete();
				cout << "\nВыберите действие:\t"; cin >> subsection_select;
				switch (subsection_select)
				{
				case 1: add_Country(List_of_countries); break;
				case 2: add_City(); break;
				case 3: delete_Country(); break;
				case 4: delete_City(); break;
				case 5: break;
				}
			} while (subsection_select != 5);
			break;
		case 2:
			do
			{
				menu_subsection_count();
				cout << "\nВыберите действие:\t"; cin >> subsection_select;
				switch (subsection_select)
				{
				case 1: count_Countries_in_the_database(); break;
				case 2: count_Cities_in_the_database(); break;
				case 3: count_Cities_of_the_country_n(); break;
				case 4: break;
				}
			} while (subsection_select != 4);
			break;
		case 3:
			do
			{
				menu_subsection_display();
				cout << "\nВыберите действие:\t"; cin >> subsection_select;
				switch (subsection_select)
				{
				case 1: display_list_of_countries(List_of_countries); break;
				case 2: display_list_of_cities(); break;
				case 3: break;
				}
			} while (subsection_select != 3);
			break;
		case 4:
			do
			{
				menu_subsection_file();
				cout << "\nВыберите действие:\t"; cin >> subsection_select;
				switch (subsection_select)
				{
				case 1: save_database(); break;
				case 2: load_database(); break;
				case 3: clear_database(); break;
				case 4: break;
				}
			} while (subsection_select != 4);
			break;
		case 5:
			cout << "\nРабота завершена" << endl; break;
		}
	} while (menu_select != 5);
}
///////////////////////////////////////////////////////////////////////////////////////////////
///////////								Add_FunctionS							  /////////////
///////////////////////////////////////////////////////////////////////////////////////////////
void add_Country(std::map<int, std::list<Country>>& List_of_countries)
{
	try
	{
		cout << "Выберите континент: " << endl;
		for (std::map<int, std::string>::const_iterator it = Continent.begin(); it != Continent.end(); ++it)
			cout << it->first << " - " << it->second << endl;
		int continent_select;
		cout << "Введите номер континента: "; cin >> continent_select;
		if (continent_select > 5 || continent_select < 0)
			throw std::out_of_range("Сбой программы, выберите значение от 0 до 5 включительно!!!");
		Country country;
		country.input_info_country();
		List_of_countries[continent_select].push_back(country);
		cout << "Страна добавлена в список" << endl;
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Ошибка:\t" << ex.what() << endl;
	}
	catch (...)
	{
		cout << "Неизвестная ошибка: что-то пошло не так" << endl;
	}
}
void add_City()
{

}
///////////////////////////////////////////////////////////////////////////////////////////////
///////////							Delete_Functions							  /////////////
///////////////////////////////////////////////////////////////////////////////////////////////
void delete_Country()
{

}
void delete_City()
{

}
///////////////////////////////////////////////////////////////////////////////////////////////
///////////									Count								  /////////////
///////////////////////////////////////////////////////////////////////////////////////////////
void count_Countries_in_the_database()
{

}
void count_Cities_in_the_database()
{

}
void count_Cities_of_the_country_n()
{

}
///////////////////////////////////////////////////////////////////////////////////////////////
///////////								Display_list							  /////////////
///////////////////////////////////////////////////////////////////////////////////////////////
void display_list_of_countries(std::map<int, std::list<Country>>& List_of_countries)
{
	if (List_of_countries.empty())
	{
		cout << "Вы не внесли в базу данных ни одной страны" << endl;
	}
	else
	{
		cout << "								Ваш список стран" << endl;
		for (std::map<int, std::list<Country>>::const_iterator it = List_of_countries.begin(); it != List_of_countries.end(); ++it)
		{
			//cout << it->first << endl;
			for (std::list<Country>::const_iterator count_country = it->second.begin(); count_country != it->second.end(); ++count_country)
			{
				cout << "Страна:\t" << count_country->get_country() << endl;
			}
			cout << delimiter << endl;
		}
	}
}
void display_list_of_cities()
{

}
///////////////////////////////////////////////////////////////////////////////////////////////
///////////								Save/Load/Clear							  /////////////
///////////////////////////////////////////////////////////////////////////////////////////////
void save_database()
{

}
void load_database()
{

}
void clear_database()
{

}