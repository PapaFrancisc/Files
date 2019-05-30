#include <iostream>
#include <fstream>

using namespace std;

//#define INTRODUCTION_IN_FILES

void main()
{
	setlocale(LC_ALL, "Rus");

#ifdef INTRODUCTION_IN_FILES

	cout << "Hello World!\n";
	//1) Создаем поток вывода в файл 
	ofstream fout("File.txt", ios::app);

	fout << "Hello WOrld";
	//закрываем в 
	fout.close();
	//system("notepad File.txt");

	ifstream fin("File.txt");

	if (fin.is_open())
	{
		const int n = 256;
		char sz_buffer[n]{};
		while (!fin.eof())
		{
			//fin >> sz_buffer;
			fin.getline(sz_buffer, n);
			cout << sz_buffer << endl;
		}
	}

	fin.close();
#endif // INTRODUCTION_IN_FILES


	//1) Создаем потоки
	
	const int SIZE = 256;
	char src_filename[SIZE]{}; //source file name
	char dst_filename[SIZE]{}; //destination file name
	cout << "Введите имя исходного файла: "; 
	cin.getline(src_filename, SIZE);
	cout << "Введите имя исходного файла: ";
	cin.getline(dst_filename, SIZE);
	
	ifstream fin(src_filename);
	ofstream fout(dst_filename);

	//2) Создаем буферы в которые будет производиться чтение из файла
	const int IP_MAX_SIZE = 16;
	const int MAC_MAX_SIZE = 18;
	char sz_IPbuffer[IP_MAX_SIZE]{};
	char sz_MACbuffer[MAC_MAX_SIZE]{};


	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> sz_IPbuffer;
			fin >> sz_MACbuffer;
			fout << sz_MACbuffer <<"\t";
			fout << sz_IPbuffer << "\n";

		}
	}


	fin.close();
	fout.close();
	system(dst_filename);

}