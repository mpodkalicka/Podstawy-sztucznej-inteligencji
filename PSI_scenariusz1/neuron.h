#pragma once
typedef double(*fun1)(double x);

class neuron
{
public:
	neuron();
	neuron(int n);
	neuron(int n, double *wagi);
	~neuron();

	void set_wagi(double *m_wagi);
	double get_wagi(int i);
	void set_wagi(double x, int i);

	void set_n(int Mn);
	int get_n() { return n; }

	void setfunkcjaAktywacji(fun1 funAktywacji);
	void set_pochodna(fun1 Mpochodna);
	
	double start(double *input);
	void nauka(double *input, double output);
	fun1 getPochodna() { return pochodna; };


private:
	double *wagi;
	int n;
	fun1 funAktywacji;
	fun1 pochodna;

	double sum(double *m_input);
};

