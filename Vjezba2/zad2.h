#ifndef ZAD2_H
#define ZAD2_H

#include <cstddef>
#include <iostream>

struct myVector {
	int *el;
	int log_vel;
	int fiz_vel;
};

myVector *vector_new(int fiz_velicina);
void vector_delete(myVector *vec);

#endif