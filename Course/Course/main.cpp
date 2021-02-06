// Course.cpp: определяет точку входа для приложения.
//

#include "Course.h"



int main()
{
	Course a;
	std::string name;
	std::cin >> name;
	a.SetStud(name);

	for (int i = 0; i < 15; i++)
	{
		std::cout << a.GetStud(i) << std::endl;
	}




	return 0;
}
