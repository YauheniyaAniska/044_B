// 044_B.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "name.h"
#include <Windows.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[]){
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian");
	int size;
	cout << "Введите знаменатель: ";
	cin >> size;
	while (!cin.good() || size < 0){
		cin.clear();
		cin.ignore(255, '\n');
		cout << "Значение введено неверно. Повторите ввод" << endl;
		cin >> size;
	}
	Drobi *numbers;
	numbers = new Drobi[size];
	Drobi **table;
	table = new Drobi*[size];
	for (int i = 0; i < size; i++){
		table[i] = new Drobi[size];
	}
	multiplication_table(numbers, table, size);
	for (int i = 0; i < size; i++)
		delete[] table[i];
	delete[] table;
	delete[] numbers;
	system("pause");
	return 0;
}

