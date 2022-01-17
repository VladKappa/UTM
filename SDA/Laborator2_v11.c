// 10.	Să se scrie funcţia sortmid, care va sorta o serie din n şiruri în ordine alfabetică,
// bazându-se pe litera cu numărul de ordine  k  din fiecare şir, unde k  este un parametru,
// transmis funcţiei sortmid. De exemplu, dacă k = 3, atunci elementele şirului trebuie să
// fie sortate în ordine ascendentă conform valorii în cea de a treia literă a fiecărui şir.
// Dacă lungimea şirului este mai mică decât  k, atunci vom presupune,
// că în calitate de litera cu numărul de ordine  k  al acestuia, real inexistentă, serveşte blancul.

// 11.	Să se scrie funcţia care va efectua sortarea, analogică celei din problema 10,
// a şirurilor în ordine alfabetică inversă.
#include <stdio.h>
#include <conio.h>
#include <string.h>
void sortmid(char *arr, int k)
{
	char working_array[100];
	strcpy(working_array,arr);
	int length = strlen(working_array);
	// printf("k=%d length=%d",k, length);
	if (k>length-2)
		k=0;
	printf("WORKING ARRAY - %s\n", &working_array);
	char temp[2];
	// Vrode metoda bulelor
	for (k; k < length; k++)
	{
		for (int i=k+1; i < length; i++)
		{
			if (working_array[i] > working_array[i-1])
			{
				temp[0] = working_array[i];
				working_array[i] = working_array[i - 1];
				working_array[i - 1] = temp[0];
			}
		}
	}
	strcpy(arr,working_array);
}

int main()
{
	int k;
	printf("Introduceti variablia k: ");
	scanf("%d", &k);
	int n;
	printf("Cate siruri introducem? ");
	scanf("%d", &n);
	char siruri[100][100];
	for (int i = 0; i < n; i++)
	{
		printf("Sirul %d: ", i + 1);
		scanf("%s", &siruri[i]);
	}
	for(int i=0;i<n;i++)
		sortmid(siruri[i],k);

	for(int i=0;i<n;i++){
		printf("%s\n", siruri[i]);
	}
	return 0;
}