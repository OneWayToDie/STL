#include<iostream>
#include<array>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"
#define delimiter "\n-----------------------------------------------------------------\n"

long long int Factorial(int n);
template<typename T>void vector_info(const std::vector<T>& vec);

//#define STL_ARRAY
//#define FACTORIAL
#define STL_VECTOR



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

	int n;
	cout << "Введите число: "; cin >> n;
	try
	{
		cout << n << "! = " << Factorial(n) << endl;
	}
	//catch (const char* e)
	//{
	//	std::cerr << e << endl;
	//}
	catch (const std::runtime_error& e)
	{
		std::cerr << "runtime_error: ";
		std::cerr << e.what() << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: ";
		std::cerr << e.what() << endl;
	}
#endif // FACTORIAL

#ifdef STL_VECTOR

	std::vector<int> vec = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << tab;
	}
	cout << endl;
	vector_info(vec);


	vec.push_back(55);
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		cout << *it << tab;
	cout << endl;


	for (std::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
		cout << *it << tab;
	cout << endl;
	vector_info(vec);
	//vec.shrink_to_fit();	//Урезает capacity до фактического размера
	//vec.reserve(1600);
	//vec.push_back(1024);
	//vec.resize(18);
	for (int i : vec)cout << i << tab; cout << endl;
	vector_info(vec);
	cout << vec.front() << endl;
	cout << vec.back() << endl;
	////////////////////////////////////////////////////////////////////////////////////////////
	int index;
	int value;
	do
	{
		cout << "Введите индекс добавляемого элемента: "; cin >> index;
		cout << "Введите значение добавляемого элемента: "; cin >> value;
	} while (index>vec.capacity());
	vec.insert(vec.begin() + index, value);
	for (int i : vec)cout << i << tab; cout << endl;
#endif // STL_VECTOR
}

long long int Factorial(int n)
{
	if (n > 20)throw std::runtime_error/*exception*/("Arithmetical overflow exception");
	long long int f = 1;
	for (int i = 1; i <= n; i++)
	{
		f *= i;
	}
	return f;
}


template<typename T>void vector_info(const std::vector<T>& vec)
{
	cout << "Size:\t " << vec.size() << endl;		//Фактический размер вектора, показывающий, сколько элементов хранит вектор
	cout << "MaxSize: " << vec.max_size() << endl;
	cout << "Capacity:" << vec.capacity() << endl;	//Объём зарезервированной памяти. Зарезервированная память нужна для того
	// Чтобы ускорить процесс добавления элементов, и избежать необходимость переопределять память при каждом добавлении элемента
	// Это экономит ресурсы процессорного времени, но расходует дополнительные ресурсы памяти.
	// Если у вектора есть свободная зарезервированная память, то добавляемое значение просто записывается в конец массива,
	// Но если зарезервированная память закончилась, то при добавлении элемента - Вектор резервирует новую память
	// В половину больше фактического размера(В полтора раза больше фаткического размера).
	// На capacity можно повлиять при помощи методов reserve(), resize() и shrink_to_fit()
	cout << delimiter << endl;
}