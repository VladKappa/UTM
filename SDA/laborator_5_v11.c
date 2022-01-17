// 11.	Fie dat un tablou unidimensional din n caractere. Să se ordoneze elementele tabloului în
// ordine ascendentă, utilizând metoda bulelor şi metoda de sortare Shaker.
// Să se compare eficienţa metodelor în funcţie de numărul de comparaţii
// şi de numărul de permutări.
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void bubblesort(char *arr, int n)
{
	int comparatii = 0;
	int permutari = 0;
	char working_array[100];
	strncpy(working_array, arr, n);
	int length = strlen(working_array);
	char temp[2];
	// Vrode metoda bulelor
	for (int k = 0; k < length-1; k++)
	{
		for (int i = 0; i < length-k; i++)
		{
			comparatii++;
			if (working_array[i] < working_array[i - 1])
			{
				permutari++;
				temp[0] = working_array[i];
				working_array[i] = working_array[i - 1];
				working_array[i - 1] = temp[0];
			}
		}
	}
	printf("Array sortat: %s\n", working_array);
	printf("COMPARATII: %d\nPERMUTARI: %d\n", comparatii, permutari);
}

void shakersort(char *array, int n)
{
	char arr[100];
	strncpy(arr, array, n);
	int p, i;
	int permutari = 0, comparatii = 0;
	char temp[2];
	for (p = 1; p <= n / 2; p++)
	{
		for (i = p-1; i < n - p; i++)
		{
			comparatii++;
			if (arr[i] > arr[i + 1])
			{
				permutari++;
				temp[0] = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp[0];
			}
		}
		for (i = n - p - 1; i >= p; i--)
		{
			comparatii++;
			if (arr[i] < arr[i - 1])
			{
				permutari++;
				temp[0] = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = temp[0];
			}
		}
	}
	printf("\nArray sortat: %s\n", arr);
	printf("COMPARATII: %d\nPERMUTARI: %d\n", comparatii, permutari);
}

int main()
{
	int n;
	char array[100];
	printf("n= ");
	scanf("%d", &n);
	printf("Introduceti sirul de %d caractere:\n", n);
	scanf("%s", &array);
	printf("BUBBLESORT:\n");
	bubblesort(array, n);

	printf("Shake sort:\n");
	shakersort(array, n);

	return 0;
}