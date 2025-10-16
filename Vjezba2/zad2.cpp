#include "zad2.h"
#include <iostream>


myVector *vector_new(int fiz_velicina) {
	myVector *vec = new myVector;
	vec->el = new int[fiz_velicina];
	vec->log_vel = 0;
	vec->fiz_vel = fiz_velicina;
	return vec;
}

void vector_delete(myVector *vec)
{
	delete[] vec->el;
}

void vector_push_back(myVector* vec, int value) {
	if (vec->log_vel >= vec->fiz_vel) {
		int new_capacity = vec->fiz_vel * 2;
		int* novi_vek = new int[new_capacity];

		for (int i = 0; i < vec->log_vel; ++i) {
			novi_vek[i] = vec->el[i];
		}

		delete[] vec->el;
		vec->el = novi_vek;
		vec->fiz_vel = new_capacity;
	}

	vec->el[vec->log_vel++] = value;
}