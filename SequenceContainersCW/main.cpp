#include<iostream>
#include<array>
#include<vector>
#include<forward_list>
#include<list>
#include<iterator>
#include<deque>
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"
#define delimiter "\n-----------------------------------------------------------------\n"

long long int Factorial(int n);
template<typename T>void vector_info(const std::vector<T>& vec);
template<typename T>void deque_info(const std::deque<T>& vec);

//#define STL_ARRAY
//#define FACTORIAL
#define STL_VECTOR
#define STL_DEQUE
//#define STL_LIST
//#define STL_FORWARD_LIST
//#define STL_LIST_CW
//#define STL_FORWARD_LIST_CW




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

	do
	{
		cout << "Введите значение удаляемого элемента: "; cin >> value;
	} while (index > vec.capacity());
	vec.erase(vec.begin() + index); 
	for (int i : vec)cout << i << tab;
	cout << endl;
#endif // STL_VECTOR

#ifdef STL_DEQUE
	// deque - это контейнер, который хранит данные в виде списка векторов.
	// Это позволяет обеспечить относительно быстрый доступ к элементам, и относительно
	// быстрое добавление/удаление элементов
	// deque - double-ended queue(двунаправленная очередь)
	// deque - по своим возможностям очень напоминает vector, и дополняет его методами 
	// push_front и pop_front
	// в то время как вектор гарантировано хранит данные в одном массиве, элементы deque могут быть разбросаны в памяти
	// Именно поэтому вектор предоставляет прямой доступ к хранилищу в виде указателя на массив, а deque этого не делает
	// deque внтуренне устроен сложнее, чем вектор, но это позволяет ему изменять размер более эффективно
	// при тех же обстоятельствах, что и вектор, особенно при больших размерах
	std::deque<int> deque = { 3, 5, 8, 13, 21 };
	deque.push_back(34);
	deque.push_front(2);

	//std::vector<int>vec;
	//cout << typeid(vec.data()).name() << endl;

	deque_info(deque);
	deque.assign(vec.begin() + 3, vec.end() - 3);
	for (int i : deque)cout << i << tab; cout << endl;

#endif // STL_DEQUE



#ifdef STL_LIST
	std::list<int> numbers{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };	//Список
	std::list<int>::iterator Iterator;							//Указатель на элемент
	for (int n : numbers)
		std::cout << n << "\t";									//Цикл для вывода списка
	std::cout << std::endl;
	Iterator = numbers.begin();									//Указываю на начальный элемент списка
	for (int i = 0; i < 4; ++i)
	{
		++Iterator;												//Цикл для перемещения по списку
	}
	numbers.insert(Iterator, 10);
	for (int n : numbers)
		std::cout << n << "\t";									//Цикл для вывода списка
	std::cout << std::endl;
	for (int i = 0; i < 2; ++i)
	{
		++Iterator;												//Цикл для перемещения по списку
	}
	numbers.erase(Iterator);									//Удаляю элемент на который указывает итератор
	for (int n : numbers)
		std::cout << n << "\t";									//Цикл для вывода списка
	std::cout << std::endl;
#endif // STL_LIST

#ifdef STL_FORWARD_LIST
	std::forward_list<int> numbers = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };	//Односвязный список
	std::forward_list<int>::iterator Iterator;								//указатель на элемент
	for (int i : numbers)
		std::cout << i << "\t";												//Цикл для вывода списка
	std::cout << std::endl;
	Iterator = numbers.before_begin();										//Указываю на начальный элемент списка
	++Iterator;																//Перемещаю указатель на элемент
	++Iterator;																//Перемещаю указатель на элемент
	Iterator = numbers.insert_after(Iterator, 2, 30);						//Добавляю два раза по 30 на место указателя на элемент
	for (int i : numbers)
		std::cout << i << "\t";												//Вывожу односвязный список снова
	std::cout << std::endl;
	for (int i = 1; i < 5; ++i)
	{
		++Iterator;															//Перемещаю указатель на 5-ый элемент после последнего заданного указателя(он же является 9-ый по всему списку)
	}
	numbers.erase_after(Iterator);											//удаляю, элемент на который указывает указатель
	for (int i : numbers)
		std::cout << i << "\t";												//И опять вывожу список
	std::cout << std::endl;
	Iterator = numbers.before_begin();										//Ставлю указатель на нулевой элемент, чтобы прочесать весь односвязный список снова
	for (int i = 0; i < 2; ++i)
	{
		++Iterator;															//Ставлю указатель на второй элемент(с нуля), или же третий с при счёте с единицы(это для себя, ибо я уже запутался во всем этом)				
	}
	for (int i = 0; i < 2; ++i)
	{
		numbers.erase_after(Iterator);										//Соответственно удаляю второй и третий элементы
	}
	//numbers.erase_after(Iterator);
	for (int i : numbers)
		std::cout << i << "\t";												//И опять всё вывожу на консоль
	std::cout << std::endl;

	//std::forward_list<int>::const_iterator Iterator = numbers.cbegin();
#endif // STL_FORWARD_LIST

#ifdef STL_LIST_CW
	//list - это контейнер, который хранит данные в виде двусвязного списка
	std::list<int> list = { 3, 5, 8, 13, 21, 34, 55, 89 };
	list.push_front(2);
	list.push_front(1);
	list.push_front(1);
	list.push_front(0);
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
		cout << *it << tab;
	cout << endl;

	for (std::list<int>::reverse_iterator it = list.rbegin(); it != list.rend(); ++it)
		cout << *it << tab;
	cout << endl;

	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;

	//list.insert(list.begin() + index, value);//Списки не поддерживают арифметику указателей
	std::list<int>::iterator position = list.begin();
	//for (int i = 0; i < index; i++)position++;
	//std::advance(position, index);	//Функция advance() смещает итератор вправо на заданое количество элементов
	//list.insert(position, value);

	std::list<int>::reverse_iterator r_position = list.rbegin();
	std::advance(r_position, list.size() - index);
	position = r_position.base();
	list.insert(position, value);

	for (int i : list)cout << i << tab; cout << endl;



	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	position = list.begin();
	std::advance(position, index);
	list.erase(position);
	for (int i : list)cout << i << tab; cout << endl;


#endif // STL_LIST_CW

#ifdef STL_FORWARD_LIST_CW
	std::forward_list<int> list = { 3, 5, 8, 13, 21 };
	list.push_front(2);
	list.push_front(1);
	list.push_front(1);
	list.push_front(0);
	for (std::forward_list<int>::iterator it = list.begin(); it != list.end(); ++it)
		cout << *it << tab;
	cout << endl;

	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	//std::forward_list<int>::iterator position = list.begin();
	//std::advance(position, index - 1);
	std::forward_list<int>::iterator position = list.before_begin();
	std::advance(position, index);
	list.insert_after(position, value);
	list.insert_after(list.begin(), 16384);
	for (int i : list)cout << i << tab; cout << endl;
#endif // STL_FORWARD_LIST_CW

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

template<typename T>void deque_info(const std::deque<T>& vec)
{
	cout << "Size:\t " << vec.size() << endl;	
	cout << "MaxSize: " << vec.max_size() << endl;
	cout << delimiter << endl;
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