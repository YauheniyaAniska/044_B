#ifndef NAME_H_
#define NAME_H_

struct Drobi{
	int x;
	int y;
};

Drobi reduce(Drobi **table, int i, int j);
void show(Drobi ** table, int size);
void multiplication_table(Drobi *numbers, Drobi **table, int size);
#endif