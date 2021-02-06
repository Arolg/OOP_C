#include "Course.h"

Course::Course()
{
	Size = 0;
	for (int i = 0; i < 15; i++)
	{
		ptr[i].name = "None";
	}
}



void Course::SetStud(std::string name)
{
	int i = 0;

	while (ptr[0].name != "None")
	{
		i++;
	}
	ptr[i].name = name;
	Size++;
}

std::string Course::GetStud(int i)
{
	return ptr[i].name;
}

void Course::DelStud(std::string name)
{
	int i = 0;
	while (ptr[i].name != name)
	{
		i++;
	}
	ptr[i].name = "None";
	Size--;
}

int Course::GetSize()
{
	return Size;
}

void Course::SetPrep(std::string name)
{
	name_prep = name;
}

std::string Course::GetPrep()
{
	return std::string(name_prep);
}
