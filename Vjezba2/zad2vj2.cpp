#include <iostream>
#include <string>
#include <cctype>

struct Vector
{
	int* el{};
	int log_vel{};
	int fiz_vel{};
};

void vector_new(Vector& v,int velicina)
{
	v.el = new int[velicina];
	v.log_vel = 0;
	v.fiz_vel = velicina;
}

void vector_delete(Vector& v)
{
	delete[] v.el;
	v.fiz_vel = 0;
	v.log_vel = 0;
}

void vector_push_back(Vector& v,int element)
{
	if (v.log_vel >= v.fiz_vel)
	{
		int nova_fiz_vel = v.fiz_vel * 2;
		int *novi = new int[nova_fiz_vel];
		
		for (int i = 0; i < v.log_vel;i++)
			novi[i] = v.el[i];
			
		delete[] v.el;
		v.el = novi;
		v.fiz_vel = nova_fiz_vel;
	}	
	
	v.el[v.log_vel++] = x;	
}

void vector_pop_back(Vector& v)
{
    if (v.log_vel > 0)
        v.log_vel--;
}

int vector_front(const Vector& v)
{
    return v.elementi[0];
}

int vector_back(const Vector& v)
{
    return v.elementi[v.log_vel - 1];
}

int vector_size(const Vector& v)
{
    return v.log_vel;
}


int main()
{
    Vector v;
    vector_new(v, 2);

    vector_push_back(v, 10);
    vector_push_back(v, 20);
    vector_push_back(v, 30); 

    vector_print(v);

    std::cout << "Prvi element: " << vector_front(v) << '\n';
    std::cout << "Zadnji element: " << vector_back(v) << '\n';
    std::cout << "Velicina: " << vector_size(v) << '\n';

    vector_pop_back(v);
    vector_print(v);

    vector_delete(v);
    return 0;
}


