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

#define POLICE

const std::map<int, std::string> VIOLATIONS =
{
	{0, "N/A"},
	{1, "Парковка в неположенном месте"},
	{2, "Непристёгнутый ремень безопасности"},
	{3, "Пересечение сплошной"},
	{4, "Превышение скорости"},
	{5, "Проезд на красный"},
	{6, "Выезд на встречную полосу"},
	{7, "Езда в нетрезвом состоянии"},
	{8, "Оскорбление офицера"},
};

class Crime
{
	int violation;
	std::string place;
public:
	int get_violation()const
	{
		return violation;
	}
	const std::string& get_place()const
	{
		return place;
	}
	void set_violation(int violation)
	{
		this->violation = violation;
	}
	void set_place(const std::string& place)
	{
		this->place = place;
	}
	Crime(int violation, const std::string& place)
	{
		set_violation(violation);
		set_place(place);
	}
};
std::ostream& operator<<(std::ostream& os, const Crime& obj)
{
	os.width(32);
	os << std::left;
	return os << VIOLATIONS.at(obj.get_violation()) << "\t" << obj.get_place();
}

void print(const std::map<std::string, std::list<Crime>>& base);
void save(const std::map<std::string, std::list<Crime>>& base, const std::string& filename);

void main()
{
	setlocale(LC_ALL, "");

#ifdef POLICE

	std::map<std::string, std::list<Crime>> base =
	{
		{"А777АА", {Crime(4, "Ул. Ленина"), Crime(5, "Ул. Ленина"), Crime(7, "Ул. Энтузиастов"), Crime(8, "Ул. Энтузиастов") } },
		{"a123bb", {Crime(2, "Ул. Пролетарская"), Crime(3, "Ул. Ватутина") } },
		{"a001eg", {Crime(5, "Ул.октябрьская"),Crime(5, "Ул.октябрьская"), Crime(7, "Ул.Космическая"), Crime(8, "Ул.Энтузиастов") } }
	};
	print(base);
	save(base, "base.txt");
#endif	//POLICE

}


void print(const std::map<std::string, std::list<Crime>>& base)
{
	for (std::map<std::string, std::list<Crime>>::const_iterator plate = base.begin(); plate != base.end(); ++plate)
	{
		cout << plate->first << ":\n";
		for (std::list<Crime>::const_iterator violation = plate->second.begin(); violation != plate->second.end(); ++violation)
		{
			cout << "\t" << *violation << endl;
		}
		cout << delimiter << endl;
	}
}

void save(const std::map<std::string, std::list<Crime>>& base, const std::string& filename)
{
	std::ofstream fout(filename/*, std::ios_base::app*/);
	for (std::map<std::string, std::list<Crime>>::const_iterator plate = base.begin(); plate != base.end(); ++plate)
	{
		cout << plate->first << ":\n";
		for (std::list<Crime>::const_iterator violation = plate->second.begin(); violation != plate->second.end(); ++violation)
		{
			fout << "\t" << *violation << endl;
		}
		fout << delimiter << endl;
	}
	fout.close();
	std::string cmd = "notepad ";
	cmd += filename;
	system(cmd.c_str());
	cout << "Данные сохранены в файл base.txt" << endl;
	/*system("start notepad Police.txt");*/
}