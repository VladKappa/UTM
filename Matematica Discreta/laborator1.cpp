#include <iostream>
#include <fstream>

using namespace std;

void citire_din_fisier(int **a, int m, int n)
{
	ifstream f("date.txt");
	int x;
	f >> x >> x;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			f >> a[i][j];
	f.close();
}
void afisare_matrice(int **matrice, int m, int n)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			cout << matrice[i][j] << " ";
		cout << endl;
	}
}

void write_to_file(int **matrice, int m, int n)
{
	ofstream f("adiacenta.txt");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			f << matrice[i][j] << " ";
		f << endl;
	}
	f.close();
}

int **incidenta_to_adiacenta(int **incidenta, int m, int n)
{
	int **matrice = new int *[n];
	for (int i = 0; i < n; i++)
		matrice[i] = new int[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrice[i][j] = 0;

	int origine;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			for (int x = 0; x < n; x++)
				if (incidenta[i][x] == -1)
					origine = x;
			if (incidenta[i][j] == 1)
				matrice[origine][j] = 1;
			if (incidenta[i][j] == 2)
				matrice[j][j] =1;
		}

	return matrice;
}

void print_lista_adiacenta(int **matrice_adiacenta, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << " - ";
		for (int j = 0; j < n; j++)
			if (matrice_adiacenta[i][j] == 1)
				cout << j + 1 << ", ";
		cout << "0" << endl;
	}
}

int main()
{
	int m, n;
	ifstream f("date.txt");
	f >> m;
	f >> n;
	f.close();

	// Initializam matricea dinamica
	int **matrice = new int *[m];
	for (int i = 0; i < m; i++)
		matrice[i] = new int[n];

	citire_din_fisier(matrice, m, n);
	int **adiacenta = incidenta_to_adiacenta(matrice, m, n);
	cout << "Matricea de incidenta a grafului este " << endl;
	afisare_matrice(matrice, m, n);
	cout << "Matricea de adiacenta a grafului este " << endl;
	afisare_matrice(adiacenta, n, n);
	cout << "Lista de adiacenta a grafului este " << endl;
	print_lista_adiacenta(adiacenta, n);
	cout << "\n\nScriu in fisier...";
	write_to_file(adiacenta, m, n);
	return 0;
}