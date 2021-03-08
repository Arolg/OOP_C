#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
using namespace std;

void register1(string& arr)
{
	for (auto &element : arr)
	{
		if (element > 'A' && element < 'Z') element += 'z' - 'Z';
		if (element > 'А' && element < 'Я') element += 'я' - 'Я';
	}
	
}
void file_of(const string& arr, const string& c)
{
	ofstream fout;
	fout.exceptions(ofstream::badbit | ofstream::failbit);
	try
	{
		fout.open(c, ofstream::app);
		fout << arr << endl;
		fout.close();
	}
	catch (const ofstream::failure& ex)
	{
		cerr << ex.what() << endl;
		cerr << ex.code() << endl;
		cerr << "Error to write file"<< c << endl;
		cout << "=========================" << endl;
	}
}

int main()
{
	string MyFile = "MyFile.txt";
    string c = "processed//c.txt";
	string even = "processed//even.txt";
	string odd = "processed//odd.txt";
	string directory = "processed";
	string str;
	try
	{
		std::filesystem::create_directory(directory);
	}
	catch (const std::filesystem::filesystem_error& ex)
	{
		cerr << ex.what() << endl;
		cerr << ex.code() << endl;
		cerr << "Error to create directory" << endl;
		cout << "=========================" << endl;
	}
	ofstream fout;
	ifstream fin;
	fout.exceptions(ofstream::badbit | ofstream::failbit);
	fin.exceptions(ifstream::badbit | ifstream::failbit);
	try
	{
		fout.open(MyFile);
		cout << "Enter the text in MyFile for further sorting\nEnter 1 to stop writing:";
		while (true)
		{
			str = "";
			cin >> str;
			if (str == "1")
			{
				break;
			}
			fout << str << endl;
		}
		fout.close();
	}
	catch (const ofstream::failure& ex)
	{
		cerr << ex.what() << endl;
		cerr << ex.code() << endl;
		cerr << "Error to write file MyFile" << endl;
		cout << "=========================" << endl;
	}
	
	try
	{
		
		fin.open(MyFile);
		while (!fin.eof())			//как я понял жалуется на eof, как исправить я не в курсе
		{
			str = "";
			fin >> str;
			register1(str);
			int s = str.find("c", 0);
			if (s >= 0)
			{
				str[s] = 'C';
				file_of(str, c);
			}
			else
			{
				if (str.size() % 2 == 0)
				{
					str.push_back('_');
					file_of(str, even);
				}
				else
				{
					str.push_back('_');
					file_of(str, odd);
				}
			}
		}
		fin.close();
	}
	catch (const ifstream::failure& ex)
	{
		cerr << ex.what() << endl;
		cerr << ex.code() << endl;
		cerr << "Error to read file MyFile" << endl;
		cout << "=========================" << endl;
	}


   

	
    
}
