#include <iostream>
#include <stdlib.h>

using namespace std;
int tabli[100];
int iter = 0;
int nwd(int a, int b) {
	int c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int phi(unsigned long long n) 
{
	double suma = n;
	int dzielnik = 2;
	while (n != 1) {
		while (n % dzielnik != 0)
			dzielnik++;
		suma *= (1 - 1.0 / dzielnik);
		while (n % dzielnik == 0)
			n /= dzielnik;
	}
	return int(suma);
}


int spModulo(unsigned long long x, unsigned long long y, unsigned long long m)
{
	int w = x;
	if (nwd(x, m) == 1)
		y = y % phi(m);
	for (int i = 1; i < y; i++)
		w = (w * x) % m;
	return w;
}
int spModulo2(unsigned long long x, unsigned long long y, unsigned long long m, unsigned long long n) 
{
	int w = x;
	if (nwd(x, m) == 1)
		y = y % phi(m);
	for (int i = 1; i < y/n; i++)
		w = (w * x) % m;
	return w;
}

void Fermat(unsigned int p) 
{
	unsigned long long x, y, z, m, n;
	x = (unsigned long long)ceil(sqrt(p));
	do {
		z = x * x - p;
		y = (unsigned long long)floor(sqrt(z));
		if (z == y * y)
		{
			m = x + y;
			n = x - y;
			if (n == 1) break;
			Fermat(m);
			Fermat(n);
			return;
		}
		x++;
	} while (x + y < p);
	tabli[iter] = p;
	iter++;
}

void test_lucasa(unsigned int n, unsigned int q) 
{
	//q liczba pierwsza
	unsigned int c, d;
	int e, zakres = 0;
	c = n - 1;
	//Fermat(c);
	int tablica[200000], dokad = floor(sqrt(zakres));
	//e=spModulo(q, c, n);
	int i, j;
	for (i = 1; i <= zakres; i++) tablica[i] = 1;
	//algorytm - sito eratostenesa
	for (i = 2; i <= dokad; i++)
	{
		if (tablica[i] != 0)
		{
			j = i + i;
			while (j <= zakres)
			{
				tablica[j] = 0;
				j += i;
			}
		}
	}
}


int main()
{
	int x, y, m, tablic[100], ta[100];
	unsigned int a, n, q;
	cout << "zadanie 1: \n";
	cout << "liczba:  ";
	cin >> x;
	cout << "potega tej liczby: ";
	cin >> y;
	cout << "mod:  ";
	cin >> m;
	cout << x << "^" << y << " mod m = ";
	cout << spModulo(x, y, m) << endl;
	cout << "zadanie 2: \n";
	cout << "Fermat: \n";
	cin >> a;

	while (a % 2 == 0)
	{
		a /= 2;
		tabli[iter] = 2;
		iter++;
	}
	if (a > 1) Fermat(a - 1);
	for (int i = 0; i < iter; i++)
		cout << tabli[i] << endl;
	cout << "\n";
	cout << "zadanie 3: \n";
	cout << "liczba n\n";
	cin >> n;
	cout << "q: \n";
	cin >> q;

	for (int j = 0; j < iter; j++)
		tablic[j] = ta[j] = tabli[j];
	int k = 0;
	cout << "-------\n";
	for (int j = 0; j < iter; j++) {
		for (int i = 2; i <= tabli[j]; i++) 
		{
			while (tabli[j] % i == 0)
			{
				tabli[j] /= i;
				ta[k] = i;
				k++;
				cout << ta[k] << " ";
			}
		}
	}
	cout << "\n------\n";
	int koala=1;
	for (int j = 0; j < 30; j++) {
		cout << spModulo(q,(n - 1)/ta[j], n) << " " << ta[j] << endl;
		if (spModulo(q, (n - 1) / ta[j], n) == 1) koala++;
	}
	(koala == 1) ? cout << "\n liczba pierwsza \n" : cout << "\n test nie rozstrzyga\n";

	system("pause");
	return 0;
}