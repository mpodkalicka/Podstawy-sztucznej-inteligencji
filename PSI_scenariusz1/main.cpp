#include <iostream>
#include <fstream>
#include "neuron.h"

using namespace std;

double funAktywacji(double x);
double* read_csv(string plik);

int main()
{
	double *wejscie1 = read_csv("../file1.csv");
	double *wejscie2 = read_csv("../file2.csv");
	neuron *neurone1 = new neuron(64);

	neurone1->setfunkcjaAktywacji(funAktywacji);

	cout << neurone1->start(wejscie2) << endl;
	
	neurone1->nauka(wejscie2, 0);
	cout << neurone1->start(wejscie2) << endl;
	cout << neurone1->start(wejscie1) << endl;

	neurone1->nauka(wejscie1, 1);
	cout << neurone1->start(wejscie1) << endl;
	cout << neurone1->start(wejscie2) << endl;

	system("pause");
	return 0;
}

double funAktywacji(double x)
{
	if (x > 0)
		return 1;
	else
		return 0;
}


double* read_csv(string file)
{

	ifstream is(file);
	
	double *in = new double[64];
	int i = 0;
	char  ch;

	while (is.get(ch))
	{
		if (ch != ',' && ch != '\n')
		{
			in[i] = ch - 48;
			i++;
		}
	}
	is.close();

	return in;
}