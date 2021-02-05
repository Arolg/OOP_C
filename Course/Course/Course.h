// Course.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#include <iostream>
#include <memory>
class Course
{
public:
	Course();
	void SetStud(std::string name);			//добавлять студентов
	std::string GetStud(int i);				//выводить на экран студента
	void DelStud(std::string name);			//удалить студента
	int GetSize();
	void SetPrep(std::string name);		
	std::string GetPrep();
private:
	const int size = 15;
	class Student
	{
	public:
		std::string name;

	};
	std::shared_ptr<Student[]> ptr{ new Student[size] };
	int Size;
	std::string name_prep;
};

// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.
