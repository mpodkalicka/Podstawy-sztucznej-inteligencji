#include <iostream>
#include <cstdlib>
#include <ctime>
#include "neuron.h"


double f_rand(double f_min, double f_max)
{
	double f = (double)rand() / RAND_MAX;
	return f_min + f * (f_max - f_min);
}
neuron::neuron()
{
	wagi = NULL;
	funAktywacji = NULL;
	srand(time(NULL));
}
neuron::neuron(int Mn) :
	n(Mn)
{
	funAktywacji = NULL;
	srand(time(NULL));
	wagi = new double[n];
	for (int i = 0; i < n; i++)
	{
		wagi[i] = f_rand(0, 1);
	}
}
neuron::neuron(int Mn, double *m_wagi) :
	n(Mn),
	wagi(m_wagi)
{
	funAktywacji = NULL;
	srand(time(NULL));
}
void neuron::set_wagi(double *m_wagi)
{
	wagi = m_wagi;
}
double neuron::get_wagi(int i)
{
	if (wagi != NULL && i < n)
	{
		return wagi[i];
	}
	else
	{
		throw "error-getWagi";
	}
}
void neuron::set_wagi(double x, int i)
{
	if (wagi != NULL && i < n)
	{
		wagi[i] = x;
	}
	else
	{
		throw "error-set_wagi";
	}
}
void neuron::set_n(int Mn)
{
	n = Mn;

}
void neuron::setfunkcjaAktywacji(fun1 m_funkcjaAktywuj¹ca)
{
	funAktywacji = m_funkcjaAktywuj¹ca;
}
void neuron::set_pochodna(fun1 Mpochodna)
{
	pochodna = Mpochodna;
}
double neuron::start(double *inputs)
{
	if (funAktywacji == 0)
		throw "ustaw funkcje aktyacji!";
	double a = sum(inputs);
	return funAktywacji(a);

}
double neuron::sum(double *m_input)
{

	double suma = 0;
	for (int i = 0; i < n; i++)
	{
		suma += wagi[i] * m_input[i];
	}

	return suma;
}
void neuron::nauka(double * input, double output)
{
	if (funAktywacji == 0)
		throw "ustaw funkcje aktywacji!";

	double ni = 0.5;
	double result = this->start(input);
	if (result != output)
	{
		for (int i = 0; i < n; i++)
		{
			wagi[i] += ni*(output - result)*input[i];
		}
	}


}
neuron::~neuron()
{
	delete wagi;
}