// 11.	 Fie dată o listă de numere întregi A.
// Să se introducă în lista B numerele de ordine ale elementelor maximale din lista A.
// -- Cu stiva.
// input: 7, 20, 12, 15, 16

// output: 2, 5, 4, 3, 1

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

struct nod
{
	int valoare;
	int index;
	struct nod *urmator;
};

void printList(struct nod *n)
{
	struct nod *t = n;
	while (t != NULL)
	{
		printf("%d ", t->valoare);
		t = t->urmator;
	}
}

void printListidx(struct nod *n)
{
	struct nod *t = n;
	while (t != NULL)
	{
		printf("%d ", t->index +1);
		t = t->urmator;
	}
}

void schimba(struct nod *a, struct nod *b)
{
	int t1 = a->valoare, t2 = a->index;
	a->valoare = b->valoare;
	a->index = b->index;
	b->valoare = t1;
	b->index = t2;

}

struct nod *lista_elemente_maximale(struct nod *nod)
{
	struct nod *t = nod;
	
	int schimbat, i;
    struct nod *ptr1;
    struct nod *lptr = NULL;

    if (nod == NULL)
        return NULL; 
    do
    {
        schimbat = 0;
        ptr1 = nod;
  
        while (ptr1->urmator != lptr)
        {
            if (ptr1->valoare < ptr1->urmator->valoare)
            { 
                schimba(ptr1, ptr1->urmator);
                schimbat = 1;
            }
            ptr1 = ptr1->urmator;
        }
		lptr =ptr1;
    }
    while (schimbat);

	return nod;
}

int main()
{

	struct nod *nod_curent, *capul_listei, *temp;
	int n;

	printf("Introduceti numarul de elemente n=");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		nod_curent = (struct nod *)malloc(sizeof(struct nod));
		printf("Introduceti elementul %d: ", i + 1);
		scanf("%d", &nod_curent->valoare);
		nod_curent->index = i;

		if (i == 0)
		{
			capul_listei = temp = nod_curent;
			continue;
		}

		temp->urmator = nod_curent;
		temp = nod_curent;
	}

	temp->urmator = NULL;
	printf("Lista A: ");
	printList(capul_listei);
	printf("\nLista B: ");
	capul_listei = lista_elemente_maximale(capul_listei);
	printListidx(capul_listei);


	return 0;
}