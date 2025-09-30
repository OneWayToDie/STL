#include<iostream>
#include<array>
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"

//#define STL_ARRAY
#define FACTORIAL


// ��������� ������������ ��� �������� ������ � �������, ������� �������� ���������� ������
template<typename T>
struct WrongFactorialNumberException
{
	T number;
public:
	WrongFactorialNumberException(T number) : number(number) {}	// ������ ����������� ��� ����������� �������� number � �������*
};

template<typename T>T Factorial_Number()
{
	std::cin.exceptions(std::istream::failbit); // ��� ������� ����� ��� ������ ���������� �� ����� ������ �����
	T number;
	cin >> number;
	if (number < 0 || number >= 17) 
	{
		throw WrongFactorialNumberException<int>(number);	//*���������� number �� struct
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
	//array - ��� ���������, ������� ������ ������ � ���� ������������ �������;
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
		cout << "������� �����, ��������� �������� ������ ������ - "; 
		number = Factorial_Number<int>(); cout << endl;
		cout << "��������� ����� " << number << " = " << factorial(number) << endl;
		cout << "��������� ����� " << number << " = " << Recursion_factorial(number) << endl;
	}
	catch (const WrongFactorialNumberException<int>& I_dont_know)
	{
		std::cerr << "����� "<< I_dont_know.number << " �� �������� ��������"  << endl;
	}
	catch (const std::exception& I_dont_know)
	{
		std::cerr << "�� ������� ��������� ����� �� �������: " << I_dont_know.what() << endl;
	}
	catch (...)
	{
		std::cerr << "����������� ��� ������\n";
	}
#endif // FACTORIAL
}


