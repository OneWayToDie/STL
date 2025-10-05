#include<iostream>
#include<map>
#include<list>
#include<set>
#include<fstream>
using std::cin;
using std::cout;
using std::endl;


#define tab "\t"
#define delimiter "\n----------------------------------------------------\n"

template<typename T>T list();


//Сделал два класса без делегирования, потому что не знаю как их реализовать в std::map по другому, один передаёт номер машины, которая получила штраф, в другой передаёт штрафные санкции/причину штрафа
//template<typename T>
//class number
//{
//	T car_number;
//public:
//	T get_car_number()const
//	{
//		return car_number;
//	}
//	void set_car_number(T car_number)
//	{
//		this->car_number = car_number;
//	}
//	number(T car_number)
//	{
//		set_car_number(car_number);
//	}
//	virtual ~number() {};
//	virtual std::ostream& info(std::ostream& os)const
//	{
//		return os << "Номер машины - " << car_number << "  ";
//	}
//	bool operator<(const number& other)const 
//	{
//		return this->car_number < other.car_number;
//	}
//};
//
//
//std::ostream& operator<<(std::ostream& os, const number<std::string>& obj)
//{
//	return obj.info(os);
//}
//
//template<typename T>
//class criminalitet/* :public number*/
//{
//	T violation;
//public:
//	const T get_violation()const
//	{
//		return violation;
//	}
//	void set_violation(T violation)
//	{
//		this->violation = violation;
//	}
//	criminalitet(T violation/*, int car_number*/) /*:number(car_number)*/
//	{
//		set_violation(violation);
//	}
//	~criminalitet() {};
//	virtual std::ostream& info(std::ostream& os)const /*override*/
//	{
//		return os/*number::info(os) <<*/ << "Список нарушений: " << violation << "  ";
//	}
//};
//
//std::ostream& operator<<(std::ostream& os, const criminalitet<std::string>& obj)
//{
//	return obj.info(os);
//}

//#define POLICE

void main()
{
	setlocale(LC_ALL, "");

#ifdef POLICE
	//number<std::string> number_car(number_of_fool);
	std::string number_of_fool;
	cout << "Введите номер машины: "; cin >> number_of_fool;
	std::string delinquent = list<std::string>();
	//std::string criminal = list<std::string>();
	//int again;
	//cout << "Хотите ещё выписать на чей-то номер штраф? нажмите \"1\", если хотите продолжить, и любую другую цифру, если хотите выйти:\t"; cin >> again;

	std::ofstream fout("Police.txt", std::ios_base::app);
	std::map<std::string, std::string> The_list_of_fools;
	//do {
	//		The_list_of_fools[number_of_fool] = delinquent;
	//	} while (again == 1);
	for (int i = 0; i < 1000; i++)
	{
		int again;
			cout << "Хотите ещё выписать на чей-то номер штраф? нажмите \"1\", если хотите продолжить, и любую другую цифру, если хотите выйти:\t"; cin >> again;
			if (again == 1)
			{
				The_list_of_fools[number_of_fool] = delinquent;
			}
			else
			{
				i = 999;
			}
	}
	for (std::map<std::string, std::string>::iterator it = The_list_of_fools.begin(); it != The_list_of_fools.end(); ++it)
	{
		cout << it->first << tab << it->second << endl;
		fout << it->first << tab << it->second << endl;
	}
	fout.close();
	system("start notepad Police.txt");

#endif	//POLICE

}

template<typename T>T list()
{
	T criminal;
	cout << "Введите причину штрафа: "; cin >> criminal;
	bool true_false;
	cout << "Это всё, или ещё есть штрафные санкции? \nВведите \"1\" если хотите продолжить вводить нарушения, и любую другую цифру если хотите закончить:\t"; cin >> true_false;
	if (true_false == 1)
	{
		return list<T>();
	}
	else
	{
		return criminal;
	}
}
