#include "stdafx.h"
#include <iostream>
#include "name.h"

Drobi reduce(Drobi **table, int i, int j){
	int r = 2;
	while (r <= table[i][j].x){
		if (table[i][j].x%r || table[i][j].y%r)
			r++;
		if (table[i][j].x%r == 0 & table[i][j].y%r == 0){
			table[i][j].x = table[i][j].x / r;
			table[i][j].y = table[i][j].y / r;
		}
	}
	return table[i][j];
}

void show(Drobi **table, int size){
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if (table[i][j].x == 0)
				std::cout << "\t";
			else
				std::cout << table[i][j].x << "/" << table[i][j].y << "\t";
		}
		std :: cout << std :: endl;
	}
}

void multiplication_table(Drobi *numbers, Drobi **table, int size){
	for (int i = 0; i < size; i++){
		numbers[i].x = i;
		numbers[i].y = size;
	}
	for (int i = 1; i < size; i++){
		for (int j = 1; j < size; j++){
			table[i][j].x = numbers[i].x*numbers[j].x;
			table[i][j].y = numbers[i].y*numbers[j].y;
		}
	}
	for (int i = 0; i < size; i++){
		table[i][0].x = i;
		table[0][i].x = i;
		table[i][0].y = size;
		table[0][i].y = size;
	}
	for (int i = 0; i < table[0][1].y; i++)
		for (int j = 0; j < table[0][1].y; j++){
		reduce(table, i, j);
		}
	show(table, size);
}