#include <chrono>
#include <ctime>
#include <iostream>
#include "sorts.h"
#include <iomanip>
#include <fstream>

using namespace std;


int main()

{
	setlocale(LC_ALL, "rus");

	//Zadanie_1


	const int razmer = 10;
	int massiv1[razmer] = { -10, 5, 28, 94, 34, -166, 78, 22, 87, 100 };

	std::cout << endl << "#Zadanie_1" << endl << endl;
	std::cout << "Input massiv: ";

	for (int i = 0; i < razmer; i++)
	{
		std::cout << massiv1[i] << " ";
	}

	MergeSort(massiv1, razmer);

	std::cout << endl << endl << "Output massiv: ";
	for (int i = 0; i < razmer; i++)
	{
		std::cout << massiv1[i] << " ";
	}

	std::cout << endl << endl << endl;


   //Zadanie_2
	std::cout << "#Zadanie_2 " << endl;
	std::cout << endl << "QuickSort" << endl;
	srand(time(NULL));

	const int massiv_counts = 10;
	const int counts_elements[massiv_counts] = { 100, 500, 1000, 2500, 5000, 10000,
												50000, 100000, 500000, 1000000 };


	for(int i = 0; i < massiv_counts; i++)
	{
		int* massiv = new int[counts_elements[i]];
		for (int j = 0; j < counts_elements[i]; j++)
		{
			massiv[j] = rand() % 100001;
		}
		auto start_time = chrono::steady_clock::now();
		QuickSort(massiv, counts_elements[i]);
		auto end_time = chrono::steady_clock::now();
		std::cout << endl <<  "massiv size:\t" <<counts_elements[i] << "\t" << "	duration time = " << chrono::duration_cast <chrono::microseconds>(end_time - start_time).count() << "us" << endl;
		delete[] massiv;
	}

	//Zadanie_3 (Возьмем массивы с размерностями от 10 до 10000)

	ofstream file_out;
	file_out.open("output_file3.txt");

	if (!file_out.is_open())
	{
		std::cout << "Ошибка открытия файла";

	}
	
	string max_count = "1000000";
	int max = max_count.size();

	std::cout << endl << endl << "#Zadanie_3 (100 <= size <= 10000)" << endl << "check file: output_file3.txt" << endl << endl;
	string t = "    ";

	string massiv_words[6] = { "Размер массива", "Время выполнения BubbleSort",
	"Время выполнения InsertionSort","Время выполнения SelectionSort", "Время выполнения QuickSort", "Время выполнения MergeSort"};

	int massiv_lengh_words[6];

	int length = 0;

	for (int i = 0; i < 6; i++)
	{
		length = massiv_words[i].size();
		massiv_lengh_words[i] = length;
	}
	

	for (int i = 0; i < 6; i++)
	{
		file_out << massiv_words[i] << "        ";
	}

	std::cout << endl << endl;
	file_out << endl << endl;
	

	for (int i = 0; i < massiv_counts; i++)
	{	 
		if (counts_elements[i] == 50000)  //(Возьмем массивы с размерностями от 10 до 10000)
			break;


		int* massiv = new int[counts_elements[i]];   // Создание динамического массива
		for (int j = 0; j < counts_elements[i]; j++)
		{
			massiv[j] = rand() % 100001;
		}

		int* copy_massiv_1 = new int[counts_elements[i]];  // Создание первой копии 
		for (int j = 0; j < counts_elements[i]; j++)
		{
			copy_massiv_1[j] = massiv[j];
		}

		int* copy_massiv_2 = new int[counts_elements[i]];  // Создание второй копии 
		for (int j = 0; j < counts_elements[i]; j++)
		{
			copy_massiv_2[j] = massiv[j];
		}

		int* copy_massiv_3 = new int[counts_elements[i]];  // Создание третьей копии 
		for (int j = 0; j < counts_elements[i]; j++)
		{
			copy_massiv_3[j] = massiv[j];
		}

		int* copy_massiv_4 = new int[counts_elements[i]];  // Создание четвертой копии 
		for (int j = 0; j < counts_elements[i]; j++)
		{
			copy_massiv_4[j] = massiv[j];
		}


		auto start_time_Bubble = chrono::steady_clock::now();
		BubbleSort(massiv, counts_elements[i]);
		auto end_time_Bubble = chrono::steady_clock::now();

		auto start_time_Insertion = chrono::steady_clock::now();
		InsertionSort(copy_massiv_1, counts_elements[i]);
		auto end_time_Insertion = chrono::steady_clock::now();

		auto start_time_Selection = chrono::steady_clock::now();
		SelectionSort(copy_massiv_2, counts_elements[i]);
		auto end_time_Selection = chrono::steady_clock::now();

		auto start_time_Quick = chrono::steady_clock::now();
		QuickSort(copy_massiv_3, counts_elements[i]);
		auto end_time_Quick = chrono::steady_clock::now();

		auto start_time_Merge = chrono::steady_clock::now();
		MergeSort(copy_massiv_3, counts_elements[i]);
		auto end_time_Merge = chrono::steady_clock::now();

		//Запись в файл
		file_out << endl << setw(massiv_lengh_words[0]) << counts_elements[i] << setw(massiv_lengh_words[1] + 6)
			<< chrono::duration_cast <chrono::microseconds>(end_time_Bubble - start_time_Bubble).count() << "us" <<
			setw(massiv_lengh_words[2] + 6) << chrono::duration_cast <chrono::microseconds>(end_time_Insertion - start_time_Insertion).count() << "us" <<
			setw(massiv_lengh_words[3] + 6) << chrono::duration_cast <chrono::microseconds>(end_time_Selection - start_time_Selection).count() << "us" <<
			setw(massiv_lengh_words[4] + 6) << chrono::duration_cast <chrono::microseconds>(end_time_Quick - start_time_Quick).count() << "us" <<
			setw(massiv_lengh_words[5] + 6) << chrono::duration_cast <chrono::microseconds>(end_time_Merge - start_time_Merge).count() << "us" << endl;
			

		delete[] massiv;
		delete[] copy_massiv_1;
		delete[] copy_massiv_2;
		delete[] copy_massiv_3;
		delete[] copy_massiv_4;
	}

	file_out.close();

	return 0;
	
}

