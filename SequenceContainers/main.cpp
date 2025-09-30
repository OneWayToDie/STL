#include<iostream>
#include<array>
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"

//#define STL_ARRAY
#define FACTORIAL


// Структуры задействовал для передачи данных в функцию, которая помогает выискивать ошибки
template<typename T>
struct WrongFactorialNumberException
{
	T number;
public:
	WrongFactorialNumberException(T number) : number(number) {}	// Создал конструктор для возможности передачи number в функцию*
};

template<typename T>T Factorial_Number()
{
	std::cin.exceptions(std::istream::failbit); // эта строчка нужна для поимки исключений на месте потока ввода
	T number;
	cin >> number;
	if (number < 0 || number >= 17) 
	{
		throw WrongFactorialNumberException<int>(number);	//*применение number из struct
	}
	return number;
}

template<typename T>T factorial(T Number)
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
	return Number * factorial(Number - 1);
}

void main()
{
	setlocale(LC_ALL, "");

#ifdef STL_ARRAY
	//array - это контейнер, который хранит данные в виде статического массива;
	throw;
	const int n = 5;
	std::array<int, n> arr;
	for (int i = 0; i < arr.size(); i++)
	{
		arr.at(i) = rand() % 100;
	}
	try
	{
		for (int i = 0; i < arr.size() * 2; i++)
		{
			cout << arr.at(i) << tab;
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	/*catch (...)
	{
		std::cout << "Error: Something went wrong" << endl;
	}*/

	for (int i : arr)
	{
		cout << i << tab;
	}
	cout << endl;
	//std::string str;

#endif

#ifdef FACTORIAL
	int number;
	try
	{
		cout << "Введите число, факториал которого хотите узнать - "; 
		number = Factorial_Number<int>(); cout << endl;
		cout << "Факториал числа " << number << " = " << factorial(number) << endl;
		cout << "Факториал числа " << number << " = " << Recursion_factorial(number) << endl;
	}
	catch (const WrongFactorialNumberException<int>& I_dont_know)
	{
		std::cerr << "Число "<< I_dont_know.number << " не подходит условиям"  << endl;
	}
	catch (const std::exception& I_dont_know)
	{
		std::cerr << "Не удалось прочитать число по причине: " << I_dont_know.what() << endl;
	}
	catch (...)
	{
		std::cerr << "Неизвестная мне ошибка\n";
	}
#endif // FACTORIAL
}


