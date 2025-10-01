//Factorial_Find_Error_Through_Class
#include<iostream>
#include<array>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

template<typename T>
class WrongFactorialNumberException
{
public:
	T number;
	T get_number()const
	{
		return number;
	}
	void set_number(T number)
	{
		this->number = number;
	}
	WrongFactorialNumberException(T number) : number(number) {}
	~WrongFactorialNumberException() {}

	WrongFactorialNumberException<T>& operator=(const WrongFactorialNumberException<T>& other)
	{
		if (this == &other)return *this;
		this->number = other.number;
		return *this;
	}

	WrongFactorialNumberException<T>& operator*=(const WrongFactorialNumberException<T>& other)
	{
		return *this = *this * other;
	}

	WrongFactorialNumberException<T>& operator++()
	{
		number++;
		return *this;
	}

	WrongFactorialNumberException<T> operator++(int)
	{
		WrongFactorialNumberException old = *this;
		number++;
		return old;
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////
//////									ОПЕРАТОРЫ СРАВНЕНИЯ									//////
//////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
bool operator==(const WrongFactorialNumberException<T>& left, const WrongFactorialNumberException<T>& right)
{
	return left.get_number() == right.get_number();
}

template<typename T>
bool operator!=(const WrongFactorialNumberException<T>& left, const WrongFactorialNumberException<T>& right)
{
	return left.get_number() != right.get_number();
}
template<typename T>
bool operator<(const WrongFactorialNumberException<T>& left, const WrongFactorialNumberException<T>& right)
{
	return left.get_number() < right.get_number();
}

template<typename T>
bool operator>(const WrongFactorialNumberException<T>& left, const WrongFactorialNumberException<T>& right)
{
	return left.get_number() > right.get_number();
}

template<typename T>
bool operator<=(const WrongFactorialNumberException<T> left, const WrongFactorialNumberException<T> right)
{
	return left.get_number() <= right.get_number();
}

template<typename T>
bool operator>=(const WrongFactorialNumberException<T>& left, const WrongFactorialNumberException<T>& right)
{
	return left.get_number() >= right.get_number();
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//////							ОПЕРАТОРЫ ВХОДА/ВЫХОДА В ПОТОК								//////
//////////////////////////////////////////////////////////////////////////////////////////////////

std::istream& operator>>(std::istream& is, WrongFactorialNumberException<int>& obj)
{
	return is >> obj.number;
}

std::ostream& operator<<(std::ostream& os, const WrongFactorialNumberException<int>& obj)
{
	return os << obj.get_number();
}

template<typename T>
T Factorial_Number()
{
	std::cin.exceptions(std::istream::failbit);	//// эта строчка нужна для поимки исключений на месте потока ввода
	T number;
	cin >> number;
	if (number < 0 || number >= 17)
	{
		throw WrongFactorialNumberException<T>(number);
	}
	return number;
}

template<typename T>
T factorial(T Number)
{
	T Factorial = 1;
	for (T i = 1; i <= Number; i++)
	{
		Factorial *= i;
	}
	return Factorial;
}
template<typename T>T Recursion_factorial(T Number)
{
	if (Number == 0) return 1;
	return Number * Recursion_factorial<T>(Number - 1);
}

//#define FACTORIAL
#define Factorial_Array

int main()
{
	setlocale(LC_ALL, "");
#ifdef FACTORIAL
	try
	{
		cout << "Введите число, факториал которого хотите узнать: ";
		WrongFactorialNumberException<int> number(Factorial_Number<int>());
		cout << "Факториал числа " << number << " = " << factorial(number.get_number()) << endl;
		cout << "Факториал числа " << number << " = " << Recursion_factorial(number.get_number()) << endl;
	}
	catch (const WrongFactorialNumberException<int>& ex)
	{
		std::cerr << "Число " << ex.get_number() << " не подходит условиям" << endl;
		return 0;
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Не удалось прочитать число по причине: " << ex.what() << endl;
		return 0;
	}
	catch (...)
	{
		std::cerr << "Неизвестная ошибка\n";
		return 0;
	}
#endif // FACTORIAL

#ifdef Factorial_Array//(NET)
	int quantity;
	cout << "Введите количество чисел на проверку факториала: "; cin >> quantity;
	cout << "Введите массив: " << endl;
	try
	{
		for (int i = 0; i < quantity; i++)
		{
			WrongFactorialNumberException<int> number(Factorial_Number<int>());
			cout << "Факториал числа " << number << " = " << factorial(number.get_number()) << endl;
		}
	}
	catch (const WrongFactorialNumberException<int>& ex)
	{
		std::cerr << "Число " << ex.get_number() << " не подходит условиям" << endl;
		system("PAUSE");
		return main();
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Не удалось прочитать число по причине: " << ex.what() << endl;
		system("PAUSE");
		return main();
	}
	catch (...)
	{
		std::cerr << "Неизвестная ошибка\n";
		system("PAUSE");
		return main();
	}
#endif // Factorial_through_Array
}